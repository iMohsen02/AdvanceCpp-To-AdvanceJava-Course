#include <iostream>

void printByValue(std::string val) // The function parameter is a copy of str
{
    std::cout << val << '\n'; // print the value via the copy
}

void printByReference(const std::string& ref) // The function parameter is a reference that binds to str
{
    std::cout << ref << '\n'; // print the value via the reference
}

void printByAddress(const std::string* ptr) // The function parameter is a pointer that holds the address of str
{
    std::cout << *ptr << '\n'; // print the value via the dereferenced pointer
}

// void changeValue(const int* ptr) // note: ptr is now a pointer to a const and not allowed to change value
void changeValue(int* ptr) // note: ptr is a pointer to non-const in this example
{
    *ptr = 6; // change the value to 6
}

void print(int* ptr)
{
    if (ptr) // if ptr is not a null pointer
    {
        std::cout << *ptr << '\n';
    }
}

void greet(std::string* name=nullptr)
{
    std::cout << "Hello ";
    std::cout << (name ? *name : "guest") << '\n';
}

void nullify(int* ptr2)
{
    ptr2 = nullptr; // Make the function parameter a null pointer
}

void nullifyPointer(int*& refptr) // refptr is now a reference to a pointer
{
    refptr = nullptr; // Make the function parameter a null pointer
}


int pow(int base = 3, int power = 2) 
{
    std::cout << "base:\t" << base << "\tpower:\t" << power << '\n';
    return 0;
}




int main() {

    pow();
    pow(2);
    pow(4, 5);

    // Pass by address
    // C++ provides a third way to pass values to a function, called pass by address. With pass by address, instead of providing an object as an argument, the caller provides an object’s address (via a pointer). This pointer (holding the address of the object) is copied into a pointer parameter of the called function (which now also holds the address of the object). The function can then dereference that pointer to access the object whose address was passed.
    std::string name = "Mohsen";

    printByValue(name);
    printByReference(name);
    printByAddress(&name);

    // print values function




    // Pass by address does not make a copy of the object being pointed to

    // Pass by address allows the function to modify the argument’s value
    // When we pass an object by address, the function receives the address of the passed object, which it can access via dereferencing. Because this is the address of the actual argument object being passed (not a copy), if the function parameter is a pointer to non-const, the function can modify the argument via the pointer parameter

    // change value
	int x = 4;

    std::cout << "\nx is:\t" << x << '\n';
    changeValue(&x);
    std::cout << "after change value by pointer, x is:\t" << x << '\n';


    // Null checking
    // When passing a parameter by address, care should be taken to ensure the pointer is not a null pointer before you dereference the value. One way to do that is to use a conditional statement



    // Prefer pass by (const) reference
    // First, Given this, why allow a user to pass in a null value at all? Pass by reference has the same benefits as pass by address without the risk of inadvertently dereferencing a null pointer.
    // Second, the syntax for pass by reference is natural, as we can just pass in literals or objects. With pass by address, our code ends up littered with ampersands (&) and asterisks (*).



    // Pass by address for “optional” arguments ??????????



    // Changing what a pointer parameter points at
    // When we pass an address to a function, that address is copied from the argument into the pointer parameter
    // changing the address held by the pointer parameter had no impact on the address held by the argument
    int* pointer_to_x = &x;
    std::cout << "\n\npointer to x is:\t" << pointer_to_x << '\n';
    nullify(pointer_to_x);
    std::cout << "pointer to x is:\t" << pointer_to_x << '\n';






    // ===============================================================================================================================
    // Pass by address… by reference?
    // Yup, it’s a thing. Just like we can pass a normal variable by reference, we can also pass pointers by reference. 

    // Because refptr is now a reference to a pointer, when ptr is passed as an argument, refptr is bound to ptr. This means any changes to refptr are made to ptr.



    return 0;
}