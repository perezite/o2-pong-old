#include "RendererV1.h"

namespace o2
{
	namespace v1
	{
		void Renderer::draw(const std::vector<Vertex>& vertices, PrimitiveType primitiveType)
		{
			if (vertices.empty())
				return;

			// Shader& shader = Shader::getDefaultShader();
			// setup(vertices, shader);
			// drawVertices(vertices, primitiveType);
			// cleanup(shader);
		}

		/*
		void Renderer::setup(Shader& shader, const vector<Vertex>& vertices)
		{
			GL_CHECK(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
			GL_CHECK(glEnable(GL_BLEND));

			shader.use();
			setupShaderAttributes(shader, vertices);
		}

		void Renderer::setupShaderAttributes(Shader& shader, const vector<Vertex>& vertices)
		{
			GLvoid* position = &(vertices[0].position);
			GLvoid* color = &(vertices[0].color);
			setShaderAttribute(shader.getAttributeLocation("position"), 2, GL_FLOAT, GL_FALSE, position);
			setShaderAttribute(shader.getAttributeLocation("color"), 4, GL_FLOAT, GL_FALSE, position);
		}

		inline void Renderer::setShaderAttribute(GLuint location, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLvoid* value) 
		{
			GL_CHECK(glVertexAttribPointer(location, size, type, normalized, stride, value));
			GL_CHECK(glEnableVertexAttribArray(location));
		}
		*/

		void Renderer::drawVertices(const std::vector<Vertex>& vertices, PrimitiveType primitiveType)
		{
			// GL_CHECK(glDrawArrays((GLenum)primitiveType, 0, vertices.size()));
		}

		/*
		void Renderer::cleanup(Shader& shader) 
		{
			GL_CHECK(glDisableVertexAttribArray(shader.getAttributeLocation("color")));
			GL_CHECK(glDisableVertexAttribArray(shader.getAttributeLocation("position")));
		}
		*/
	}
}