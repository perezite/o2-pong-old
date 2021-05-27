#pragma once

#include "GLV1.h"
#include "VertexV1.h"
#include "GlObject.h"

#include <string>
#include <map>
#include <vector>

namespace o2
{
	namespace v1
	{ 
		struct DrawStates;
	}

	namespace v4
	{
		class Shader : public v1::GlObject
		{
			GLuint _shaderProgram;

			GLuint _vertexShader;

			GLuint _fragmentShader;

			std::map<std::string, GLuint> _attributeLocations;

			std::map<std::string, GLuint> _uniformLocations;

		protected:
			GLuint initShaderCode(const std::string& shaderCode, GLenum shaderType);

			void compile(GLuint shader);

			void linkProgram();

			GLint getAttributeLocation(std::string attribute);

			GLint getUniformLocation(std::string uniform);

			void release();

		public:
			Shader() : 
				_shaderProgram(0), _vertexShader(0), _fragmentShader(0)
			{ }

			inline virtual ~Shader() { release(); }

			inline GLuint getGlShaderProgram() { return _shaderProgram; }

			void loadFromMemory(const std::string& vertexShaderCode, const std::string& fragmentShaderCode);

			void loadDefault();

			void setUniformMatrix3(std::string uniformName, const float* matrix3);

			void enableVertexAttribute(const std::string& attribute, GLint size, 
				GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer);

			void disableVertexAttribute(const std::string& attribute);
			
			void use();
		};
	}
}