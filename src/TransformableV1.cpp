#include "TransformableV1.h"

namespace o2
{
    namespace v1
    {
        void Transformable::setPosition(const v1::Vector2f& position)
        {
            _position = position;
            _mustUpdateTransform = true;
        }

        void Transformable::setRotation(float degrees)
        {
            _rotation = degrees;
            _mustUpdateTransform = true;
        }

        void Transformable::setScale(const v1::Vector2f& scaling)
        {
            _scale = scaling;
            _mustUpdateTransform = true;
        }

        const Transform& Transformable::getTransform()
        {
            if (_mustUpdateTransform)
            {
                _transform = Transform(_position, _rotation, _scale);
                _mustUpdateTransform = false;
            }

            return _transform;
        }
    }
}