#include <iostream>

void printSize(int* array /*int array[]*/) // C++ will implicitly convert parameter array[] to *array
{
    // array is treated as a pointer here, not a fixed array
    std::cout << "size of array in function:\t" << sizeof(array) << "\n\n"; // prints the size of a pointer, not the size of the array!
} // Note that this happens even if the parameter is declared as a fixed array
// C++ implicitly converts parameters using the array syntax ([]) to the pointer syntax (*).
// Better to use (int*) instead od (int array[]) to not forget you are using pointer not array


// parameter ptr contains a copy of the array's address
void changeArray(int* ptr)
{
    *ptr = 5; // so changing an array element changes the _actual_ array
}

int main()
{

{

    system("cls");


    // nullptr in C++11
    // C++11 introduces a new keyword called nullptr. nullptr is a keyword, much like the boolean keywords true and false are.
    int* pointer { nullptr }; // note: pointer is still an integer pointer, just set to a null value
    std::cout << pointer << '\n';
    std::cout << "==============================================================================\n";



    // Pointers and arrays
    // when a fixed array is used in an expression, the fixed array will decay (be implicitly converted) into a pointer that points to the first element of the array. 
    int array[5]{ 9, 7, 5, 3, 1 };
    
    

    // print address of the array's first element
    std::cout << "address of first element:\t" << &array[0] << '\n';
    std::cout << "what is in arrya?\t" << array << '\n';

    // print the value of the pointer the array decays to
    std::cout << "first elemnt?\t" << array[0] << '\n';
    std::cout << "point to first elemtn: " << *array << '\n';


    // It’s a common fallacy in C++ to believe an array and a pointer to the array are identical. They’re not. In the above case, array is of type “int[5]”, and its “value” is the array elements themselves. A pointer to the array would be of type “int*”, and its value would be the address of the first element of the array.
    // All elements of the array can still be accessed through the pointer, but information derived from the array’s type (such as how long the array is) can not be accessed from the pointer.

    // Indirection through an array returns the first element (element 0)


    // C-style string (also an array)


    // We can also assign a pointer to point at the array
   

    // *********************************************
    // Differences between pointers and fixed arrays
    // The primary difference occurs when using the sizeof() operator. When used on a fixed array, sizeof returns the size of the entire array (array length * element size). When used on a pointer, sizeof returns the size of a memory address (in bytes). 
}
{
    std::cout << "\n\n\n\n";
    int array[] { 1, 2, 3, 4, 5 };
    std::cout << "Size of array: "   << sizeof(array) << "\n"; // will print sizeof(int) * array length
    
    int* ptr{ array };
    std::cout << "Size of pointer: " << sizeof(ptr) << "\n\n";  // will print the size of a pointer
    // A fixed array knows how long the array it is pointing to is. A pointer to the array does not.


    // The second difference occurs when using the address-of operator (&). Taking the address of a pointer yields the memory address of the pointer variable. Taking the address of the array returns a pointer to the entire array. This pointer also points to the first element of the array, but the type information is different (in the above example, the type of &array is int(*)[5]). It’s unlikely you’ll ever need to use this.
    std::cout << "array: "              << array << '\n';	   // type int[5], prints 009DF9D4
    std::cout << "address of array: "   << &array << "\n\n";   // type int(*)[5], prints 009DF9D4

    std::cout << "pointer: "            << ptr << '\n';	       // type int*, prints 009DF9D4
    std::cout << "address of pointer: " << &ptr << "\n\n";	   // type int**, prints 009DF9C8


    // Revisiting passing fixed arrays to functions
    // we mentioned that because copying large arrays can be very expensive, C++ does not copy an array when an array is passed into a function. When passing an array as an argument to a function, a fixed array decays into a pointer, and the pointer is passed to the function


    // print size
    std::cout << "size of array: " << sizeof(array) << '\n';
    printSize(array);


    // Arrays in structs and classes don’t decay
    // Finally, it is worth noting that arrays that are part of structs or classes do not decay when the whole struct or class is passed to a function. This yields a useful way to prevent decay if desired
}


    // Pointer arithmetic and array indexing

    // Pointer arithmetic
    // If ptr points to an integer, ptr + 1 is the address of the next integer in memory after ptr. ptr - 1 is the address of the previous integer before ptr.
    // If ptr points to an integer (assuming 4 bytes), ptr + 3 means 3 integers (12 bytes) after ptr. If ptr points to a char, which is always 1 byte, ptr + 3 means 3 chars (3 bytes) after ptr.
    // When calculating the result of a pointer arithmetic expression, the compiler always multiplies the integer operand by the size of the object being pointed to. This is called scaling.
    int variable = 4;
    int* point_to_variable = &variable;

    std::cout << "address 0:\t" << point_to_variable << '\n';
    std::cout << "address +1:\t" << (point_to_variable + 1) << '\n';
    std::cout << "address +2:\t" << (point_to_variable + 2) << '\n';
    std::cout << "address +3:\t" << (point_to_variable + 3) << '\n';
    std::cout << "address +4:\t" << (point_to_variable + 4) << "\n\n";


    // Arrays are laid out sequentially in memory
    // proof ?
    int array[] = {1, 2, 3, 4, 5, 6, 7};

    std::cout << "element at 0: " << *(array + 0) << '\n';
    std::cout << "element at 1: " << *(array + 1) << '\n';
    std::cout << "element at 2: " << *(array + 2) << '\n';
    std::cout << "element at 3: " << *(array + 3) << "\n\n";

    std::cout << "address element at 0: " << &array[0] << '\n';
    std::cout << "address element at 1: " << &array[1] << '\n';
    std::cout << "address element at 2: " << &array[2] << '\n';
    std::cout << "address element at 3: " << &array[3] << '\n';
    
    return 0;
}