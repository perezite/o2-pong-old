template <class T>
inline void safeDelete(T* pointer)
{
    if (pointer)
        delete pointer;
}

class EmissionShape
{
public:
    virtual ~EmissionShape() { }

    virtual void print() = 0;
};

class CircleEmissionShape : public EmissionShape
{
    float _radius;

public:
    CircleEmissionShape(float radius = 1)
        : _radius(radius)
    { }

    inline void setRadius(float radius) { _radius = radius; }

    void print()
    {
        cout << "CircleEmissionShape::print()" << endl;
        cout << "Address: " << this << endl;
        cout << "Radius: " << _radius << endl;
    }
};

template <class T>
class ClonableBase
{
    T* _pointer;

protected:
    inline T* getPointer() { return _pointer; }

public:
    ClonableBase(T* pointer)
        : _pointer(pointer)
    { }

    virtual ~ClonableBase()
    {
		safeDelete(_pointer);
	}

    inline T& getObject() { return *_pointer; }

    virtual ClonableBase<T>* clone() = 0;
};

template <class TBase, class TDerived>
class Clonable : public ClonableBase<TBase>
{
public:
    Clonable(const TDerived& object)
        : ClonableBase<TBase>(new TDerived(object))
    { }

    ClonableBase<TBase>* clone()
    {
        TDerived* pointer = (TDerived*)ClonableBase<TBase>::getPointer();
        return new Clonable<TBase, TDerived>(*pointer);
    }
};

class ParticleSystem
{
    ClonableBase<EmissionShape>* _emissionShape;

public:
    ParticleSystem()
        : _emissionShape(NULL)
    { }

    ParticleSystem(const ParticleSystem& other)
    {
        *this = other;
        _emissionShape = other._emissionShape->clone();
    }

    virtual ~ParticleSystem()
    {
        safeDelete(_emissionShape);
    }

    template <class T>
    void setEmissionShape(const T& emissionShape)
    {
        safeDelete(_emissionShape);
        _emissionShape = new Clonable<EmissionShape, T>(emissionShape);
    }

    void print()
    {
        if (_emissionShape)
            _emissionShape->getObject().print();
    }
};

int experiment()
{
    CircleEmissionShape circleEmissionShape(2);
    CircleEmissionShape circleEmissionShape2(3);

    ParticleSystem emitter;
    emitter.setEmissionShape(circleEmissionShape);

    ParticleSystem emitter2(emitter);
    ParticleSystem emitter3 = emitter;

    ParticleSystem emitter4;
    emitter4.setEmissionShape(circleEmissionShape2);

    emitter.print();
    emitter2.print();
    emitter3.print();
    emitter4.print();

    cout << "done..." << endl;
    cin.get();
    exit(0);
}
