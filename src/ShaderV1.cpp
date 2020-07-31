#include "ShaderV1.h"

using namespace std;

namespace o2
{
	namespace v1
	{
		namespace
		{
			const char DefaultVertexShaderCode[] =
				"attribute vec4 position;			\n"
				"void main()						\n"
				"{									\n"
				"	gl_Position = position;			\n"
				"}									\n";

			const char DefaultFragmentShaderCode[] =
				"precision mediump float;						\n"
				"void main()									\n"
				"{												\n"
				"	gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);	\n"
				"}												\n";
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
				error() << "Error compiling shader: " << endl << infoLog << endl;
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
				error() << "Error linking shader program: " << endl << infoLog << endl;
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
				error() << GL::getErrorDescription(glGetError()) << endl;

			const char* rawShaderSource = shaderCode.c_str();
			GL_CHECK(glShaderSource(shader, 1, &rawShaderSource, NULL));

			compileShader(shader);

			return shader;
		}

		void Shader::loadFromMemory(const std::string & vertexShaderCode, const std::string & fragmentShaderCode)
		{
			release();

			_shaderProgram = glCreateProgram();
			if (!_shaderProgram)
				error() << GL::getErrorDescription(glGetError()) << endl;

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