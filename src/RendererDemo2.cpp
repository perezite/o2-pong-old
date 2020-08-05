#include "WindowDemo1.h"
#include "WindowV2.h"
#include "ShaderV1.h"
#include "ShaderV3.h"
#include "EventsV2.h"
#include <iostream>
#include <stdlib.h>

using namespace std;
using namespace o2;

namespace rendererDemo2
{	
	void demo0()
	{
		v2::Window window(v1::Vector2i(600, 400), "Pong");

		while (window.isOpen())
		{
			v2::Events::update();
			if (v2::Events::hasCloseRequest(window))
				window.close();

			window.display();
		}
	}

	void demo1()
	{
		v2::Window window(v1::Vector2i(600, 400), "Pong");
		v1::Renderer renderer;
		vector<v1::Vertex> vertices(3);

		vertices[0] = v1::Vertex(v1::Vector2f( -.5f, -.5f));
		vertices[1] = v1::Vertex(v1::Vector2f(  .5f, -.5f));
		vertices[2] = v1::Vertex(v1::Vector2f(    0,  .5f));

		while (window.isOpen())
		{
			v2::Events::update();
			if (v2::Events::hasCloseRequest(window))
				window.close();

			window.clear();

			renderer.draw(vertices, v1::PrimitiveType::Triangles);

			window.display();
		}
	}

	void draw2(v3::Shader& shader)
	{
		GLfloat vertices[] =
		{
			 0.0f,  0.5f, 0.0f, 1, 0, 0, 1,
			-0.5f, -0.5f, 0.0f, 0, 1, 0, 1,
			 0.5f, -0.5f, 0.0f, 0, 0, 1, 0
		};

		glUseProgram(shader.getGlShaderProgram());

		GLuint positionAttributeLocation = shader.getAttributeLocation("position");
		GLuint colorAttributeLocation = shader.getAttributeLocation("color");
		glVertexAttribPointer(positionAttributeLocation, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), vertices + 0);
		glVertexAttribPointer(colorAttributeLocation, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(float), vertices + 3);

		glEnableVertexAttribArray(positionAttributeLocation);
		glEnableVertexAttribArray(colorAttributeLocation);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glDisableVertexAttribArray(colorAttributeLocation);
		glDisableVertexAttribArray(positionAttributeLocation);
	}

	void demo2()
	{
		v2::Window window(v1::Vector2i(600, 400), "Pong");
		v3::Shader shader;
		shader.loadDefaultShader();

		while (window.isOpen())
		{
			v2::Events::update();
			if (v2::Events::hasCloseRequest(window))
				window.close();

			window.clear();

			draw2(shader);

			window.display();
		}
	}

    void run()
    {
		demo2();
		//demo1();
        //demo0();
    }
}