#include "TransformV1.h"
#include "MathV1.h"

#include <vector>
#include <math.h>

using namespace std;

namespace o2
{
    namespace v1
    {
        Transform::Transform(	
            float a00, float a01, float a02,
            float a10, float a11, float a12,
            float a20, float a21, float a22)
            : _matrix(9)
        {
            _matrix[0] = a00; _matrix[3] = a01; _matrix[6] = a02;
            _matrix[1] = a10; _matrix[4] = a11; _matrix[7] = a12;
            _matrix[2] = a20; _matrix[5] = a21; _matrix[8] = a22;
        }

        Transform::Transform(const Vector2f& position, float degrees, const Vector2f& scale)
            : _matrix(9)
        {
            float rad = degrees * math::ToRadian;
            float c = cosf(rad);
            float s = sinf(rad);

            _matrix[0] = c * scale.x;	_matrix[3] = -s * scale.y;	_matrix[6] = position.x;
            _matrix[1] = s * scale.x;	_matrix[4] =  c * scale.y;	_matrix[7] = position.y;
            _matrix[2] = 0;			    _matrix[5] =  0;			_matrix[8] = 1;
        }

        const Transform& Transform::apply(const Transform & transform)
        {
            const vector<float> a = _matrix;
            const vector<float>& b = transform.getMatrix();

            _matrix[0] = a[0] * b[0] + a[3] * b[1] + a[6] * b[2];
            _matrix[1] = a[1] * b[0] + a[4] * b[1] + a[7] * b[2];
            _matrix[2] = a[2] * b[0] + a[5] * b[1] + a[8] * b[2];
            _matrix[3] = a[0] * b[3] + a[3] * b[4] + a[6] * b[5];
            _matrix[4] = a[1] * b[3] + a[4] * b[4] + a[7] * b[5];
            _matrix[5] = a[2] * b[3] + a[5] * b[4] + a[8] * b[5];
            _matrix[6] = a[0] * b[6] + a[3] * b[7] + a[6] * b[8];
            _matrix[7] = a[1] * b[6] + a[4] * b[7] + a[7] * b[8];
            _matrix[8] = a[2] * b[6] + a[5] * b[7] + a[8] * b[8];

            return *this;
        }

        const Transform& Transform::translate(const Vector2f& offset)
        {
            Transform translation(
                1, 0, offset.x,
                0, 1, offset.y,
                0, 0, 1);

            return apply(translation);
        }

        const Transform& Transform::rotate(float degrees)
        {
            float rad = degrees * math::ToRadian;
            float c = cosf(rad);
            float s = sinf(rad);

            Transform rotation(
                c, -s, 0,
                s,	c, 0,
                0,	0, 1);

            return apply(rotation);
        }

        const Transform & Transform::scale(const Vector2f& scaling)
        {
            Transform scaleTransform(
                scaling.x,  0,          0,
                0,          scaling.y,  0,
                0,          0,          1);

            return apply(scaleTransform);
        }

        Transform operator*(Transform& left, const Transform& right)
        {
            return left.apply(right);
        }

        Transform & operator*=(Transform& left, const Transform& right)
        {
            left.apply(right);
            return left;
        }
    }
}