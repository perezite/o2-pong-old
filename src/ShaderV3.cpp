#include "ShaderV3.h"

using namespace std;

namespace o2
{
	namespace v3
	{
		namespace
		{
			const char DefaultVertexShaderCode[] =
				"attribute vec2 position;							\n"
				"attribute vec4 color;								\n"
				"varying vec4 v_color;								\n"
				"void main()										\n"
				"{													\n"
				"	v_color = color;								\n"
				"	gl_Position = vec4(position.xy, 0, 1);			\n"
				"}													\n";

			const char DefaultFragmentShaderCode[] =
				"precision mediump float;							\n"
				"varying vec4 v_color;								\n"
				"void main()										\n"
				"{													\n"
				"	gl_FragColor = v_color;							\n"
				"}													\n";
		}

		void Shader::compileShader(GLuint shader)
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

		void Shader::release()
		{
			if (_fragmentShader)
				GL_CHECK(glDeleteShader(_fragmentShader));
			if (_vertexShader)
				GL_CHECK(glDeleteShader(_vertexShader));
			if (_shaderProgram)
				GL_CHECK(glDeleteProgram(_shaderProgram));
		}


		GLuint Shader::loadShader(const std::string & shaderCode, GLenum shaderType)
		{
			GLuint shader;

			shader = glCreateShader(shaderType);
			if (!shader)
				v1::error() << v1::GL::getErrorDescription(glGetError()) << endl;

			const char* rawShaderSource = shaderCode.c_str();
			GL_CHECK(glShaderSource(shader, 1, &rawShaderSource, NULL));

			compileShader(shader);

			return shader;
		}

		GLint Shader::getAttributeLocation(std::string attribute)
		{
			if (_attributeLocations.find(attribute) == _attributeLocations.end()) 
			{
				GLint location = glGetAttribLocation(_shaderProgram, attribute.c_str());
				if (location < 0)
					v1::error() << "Requested shader attribute '" << attribute << "' does not exist";
				_attributeLocations[attribute] = location;
			}

			return _attributeLocations[attribute];
		}

		void Shader::loadFromMemory(const std::string & vertexShaderCode, const std::string & fragmentShaderCode)
		{
			release();

			_shaderProgram = glCreateProgram();
			if (!_shaderProgram)
				 v1::error() << v1::GL::getErrorDescription(glGetError()) << endl;

			_vertexShader = loadShader(vertexShaderCode, GL_VERTEX_SHADER);
			_fragmentShader = loadShader(fragmentShaderCode, GL_FRAGMENT_SHADER);

			GL_CHECK(glAttachShader(_shaderProgram, _vertexShader));
			GL_CHECK(glAttachShader(_shaderProgram, _fragmentShader));

			linkProgram();
		}

		void Shader::loadDefaultShader()
		{
			loadFromMemory(DefaultVertexShaderCode, DefaultFragmentShaderCode);
		}
	}
}