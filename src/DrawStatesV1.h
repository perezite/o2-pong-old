#pragma once

#include "ShaderV4.h"

namespace o2
{
	namespace v1 
	{
		struct DrawStates
		{
			v4::Shader* shader;

			DrawStates(v4::Shader* shader_ = NULL)
				: shader(shader_)
			{ }

			DrawStates(v4::Shader& shader_)
				: DrawStates(&shader_)
			{ }
		};
	}
}