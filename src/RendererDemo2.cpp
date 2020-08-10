#include "WindowDemo1.h"
#include "WindowV2.h"
#include "ShaderV1.h"
#include "ShaderV3.h"
#include "EventsV2.h"
#include "VertexArrayV1.h"

#include <iostream>
#include <cstdlib>

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
			 0.0f,  0.5f, 1, 0, 0, 1,
			-0.5f, -0.5f, 0, 1, 0, 1,
			 0.5f, -0.5f, 0, 0, 1, 0
		};

		glUseProgram(shader.getGlShaderProgram());

		GLuint positionAttributeLocation = shader.getAttributeLocation("position");
		GLuint colorAttributeLocation = shader.getAttributeLocation("color");
		glVertexAttribPointer(positionAttributeLocation, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(float), vertices + 0);
		glVertexAttribPointer(colorAttributeLocation, 4, GL_FLOAT, GL_FALSE, 6 * sizeof(float), vertices + 2);

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
	
	void draw3(v3::Shader& shader)
	{
		vector<v1::Vertex> vertices(3);
		vertices[0] = v1::Vertex(v1::Vector2f(   0, 0.5f), v1::Color(1, 0, 0, 1));
		vertices[1] = v1::Vertex(v1::Vector2f(-.5f, -.5f), v1::Color(0, 1, 0, 1));
		vertices[2] = v1::Vertex(v1::Vector2f( .5f, -.5f), v1::Color(0, 0, 1, 1));

		glUseProgram(shader.getGlShaderProgram());

		GLuint positionAttributeLocation = shader.getAttributeLocation("position");
		GLuint colorAttributeLocation = shader.getAttributeLocation("color");
		glVertexAttribPointer(positionAttributeLocation, 2, GL_FLOAT, GL_FALSE, 6 * sizeof(float), &(vertices[0].position));
		glVertexAttribPointer(colorAttributeLocation, 4, GL_FLOAT, GL_FALSE, 6 * sizeof(float), &(vertices[0].color));

		glEnableVertexAttribArray(positionAttributeLocation);
		glEnableVertexAttribArray(colorAttributeLocation);


		glDrawArrays(GL_TRIANGLES, 0, 3);

		glDisableVertexAttribArray(colorAttributeLocation);
		glDisableVertexAttribArray(positionAttributeLocation);
	}

	void demo3()
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

			draw3(shader);

			window.display();
		}
	}

	void draw4(v3::Shader& shader)
	{
		vector<v1::Vertex> vertices(3);
		vertices[0] = v1::Vertex(v1::Vector2f(0, 0.5f), v1::Color(1, 0, 0, 1));
		vertices[1] = v1::Vertex(v1::Vector2f(-.5f, -.5f), v1::Color(0, 1, 0, 1));
		vertices[2] = v1::Vertex(v1::Vector2f(.5f, -.5f), v1::Color(0, 0, 1, 1));

		shader.setupDraw(vertices);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		shader.cleanupDraw();
	}

	void demo4()
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

			draw4(shader);

			window.display();
		}
	}

	void demo5()
	{
		v2::Window window(v1::Vector2i(600, 400), "Pong");
		v3::Shader shader;
		v1::Renderer renderer;
		vector<v1::Vertex> vertices(3);

		shader.loadDefaultShader();

		vertices[0] = v1::Vertex(v1::Vector2f(0, 0.5f), v1::Color(1, 0, 0, 1));
		vertices[1] = v1::Vertex(v1::Vector2f(-.5f, -.5f), v1::Color(0, 1, 0, 1));
		vertices[2] = v1::Vertex(v1::Vector2f(.5f, -.5f), v1::Color(0, 0, 1, 1));

		while (window.isOpen())
		{
			v2::Events::update();
			if (v2::Events::hasCloseRequest(window))
				window.close();

			window.clear();

			renderer.draw(vertices, v1::PrimitiveType::Triangles, &shader);

			window.display();
		}
	}

	void demo6()
	{
		v2::Window window(v1::Vector2i(600, 400), "Pong");
		vector<v1::Vertex> vertices(3);
		v3::Shader shader;

		shader.loadDefaultShader();

		vertices[0] = v1::Vertex(v1::Vector2f(0, 0.5f), v1::Color(1, 0, 0, 1));
		vertices[1] = v1::Vertex(v1::Vector2f(-.5f, -.5f), v1::Color(0, 1, 0, 1));
		vertices[2] = v1::Vertex(v1::Vector2f(.5f, -.5f), v1::Color(0, 0, 1, 1));

		while (window.isOpen())
		{
			v2::Events::update();
			if (v2::Events::hasCloseRequest(window))
				window.close();

			window.clear();

			window.draw(vertices, v1::PrimitiveType::Triangles, &shader);

			window.display();
		}
	}

	void demo7()
	{
		v2::Window window(v1::Vector2i(600, 400), "Pong");
		vector<v1::Vertex> vertices(3);

		vertices[0] = v1::Vertex(v1::Vector2f(0, 0.5f), v1::Color(1, 0, 0, 1));
		vertices[1] = v1::Vertex(v1::Vector2f(-.5f, -.5f), v1::Color(0, 1, 0, 1));
		vertices[2] = v1::Vertex(v1::Vector2f(.5f, -.5f), v1::Color(0, 0, 1, 1));

		while (window.isOpen())
		{
			v2::Events::update();
			if (v2::Events::hasCloseRequest(window))
				window.close();

			window.clear();

			window.draw(vertices, v1::PrimitiveType::Triangles);

			window.display();
		}
	}

	void demo8()
	{
		v2::Window window(v1::Vector2i(600, 400), "Pong");
		v1::VertexArray triangle(3, v1::PrimitiveType::Triangles);
		triangle[0] = v1::Vertex(v1::Vector2f(   0, 0.5f), v1::Color(1, 0, 0, 1));
		triangle[1] = v1::Vertex(v1::Vector2f(-.5f, -.5f), v1::Color(0, 1, 0, 1));
		triangle[2] = v1::Vertex(v1::Vector2f( .5f, -.5f), v1::Color(0, 0, 1, 1));

		while (window.isOpen())
		{
			v2::Events::update();
			if (v2::Events::hasCloseRequest(window))
				window.close();

			window.clear();

			 triangle.draw(window);

			window.display();
		}
	}

    void run()
    {
		demo8();
		//demo7();
		//demo6();
		//demo5();
		//demo4();
		//demo3();
		//demo2();
		//demo1();
        //demo0();
    }
}