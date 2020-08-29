#pragma once

#include "ShaderV4.h"
#include "TransformV1.h"
#include "CameraV1.h"

namespace o2
{
    namespace v1 
    {
        struct DrawStates
        {
            v4::Shader* shader;

            Transform transform;

            Camera* camera;

            DrawStates(v4::Shader* shader_ = NULL, const Transform& transform_ = Transform(), Camera* camera_ = NULL)
                : shader(shader_), transform(transform_), camera(camera_)
            { }

            DrawStates(v4::Shader& shader_)
                : DrawStates(&shader_, Transform(), NULL)
            { }

            DrawStates(const Transform& transform_)
                : DrawStates(NULL, transform_, NULL)
            { }

            DrawStates(v1::Camera& camera_)
                : DrawStates(NULL, Transform(), &camera_)
            { }
        };
    }
}