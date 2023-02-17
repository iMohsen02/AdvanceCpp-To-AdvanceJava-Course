#include <iostream>

int main() {
    
    // Pointers to pointers and dynamic multidimensional arrays

    // Pointers to pointers
    // A normal pointer to an int is declared using a single asterisk
    int* ptr1; // pointer to an int, one asterisk

    // A pointer to a pointer to an int is declared using two asterisks
    int** ptrptr1; // pointer to a pointer to an int, two asterisks

    int value { 5 };
    int* ptr { &value };
    std::cout << *ptr << '\n'; // Indirection through pointer to int to get int value

    int** ptrptr { &ptr };
    std::cout << **ptrptr << '\n'; // first indirection to get pointer to int, second indirection to get int value


    // Note that you can not set a pointer to a pointer directly to a value
    // int** ptrptr { &&value }; // not valid


    // Arrays of pointers
    // Pointers to pointers have a few uses. The most common use is to dynamically allocate an array of pointers
    int* arary2 = new int[20];
    int** array1 = new int*[10]; // allocate an array of 10 int pointers
    

    // Two-dimensional dynamically allocated arrays

    // There are two possible solutions here. If the rightmost array dimension is a compile-time constant, you can do this:
    // int (*array)[5] { new int[10][5] };
    // auto array { new int[10][5] }; // so much simpler!

    // Unfortunately, this relatively simple solution doesn’t work if any non-leftmost array dimension isn’t a compile-time constant. In that case, we have to get a little more complicated. First, we allocate an array of pointers (as per above). Then we iterate through the array of pointers and allocate a dynamic array for each array element. Our dynamic two-dimensional array is a dynamic one-dimensional array of dynamic one-dimensional arrays!
    int** array = new int*[10]; // allocate an array of 10 int pointers — these are our rows
    for (int count = 0; count < 10; ++count)
        array[count] = new int[5]; // these are our columns

    /*
    
    With this method, because each array column is dynamically allocated independently, it’s possible to make dynamically allocated two dimensional arrays that are not rectangular. For example, we can make a triangle-shaped array:

    int** array { new int*[10] }; // allocate an array of 10 int pointers — these are our rows
    for (int count = 0; count < 10; ++count)
        array[count] = new int[count+1]; // these are our columns
    */

    // Deallocating a dynamically allocated two-dimensional array using this method requires a loop as well
    for (int count = 0; count < 10; ++count)
        delete[] array[count];
    delete[] array; // this needs to be done last

    /*
    // Instead of this:
    int** array { new int*[10] }; // allocate an array of 10 int pointers — these are our rows
    for (int count = 0; count < 10; ++count)
        array[count] = new int[5]; // these are our columns

    // Do this
    int *array { new int[50] }; // a 10x5 array flattened into a single array
    */

    // Passing a pointer by address ...

    // Pointer to a pointer to a pointer to ...
    return 0;
}