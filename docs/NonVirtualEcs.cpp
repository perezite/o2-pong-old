#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

namespace nonVirtualEcs
{
    /*
    void demoxxx() 
    {
        EntityWithPhysics entityWithPhysics;
        entityWithPhysics.createChild<EntityWithCollider>();

        entityWithPhysics.updatePhysics();
        entityWithPhysics.collide();

        // only entityWithPhysics.updatePhysics() must get called
        // only entityWithCollider.collide() must get called
    }
    */

    class Entity0
    {
        string _name;

        vector<Entity0*> _children;

    public:
        Entity0(const string& name)
            : _name(name)
        { }

        template <class T>
        inline void createChild(const string& name) { _children.push_back(new T(name)); }

        void updatePhysics()
        {
            cout << _name << ":" << " updatePhysics()" << endl;

            for (size_t i = 0; i < _children.size(); i++)
                _children[i]->updatePhysics();
        }
    };

    void demo0()
    {
        Entity0 parentEntity("parent");
        parentEntity.createChild<Entity0>("child");

        parentEntity.updatePhysics();
    }

    class Entity1
    {
        string _name;

        vector<Entity1*> _children;

    public:
        Entity1(const string& name)
            : _name(name)
        { }

        inline const std::string& getName() const { return _name; }

        template <class T>
        inline void createChild(const string& name) { _children.push_back(new T(name)); }

        virtual void updatePhysics() = 0;

        void updateEntityPhysics()
        {
            updatePhysics();

            for (size_t i = 0; i < _children.size(); i++)
                _children[i]->updateEntityPhysics();
        }
    };

    class SimpleEntity1 : public Entity1
    {
    public:
        SimpleEntity1(const string name)
            : Entity1(name)
        { }

        void updatePhysics()
        {
            cout << getName() << ": updatePhysics" << endl;
        }
    };

    void demo1()
    {        
        SimpleEntity1 parentEntity("parent");
        parentEntity.createChild<SimpleEntity1>("child");

        parentEntity.updateEntityPhysics();
    }

    template <class TContainer, class TValue>
    void eliminate(TContainer& container, TValue& value)
    {
        container.erase(remove(container.begin(), container.end(), value), container.end());
    }

    class Entity2
    {
        string _name;

        Entity2* _parent;

        bool _hasPhysics;

        vector<Entity2*> _childrenWithPhysics;

        vector<Entity2*> _childrenWithPhysicsToRemove;

    protected:
        void removeChildrenWithPhysics(vector<Entity2*>& childrenWithPhysicsToRemove)
        {
            for (size_t i = 0; i < childrenWithPhysicsToRemove.size(); i++)
                eliminate(_childrenWithPhysics, _childrenWithPhysicsToRemove[i]);

            childrenWithPhysicsToRemove.clear();
        }

    public:
        Entity2(const string& name, Entity2* parent = NULL)
            : _name(name), _parent(parent), _hasPhysics(true)
        { }

        inline const std::string& getName() const { return _name; }

        template <class T>
        inline T& createChild(const string& name) 
        { 
            T* child = new T(name, this);
            _childrenWithPhysics.push_back(child);
            return *child;
        }

        void disablePhysics(Entity2* child) { _childrenWithPhysicsToRemove.push_back(child); }

        virtual void updatePhysics()
        {
            cout << "disabled physics for " << getName() << endl;

            _hasPhysics = false;
            if (_parent)
                disablePhysics(_parent);

        }

        void updateEntityPhysics()
        {
            for (size_t i = 0; i < _childrenWithPhysics.size(); i++)
                _childrenWithPhysics[i]->updateEntityPhysics();

            if (_hasPhysics)
                updatePhysics();

            removeChildrenWithPhysics(_childrenWithPhysicsToRemove);
        }
    };

    class EntityWithPhysics2 : public Entity2
    {
    public:
        EntityWithPhysics2(const string& name, Entity2* parent = NULL)
            : Entity2(name, parent)
        { }

        virtual void updatePhysics() 
        {
            cout << getName() << ": updatePhysics()" << endl;
        }
    };

    class EntityWithoutPhysics2 : public Entity2
    { 
    public:
        EntityWithoutPhysics2(const string& name, Entity2* parent = NULL)
            : Entity2(name, parent)
        { }
    };

    void demo2()
    {
        EntityWithoutPhysics2 parentEntity("parent without physics");
        EntityWithPhysics2& child = parentEntity.createChild<EntityWithPhysics2>("child with physics");
        child.createChild<EntityWithoutPhysics2>("grandchild without physics");

        while(true)
        {
            parentEntity.updateEntityPhysics();
            cin.get();
        }
    }

    void run()
    {
        demo2();
        //demo1();
        // demo0();
    }
}