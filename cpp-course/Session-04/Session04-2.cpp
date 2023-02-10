#include <iostream>

int main() {
    // In C++, a reference is an alias for an existing object. Once a reference has been defined, any operation on the reference is applied to the object being referenced.

    // int      // a normal int type
    // int&     // an reference to an int object
    // double&  // an reference to a double object
    int mohsen_age = 20;            // normal vaariable
    int& imohsen02 = mohsen_age;    // refrence

    

    // reference variables
    // A reference variable is a variable that acts as a reference to a variable (usually another variable).




    // Modifying values through a reference
    // We can also use a reference to modify the value of the object being referenced
    mohsen_age += 10;
    imohsen02 += 10;
    std::cout << "mohse_age is:\t" << mohsen_age << '\n';
    std::cout << "imohsen02:\t" << imohsen02 << '\n';


    // Initialization of references
    // Much like constants, all references must be initialized.

    // int& invalidRef;   // error: references must be initialized


    // References can’t be bound to non-modifiable rvalues (otherwise you’d be able to change those values through the reference, which would be a violation of their const-ness).
    const int y { 8 };
    // int& refToY { y }; // error

    // References to const
    // By using the const keyword when declaring a reference, we tell a reference to treat the object it is referencing as const.
    const int& refToY { y }; // okay: ref is a a reference to a const value

    // Initializing a reference to const with a modifiable value
    // references to const can also bind to modifiable value. In such a case, the object being referenced is treated as const when accessed through the reference (even though the underlying object is non-const)
    int modifiableValue { 5 };
    const int& refToNonConst { modifiableValue };
    // refToNonConst++; // error: we can not modify an object through a const reference
    modifiableValue++;  // okay: modifiableValue is a modifiable value, we can still modify it through the original identifier


    std::cout << "==========================================================================\n";

    int modifiable = 444'444;
    int& normall_ref = modifiable;
    const int& const_ref = modifiable;

    modifiable++;
    std::cout << "modifiable:\t" << modifiable << '\n';
    std::cout << "normal_ref:\t" << normall_ref << '\n';
    std::cout << "const ref:\t" << const_ref << "\n\n";

    normall_ref = 555'555;
    std::cout << "modifiable:\t" << modifiable << '\n';
    std::cout << "normal_ref:\t" << normall_ref << '\n';
    std::cout << "const ref:\t" << const_ref << "\n\n";

    // can't change the modifiable  through const_ref
    // const_ref++ // error


    // References can’t be reseated (changed to refer to another object)
    // Once initialized, a reference in C++ cannot be reseated, meaning it cannot be changed to reference another object.

    // Reference scope and duration
    // Reference variables follow the same scoping and duration rules that normal variables do:


    // --------------------------------------------------------------------------
    std::cout << "==========================================================================\n";
    std::cout << "Call by References vs Call by value =>\n\n";

    // Pass by reference
    // Some objects are expensive to copy. Class types are usually expensive to copy. 
    // One way to avoid making an expensive copy of an argument when calling a function is to use pass by reference instead of pass by value. When using pass by reference, we declare a function parameter as a reference type (or const reference type) rather than as a normal type. When the function is called, each reference parameter is bound to the appropriate argument. Because the reference acts as an alias for the argument, no copy of the argument is made.



    // Pass by reference allows us to change the value of an argument
    // When an object is passed by value, the function parameter receives a copy of the argument. This means that any changes to the value of the parameter are made to the copy of the argument, not the argument itself:
    // However, since a reference acts identically to the object being referenced, when using pass by reference, any changes made to the reference parameter will affect the argument



    return 0;
} // all variables and refrences die at end of scope