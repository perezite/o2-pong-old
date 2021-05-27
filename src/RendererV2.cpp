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
                _defaultShader.loadDefault();
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

            cleanupShader(drawStates.shader);
        }

        void Renderer::setup(const vector<v1::Vertex>& vertices, v1::DrawStates& drawStates)
        {
            if (drawStates.shader == NULL)
                drawStates.shader = ensureDefaultShader();

            if (drawStates.camera)
                drawStates.transform *= drawStates.camera->getTransform();

            setupShader(vertices, drawStates.shader, drawStates);
        }

        void Renderer::setupShader(const std::vector<v1::Vertex>& vertices, v4::Shader* shader, v1::DrawStates& drawStates)
        {
            shader->use();
            shader->enableVertexAttribute("position", 2, GL_FLOAT, GL_FALSE, sizeof(v1::Vertex), &(vertices[0].position));
            shader->enableVertexAttribute("color", 4, GL_FLOAT, GL_FALSE, sizeof(v1::Vertex), &(vertices[0].color));
            shader->setUniformMatrix3("transform", &(drawStates.transform.getMatrix()[0]));
        }

        void Renderer::cleanupShader(v4::Shader* shader)
        {
            shader->disableVertexAttribute("color");
            shader->disableVertexAttribute("position");
        }
    }
}