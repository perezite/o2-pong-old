#pragma once

#include "ShaderV4.h"
#include "TransformV1.h"

namespace o2
{
	namespace v1 
	{
		struct DrawStates
		{
			v4::Shader* shader;

			Transform transform;

			DrawStates(v4::Shader* shader_ = NULL, const Transform& transform_ = Transform())
				: shader(shader_), transform(transform_)
			{ }

			DrawStates(v4::Shader& shader_)
				: DrawStates(&shader_)
			{ }

			DrawStates(const Transform& transform_)
				: DrawStates(NULL, transform_)
			{ }
		};
	}
}