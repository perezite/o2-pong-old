#pragma once

#include "TransformV1.h"
#include "Vector2V1.h"

namespace o2
{
    namespace v1
    {
        class Transformable
        {
            Transform _transform;

            v1::Vector2f _position;

            v1::Vector2f _scale;

            float _rotation;

            bool _mustUpdateTransform;

        public:
            Transformable()
                : _scale(1)
            { }

            void setPosition(const v1::Vector2f& position);

            inline void setPosition(float x, float y) { setPosition(v1::Vector2f(x, y)); }

            void setRotation(float degrees);

            void setScale(const v1::Vector2f& scaling);

            inline void setScale(float x, float y) { setScale(v1::Vector2f(x, y)); }

            const Transform& getTransform();
        };
    }
}