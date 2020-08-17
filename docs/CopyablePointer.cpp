// Example program
#include <iostream>
#include <string>

using namespace std;

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
    CircleEmissionShape() 
        : _radius(1)
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
class CopyableBasePointer
{    
    T* _pointer; 
    
public:    
    CopyableBasePointer() 
        : _pointer(NULL)
    { }

    CopyableBasePointer(T* pointer) 
        : _pointer(pointer)
    { }

    T* getPointer() { return _pointer; }
    
    void setPointer(T* pointer) { _pointer = pointer; }
        
    virtual CopyableBasePointer<T>* clone() = 0;
};

template <class TBase, class TDerived>
class CopyableDerivedPointer : public CopyableBasePointer<TBase>
{
    TDerived* _pointer;
    
public:    
    CopyableDerivedPointer(TBase* pointer)
        : CopyableBasePointer<TBase>(pointer)        
    { }

    CopyableBasePointer<TBase>* clone()
    {
        TBase* basePointer = CopyableBasePointer<TBase>::getPointer();
        TDerived* copiedPointer = NULL;
        
        if (basePointer) 
        {
            // TODO: Check if actually inherited
            TDerived* currentPointer = (TDerived*)basePointer;
            copiedPointer = new TDerived(*currentPointer);
        }
        
        CopyableBasePointer<TBase>* cloned = new CopyableDerivedPointer<TBase, TDerived>(copiedPointer);
        return cloned;
    }
};

class ParticleSystem
{
    CopyableBasePointer<EmissionShape>* _emissionShapePointer;
    
public:
    ParticleSystem()
        : _emissionShapePointer(NULL)
    {
    }
    
    ParticleSystem(const ParticleSystem& other) 
    {
        *this = other;
        _emissionShapePointer = other._emissionShapePointer->clone();
    }

    template <class T>
    void setEmissionShape(const T& emissionShape)
    {
        T* pointer = new T(emissionShape);
        
        CopyableDerivedPointer<EmissionShape, T>* copyablePointer = 
            new CopyableDerivedPointer<EmissionShape, T>(pointer);
        
        _emissionShapePointer = copyablePointer;
    }
    
    void update() 
    {        
        if (_emissionShapePointer)
            _emissionShapePointer->getPointer()->print();
    }
};

int main()
{
    CircleEmissionShape circleEmissionShape;
    circleEmissionShape.setRadius(2);
    
    ParticleSystem particleSystem;
    particleSystem.setEmissionShape(circleEmissionShape);
    
    ParticleSystem particleSystem2(particleSystem);
    
    particleSystem.update();
    particleSystem2.update();
}
