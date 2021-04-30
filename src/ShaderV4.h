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
			GLuint loadShader(const std::string& shaderCode, GLenum shaderType);

			void compileShader(GLuint shader);

			void linkProgram();

			void useShader();

			GLint getAttributeLocation(std::string attribute);

			GLint getUniformLocation(std::string uniform);

			void setupVertexAttribute(const std::string& attribute, GLint size, 
				GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer);

			void cleanupVertexAttribute(const std::string& attribute);

			void setUnformMatrix3(std::string uniformName, const float* matrix3);

			void release();

		public:
			Shader() : 
				_shaderProgram(0), _vertexShader(0), _fragmentShader(0)
			{ }

			inline virtual ~Shader() { release(); }

			inline GLuint getGlShaderProgram() { return _shaderProgram; }

			void loadFromMemory(const std::string& vertexShaderCode, const std::string& fragmentShaderCode);

			void loadDefaultShader();

			void setupDraw(const std::vector<v1::Vertex>& vertices, const v1::DrawStates& states);

			void cleanupDraw();

		};
	}
}