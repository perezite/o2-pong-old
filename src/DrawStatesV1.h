#pragma once

#include "ShaderV3.h"

namespace o2
{
	namespace v1 
	{
		struct DrawStates
		{
			v3::Shader* shader;

			DrawStates(v3::Shader* shader_ = NULL)
				: shader(shader_)
			{ }

			DrawStates(v3::Shader& shader_)
				: DrawStates(&shader_)
			{ }
		};
	}
}