#include "ShaderV4.h"
#include "DrawStatesV1.h"
#include "WindowV2.h"
#include "ErrorV1.h"
#include "SDLV1.h"
#include "STLV1.h"

using namespace std;

namespace o2
{
	namespace v4
	{
		namespace
		{
			const char DefaultVertexShaderCode[] =
				"attribute vec2 position;										\n"
				"attribute vec4 color;											\n"
				"varying vec4 v_color;											\n"
				"uniform mat3 transform;										\n"
				"vec3 transformedPosition;										\n"
				"void main()													\n"
				"{																\n"
				"	v_color = color;											\n"
				"	transformedPosition = transform * vec3(position.xy, 1);		\n"
				"	gl_Position = vec4(transformedPosition.xy, 0, 1);			\n"
				"}																\n";

			// https://github.com/mattdesl/lwjgl-basics/wiki/GLSL-Versions
			const char DefaultFragmentShaderCode[] =
				"#version 100													\n"
				"precision mediump float;										\n"
				"varying vec4 v_color;											\n"
				"void main()													\n"
				"{																\n"
				"	gl_FragColor = v_color;										\n"
				"}																\n";
		}

		void Shader::compile(GLuint shader)
		{
			GLint compiled;

			GL_CHECK(glCompileShader(shader));
			GL_CHECK(glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled));
			if (!compiled)
			{
				GLint infoLen = 0;
				string infoLog = "No information";

				GL_CHECK(glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen));
				if (infoLen > 1)
				{
					char* rawInfoLog = (char*)malloc(sizeof(char) * infoLen);
					GL_CHECK(glGetShaderInfoLog(shader, infoLen, NULL, rawInfoLog));
					infoLog = rawInfoLog;
					free(rawInfoLog);
				}

				release();
				v1::error() << "Error compiling shader: " << endl << infoLog << endl;
			}
		}

		void Shader::linkProgram()
		{
			GLint linked;

			GL_CHECK(glLinkProgram(_shaderProgram));
			GL_CHECK(glGetProgramiv(_shaderProgram, GL_LINK_STATUS, &linked));
			if (!linked)
			{
				GLint infoLen = 0;
				string infoLog = "No information";

				GL_CHECK(glGetProgramiv(_shaderProgram, GL_INFO_LOG_LENGTH, &infoLen));
				if (infoLen > 1)
				{
					char* rawInfoLog = (char*)malloc(sizeof(char) * infoLen);
					GL_CHECK(glGetProgramInfoLog(_shaderProgram, infoLen, NULL, rawInfoLog));
					infoLog = rawInfoLog;
					free(rawInfoLog);
				}

				release();
				v1::error() << "Error linking shader program: " << endl << infoLog << endl;
			}
		}

		GLint Shader::getAttributeLocation(std::string attribute)
		{
			if (_attributeLocations.find(attribute) == _attributeLocations.end())
			{
				GLint location;
				GL_CHECK(location = glGetAttribLocation(_shaderProgram, attribute.c_str()));
				if (location < 0)
					v1::error() << "Requested shader attribute '" << attribute << "' does not exist";
				_attributeLocations[attribute] = location;
			}

			return _attributeLocations[attribute];
		}

		GLint Shader::getUniformLocation(std::string uniform)
		{
			if (_attributeLocations.find(uniform) == _attributeLocations.end())
			{
				GLint location;
				GL_CHECK(location = glGetUniformLocation(_shaderProgram, uniform.c_str()));
				if (location < 0)
					v1::error() << "Requested shader uniform '" << uniform << "' does not exist";
				_uniformLocations[uniform] = location;
			}

			return _uniformLocations[uniform];
		}

		void Shader::release()
		{
			if (_fragmentShader)
				GL_CHECK(glDeleteShader(_fragmentShader));
			if (_vertexShader)
				GL_CHECK(glDeleteShader(_vertexShader));
			if (_shaderProgram)
				GL_CHECK(glDeleteProgram(_shaderProgram));
		}

		GLuint Shader::initShaderCode(const std::string& shaderCode, GLenum shaderType)
		{
			GLuint shader;
			GL_CHECK(shader = glCreateShader(shaderType));

			const char* rawShaderSource = shaderCode.c_str();
			GL_CHECK(glShaderSource(shader, 1, &rawShaderSource, NULL));

			compile(shader);

			return shader;
		}

		void Shader::loadFromMemory(const std::string & vertexShaderCode, const std::string & fragmentShaderCode)
		{
			release();

			GL_CHECK(_shaderProgram = glCreateProgram());

			_vertexShader = initShaderCode(vertexShaderCode, GL_VERTEX_SHADER);
			_fragmentShader = initShaderCode(fragmentShaderCode, GL_FRAGMENT_SHADER);

			GL_CHECK(glAttachShader(_shaderProgram, _vertexShader));
			GL_CHECK(glAttachShader(_shaderProgram, _fragmentShader));

			linkProgram();
		}

		void Shader::loadDefault()
		{
			loadFromMemory(DefaultVertexShaderCode, DefaultFragmentShaderCode);
		}

		void Shader::setUniformMatrix3(std::string uniform, const float* matrix3)
		{
			GLuint location = getUniformLocation(uniform);
			GL_CHECK(glUniformMatrix3fv(location, 1, GL_FALSE, matrix3));
		}

		void Shader::enableVertexAttribute(const string& attribute, GLint size,
			GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer)
		{
			GLuint location = getAttributeLocation(attribute);
			GL_CHECK(glVertexAttribPointer(location, size, type, normalized, stride, pointer));
			GL_CHECK(glEnableVertexAttribArray(location));
		}

		void Shader::disableVertexAttribute(const std::string& attribute)
		{
			GLuint attributeLocation = getAttributeLocation(attribute);
			GL_CHECK(glDisableVertexAttribArray(attributeLocation));
		}

		void Shader::use()
		{
			GL_CHECK(glUseProgram(getGlShaderProgram()));
		}
	}
}