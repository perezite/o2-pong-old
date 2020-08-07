#include "RendererV1.h"
#include "ShaderV2.h"
#include "GLV1.h"

namespace o2
{
	namespace v1
	{
		void Renderer::ensureDefaultShader()
		{
			static bool loaded = false;
			if (!loaded)
			{
				_defaultShader.loadDefaultShader();
				loaded = true;
			}
		}

		void Renderer::draw(const std::vector<Vertex>& vertices, PrimitiveType primitiveType, v3::Shader* shader)
		{
			if (vertices.empty())
				return;

			ensureDefaultShader();

			if (shader == NULL)
				shader = &_defaultShader;

			shader->setupDraw(vertices);

			GL_CHECK(glDrawArrays((GLenum)primitiveType, 0, vertices.size()));

			shader->cleanupDraw();
		}
	}
}