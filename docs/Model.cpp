#include <iostream>
#include <vector>

using namespace std;

class VertexArray 
{
	vector<float> _vertices;
	
public:
	VertexArray(size_t numVertices) : _vertices(numVertices)
	{ }
	
	float getVertex(size_t index) { return _vertices[index]; }
};

class VertexBuffer
{
	vector<float> _vertices;
	
public:
	VertexBuffer() : _vertices(1024)
	{ }
	
	float getVertex(size_t index) { return _vertices[index]; }
};

class VertexBufferView 
{
	VertexBuffer& _vertexBuffer;
	
	size_t _start, _end;
	
	public:
	VertexBufferView(VertexBuffer& vertexBuffer, size_t numVertices) 
		: _vertexBuffer(vertexBuffer), _start(0), _end(numVertices)
	{ }	

	float getVertex(size_t index) { return _vertexBuffer.getVertex(_start + index); }
};

class Drawable 
{
public:
	virtual void draw() = 0;
};

template <class TStorage>
class Model : public Drawable
{	
public:
	virtual void draw() = 0;
};

template <class TStorage>
class Block : public Model<TStorage> 
{
	TStorage _storage;
		
public:
	virtual void draw() 
	{
		
	}
};

int main() 
{
	Block<VertexArray> block1;
	Block<VertexBufferView> block2;
}
