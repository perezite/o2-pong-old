#include "CameraV1.h"
#include "Vector2V1.h"

#include <math.h>
#include <vector>

using namespace std;

namespace o2
{
    namespace v1
    {
        void Camera::updateTransform()
        {
            vector<float>& m = _transform.getMatrix();
            float cf = cosf(-_rotation);
            float sf = sinf(-_rotation);

            v1::Vector2f inverseScale(2 / _size.x, 2 / _size.y);

            float a = cf * inverseScale.x;
            float b = -sf * inverseScale.x;
            float c = sf * inverseScale.y;
            float d = cf * inverseScale.y;
            float tx = -_position.x;
            float ty = -_position.y;

            m[0] = a;	m[3] = b;	m[6] = a * tx + b * ty;
            m[1] = c;	m[4] = d;	m[7] = c * tx + d * ty;
            m[2] = 0;	m[5] = 0;	m[8] = 1;
        }

        void Camera::setSize(const Vector2f& size)
        {
            _size = size;
            _mustUpdateTransform = true;
        }

        void Camera::setRotation(float degrees)
        {
            _rotation = degrees;
            _mustUpdateTransform = true;
        }

        Transform & Camera::getTransform()
        {
            if (_mustUpdateTransform)
            {
                updateTransform();
                _mustUpdateTransform = false;
            }
            
            return _transform;
        }
    }
}