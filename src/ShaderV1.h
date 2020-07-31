#pragma once

#include "GLV1.h"

#include <string>

namespace o2
{
	namespace v1
	{
		class Shader
		{
			GLuint _shaderProgram;

		protected:
			GLuint loadShader(const std::string& shaderCode, GLenum shaderType);

		public:
			void loadFromMemory(const std::string& vertexShaderCode, const std::string& fragmentShaderCode);

			void loadDefaultShader();
		};
	}
}