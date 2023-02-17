#include <iostream>

class Student
{
    int id;
    
public:
    
    static int id_generator;
    Student()
    {
        id = id_generator++;
        std::cout << "id:\t" << id << '\n';
    }
};

int Student::id_generator = 0;

int main()
{

    // Statics can be accessed through the class itself without creating the object.
    // Static values are related to the class itself and are not generated for each object instance and are common to all objects.
    // Static members can be accessed using the object or class itself

    Student::id_generator = 20;

    Student mohsen = Student();
    Student pooria = Student();

    // mohsen.id_generator = 30;
    Student hassan = Student();
    return 0;
}