#pragma once

#include "Vector2V1.h"
#include "TransformV1.h"

namespace o2
{
    namespace v1
    {
        class Camera
        {
            Vector2f _position;

            float _rotation;

            Vector2f _size;

            Transform _transform;

            bool _mustUpdateTransform;

        protected:
            void updateTransform();

        public:
            Camera()
                : _rotation(0), _mustUpdateTransform(true)
            { }

            void setSize(const Vector2f& size);

            inline void setSize(float x, float y) { setSize(Vector2f(x, y)); }

            Transform& getTransform();
        };
    }
}