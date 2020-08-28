#pragma once

#include "Vector2V1.h"
#include "TransformV1.h"

namespace o2
{
    namespace v1
    {
        class Camera
        {
            Vector2f _size;

            Transform _transform;

        public:
            inline void setSize(const Vector2f& size) { _size = size; }

            inline void setSize(float x, float y) { setSize(Vector2f(x, y)); }

            Transform& getTransform();
        };
    }
}