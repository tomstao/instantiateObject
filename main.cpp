#include <iostream>
#include <string>

using String = std::string;

class Entity
{
private:
String m_Name;
public:
    Entity() : m_Name("Unknown") {}
    Entity(const String& name) : m_Name(name) {}

    const String& GetName() const { return m_Name; }
};

void Function()
{
    int a = 2;
    Entity entity = Entity("Cherno");
    // This object will be destroyed when the function ends --> when it reached the end of the scope
}

int main()
{
    // Entity* e;
    // {
    //     Entity entity("Cherno");
    //     e = &entity;
    //     std::cout << entity.GetName() << std::endl;
    //     // Before the scope ends, the poninter is still valid ponints to cherno
    //     // But after the scope ends, the object is destroyed, so the pointer is invalid, cherno is gone.
    //     // And the pointer is pointing to a destroyed object, which is a dangling pointer
    //     // Stack has limited size, so it's not a good idea to create a lot of objects or a huge object on the stack
    // }
    //
    // Scope doesn't necessarily mean a function, it can be a block of code

    Entity* e;


    {
        Entity* entity = new Entity("Cherno");
        // Use new keyword to create an object on the heap
        // You should delete the object when you don't need it anymore
        // And don't always use new keyword to create an object, because it's slower than creating an object on the stack
        e = entity;
        // We are storing the address of the object in the heap to the pointer
        std::cout << entity->GetName() << std::endl;
        // Use arrow operator to access the member of the object

        // This object will be destroyed when the block ends
        delete entity;
        // If you used the new keyword, don't forget to delete the object
    }
    Entity entity;
    Entity entity2("Cherno");
    // the most common way to create an object is to create it on the stack

    // This object is created on the stack, ans instantiated with the default constructor(no parameter)

    std::cout << entity.GetName() << std::endl;
    std::cout << entity2.GetName() << std::endl;





    std::cout << "Hello, World!" << std::endl;
    return 0;
}
