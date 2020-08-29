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

        void Renderer::draw(const vector<v1::Vertex>& vertices, v1::PrimitiveType primitiveType, v1::DrawStates drawStates)
        {
            if (vertices.empty())
                return;

            setup(vertices, drawStates);

            GL_CHECK(glDrawArrays((GLenum)primitiveType, 0, vertices.size()));

            drawStates.shader->cleanupDraw();
        }

        void Renderer::setup(const vector<v1::Vertex>& vertices, v1::DrawStates& drawStates)
        {
            if (drawStates.shader == NULL)
                drawStates.shader = ensureDefaultShader();

            if (drawStates.camera)
                drawStates.transform *= drawStates.camera->getTransform();

            drawStates.shader->setupDraw(vertices, drawStates);
        }
    }
}