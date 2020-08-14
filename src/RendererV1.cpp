#include "RendererV1.h"
#include "ShaderV3.h"
#include "WindowV2.h"
#include "GLV1.h"
#include "ErrorV1.h"

using namespace std;

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

		v3::Shader* Renderer::getDefaultShader()
		{
			ensureDefaultShader();

			return &_defaultShader;
		}

		void Renderer::draw(const std::vector<Vertex>& vertices, PrimitiveType primitiveType, const DrawStates& drawStates)
		{
			v3::Shader *shader = drawStates.shader;

			if (vertices.empty())
				return;

			if (shader == NULL)
				shader = getDefaultShader();

			shader->setupDraw(vertices);

			GL_CHECK(glDrawArrays((GLenum)primitiveType, 0, vertices.size()));

			shader->cleanupDraw();
		}
	}
}