#pragma once

#include "GLV1.h"
#include "VertexV1.h"

#include <string>
#include <map>
#include <vector>

namespace o2
{
	namespace v3
	{
		class Shader
		{
			GLuint _shaderProgram;

			GLuint _vertexShader;

			GLuint _fragmentShader;

			std::map<std::string, GLuint> _attributeLocations;

		protected:
			GLuint loadShader(const std::string& shaderCode, GLenum shaderType);

			void compileShader(GLuint shader);

			void linkProgram();

			void useShader();

			void setupVertexAttribute(const std::string& attribute, GLint size, 
				GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer);

			void cleanupVertexAttribute(const std::string& attribute);

			void release();

		public:
			Shader()
				: _shaderProgram(0), _vertexShader(0), _fragmentShader(0)
			{ }

			inline virtual ~Shader() { release(); }

			inline GLuint getGlShaderProgram() { return _shaderProgram; }

			GLint getAttributeLocation(std::string attribute);

			void loadFromMemory(const std::string& vertexShaderCode, const std::string& fragmentShaderCode);

			void loadDefaultShader();

			void setupDraw(const std::vector<v1::Vertex>& vertices);

			void cleanupDraw();

		};
	}
}