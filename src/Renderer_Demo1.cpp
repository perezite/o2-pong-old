#include "Window_Demo1.h"
#include "WindowV1.h"
#include "ShaderV1.h"
#include <iostream>
#include <stdlib.h>

using namespace std;
using namespace o2;

namespace rendererDemo1
{
	GLuint loadShader0(const char *shaderSrc, GLenum type)
	{
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
	}

	GLuint init0()
	{
		const char vertexShaderCode[] =
			"attribute vec4 position;			\n"
			"void main()						\n"
			"{									\n"
			"	gl_Position = position;			\n"
			"}									\n";

		const char fragmentShaderCode[] =
			"precision mediump float;						\n"
			"void main()									\n"
			"{												\n"
			"	gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);	\n"
			"}												\n";

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
	}

	void draw0(GLuint shaderProgram)
	{
		GLfloat vertices[] = 
		{ 
			 0.0f,  0.5f, 0.0f,
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f 
		};

		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shaderProgram);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vertices);
		glEnableVertexAttribArray(0);

		glDrawArrays(GL_TRIANGLES, 0, 3);
	}

	// https://www.khronos.org/assets/uploads/books/openglr_es_20_programming_guide_sample.pdf
    void demo0()
    {
        v1::Window window(v1::Vector2i(600, 400), "Pong");
		GLuint shaderProgram = init0();

        while (window.isOpen())
        {
            window.update();

			draw0(shaderProgram);

            window.display();
        }
    }
    
	void draw1(v1::Shader& shader)
	{
		GLfloat vertices[] =
		{
			 0.0f,  0.5f, 0.0f,
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f
		};

		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shader.getGlShaderProgram());

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vertices);
		glEnableVertexAttribArray(0);

		glDrawArrays(GL_TRIANGLES, 0, 3);
	}

	void demo1() {
		v1::Window window(v1::Vector2i(600, 400), "Pong");
		v1::Shader shader;
		
		shader.loadDefaultShader();

		while (window.isOpen())
		{
			window.update();

			draw1(shader);

			window.display();
		}
	}

	void drawQuad2(const v1::Vector2f& position, const v1::Vector2f& size, v1::Shader& shader)
	{
		GLfloat vertices[] =
		{
			position.x - size.x, position.y - size.y, 0,
			position.x + size.x, position.y - size.y, 0,
			position.x + size.x, position.y + size.y, 0,
			position.x - size.x, position.y + size.y, 0,
		};

		glUseProgram(shader.getGlShaderProgram());

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vertices);
		glEnableVertexAttribArray(0);

		glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
	}

	void demo2()
	{
		v1::Window window(v1::Vector2i(600, 400), "Pong");
		v1::Shader shader;

		shader.loadDefaultShader();

		while (window.isOpen())
		{
			window.update();

			glClear(GL_COLOR_BUFFER_BIT);
			drawQuad2(v1::Vector2f(-.9f,  .3f), v1::Vector2f(.05f, .4f), shader);
			drawQuad2(v1::Vector2f( .9f, -.4f), v1::Vector2f(.05f, .4f), shader);


			window.display();
		}
	}

    void run()
    {
		// maybe implement something like this: https://www.youtube.com/watch?v=YJX_KyXR0Y0

		demo2();
		//demo1();
        //demo0();
    }
}