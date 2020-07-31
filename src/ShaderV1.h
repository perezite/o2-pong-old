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

			GLuint _vertexShader;

			GLuint _fragmentShader;

		protected:
			GLuint loadShader(const std::string& shaderCode, GLenum shaderType);

			void compileShader(GLuint shader);

			void linkProgram();

			void release();

		public:
			Shader()
				: _shaderProgram(0), _vertexShader(0), _fragmentShader(0)
			{ }

			inline virtual ~Shader() { release(); }

			inline GLuint getGlShaderProgram() { return _shaderProgram; }

			void loadFromMemory(const std::string& vertexShaderCode, const std::string& fragmentShaderCode);

			void loadDefaultShader();

		};
	}
}