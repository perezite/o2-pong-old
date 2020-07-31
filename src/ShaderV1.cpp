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
				"	gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);	\n"
				"}												\n";

		}

		GLuint Shader::loadShader(const std::string & shaderCode, GLenum shaderType)
		{
			return 0;

				/*
						GLuint shader;
			GLint compiled;

			shader = glCreateShader(type);

			if (shader == 0)
			{
				v1::error() << "Error creating shader" << endl;
				return 0;
			}

			glShaderSource(shader, 1, &shaderSrc, NULL);

			glCompileShader(shader);
			glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);

			if (!compiled)
			{
				GLint infoLen = 0;
				glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);

				if (infoLen > 1)
				{
					char* infoLog = (char*)malloc(sizeof(char) * infoLen);
					glGetShaderInfoLog(shader, infoLen, NULL, infoLog);
					string infoLogString(infoLog);
					free(infoLog);
					v1::error() << "Error compiling shader: " << endl << infoLog << endl;
				}

				glDeleteShader(shader);
				return 0;
			}
			return shader;
				*/
		}

		void Shader::loadFromMemory(const std::string & vertexShaderCode, const std::string & fragmentShaderCode)
		{
			_shaderProgram = glCreateProgram();
			if (!_shaderProgram)
				error() << GL::getErrorDescription(glGetError()) << endl;

			GLuint vertexShader = loadShader(vertexShaderCode, GL_VERTEX_SHADER);
			GLuint fragmentShader = loadShader(fragmentShaderCode, GL_FRAGMENT_SHADER);

			GL_CHECK(glAttachShader(_shaderProgram, vertexShader));
			GL_CHECK(glAttachShader(_shaderProgram, fragmentShader));




			/*

		GLuint vertexShader;
		GLuint fragmentShader;
		GLuint shaderProgram;
		GLint linked;

		vertexShader = loadShader0(vertexShaderCode, GL_VERTEX_SHADER);
		fragmentShader = loadShader0(fragmentShaderCode, GL_FRAGMENT_SHADER);

		shaderProgram = glCreateProgram();

		if (shaderProgram == 0)
			v1::error() << "error creating shader program" << endl;

		glAttachShader(shaderProgram, vertexShader);
		glAttachShader(shaderProgram, fragmentShader);

		glBindAttribLocation(shaderProgram, 0, "vPosition");

		glLinkProgram(shaderProgram);

		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &linked);

		if (!linked)
		{
			GLint infoLen = 0;
			glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &infoLen);

			if (infoLen > 1)
			{
				char* infoLog = (char*)malloc(sizeof(char) * infoLen);
				glGetProgramInfoLog(shaderProgram, infoLen, NULL, infoLog);
				glDeleteProgram(shaderProgram);
				string infoLogString(infoLog);
				free(infoLog);
				v1::error() << "Error linking program: " << endl << infoLogString << endl;
			}
		}

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

		return shaderProgram;
			*/

		}

		void Shader::loadDefaultShader()
		{
			loadFromMemory(DefaultVertexShaderCode, DefaultFragmentShaderCode);
		}
	}
}