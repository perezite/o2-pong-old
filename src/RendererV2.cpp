#include "RendererV2.h"
#include "WindowV2.h"
#include "GLV1.h"
#include "ErrorV1.h"
#include "ShaderV4.h"
#include "DrawStatesV1.h"

using namespace std;

namespace o2
{
	namespace v2
	{
		v4::Shader* Renderer::ensureDefaultShader()
		{
			static bool loaded = false;
			if (!loaded)
			{
				_defaultShader.loadDefaultShader();
				loaded = true;
			}

			return &_defaultShader;
		}

		void Renderer::draw(const std::vector<v1::Vertex>& vertices, v1::PrimitiveType primitiveType, const v1::DrawStates& drawStates) 
		{
			v4::Shader *shader = drawStates.shader;

			if (vertices.empty())
				return;

			if (shader == NULL)
				shader = ensureDefaultShader();

			shader->setupDraw(vertices, drawStates);

			GL_CHECK(glDrawArrays((GLenum)primitiveType, 0, vertices.size()));

			shader->cleanupDraw();
		}
	}
}