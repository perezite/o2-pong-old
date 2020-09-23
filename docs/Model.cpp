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

class BaseVertexStorageProvider
{
public:
	virtual void* createVertexStorage(size_t numIndices) const = 0;
};

template <class TStorage>
class VertexStorageProvider : public BaseVertexStorageProvider
{
public:
	void* createVertexStorage(size_t numIndices) const { return new TStorage(numIndices); }
};

template <class TStorage, class TArgument1>
struct VertexStorageProvider2 : BaseVertexStorageProvider 
{
	TArgument1& _argument1;
	
public:
	VertexStorageProvider2(TArgument1& argument1) 
		: _argument1(argument1)
	{ }
	
	void* createVertexStorage(size_t numIndices) const { return new TStorage(_argument1, numIndices); }
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
	TStorage* _storage;
		
public:
	Block(const BaseVertexStorageProvider& vertexStorageProvider) 
	{
		_storage = (TStorage*)vertexStorageProvider.createVertexStorage(4);
	}

	virtual ~Block() 
	{ 
		if(_storage)
			delete _storage;
	}
	
	void test() 
	{
	}

	virtual void draw() 
	{
		for (size_t i = 0; i < 4; i++) 
		{
			cout << _storage->getVertex(i) << " ";
		}
		
		cout << endl;
	}
};

template <class T>
VertexStorageProvider<T> createVertexStorageProvider() 
{
	return VertexStorageProvider<T>();
}

template <class T, class U>
VertexStorageProvider2<T, U> createVertexStorageProvider(U& arg) 
{
	return VertexStorageProvider2<T, U>(arg);
}

int main() 
{
	VertexBuffer vertexBuffer;

	// https://stackoverflow.com/questions/9492595/pass-temporary-object-with-standard-constructor
	// Note: This sucks noodles
	Block<VertexArray> block1(createVertexStorageProvider<VertexArray>());
	Block<VertexBufferView> block2(createVertexStorageProvider<VertexBufferView, VertexBuffer>(vertexBuffer));
	
	block1.draw();
	block2.draw();
}
