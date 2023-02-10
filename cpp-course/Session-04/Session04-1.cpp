#include <iostream>

int main() {
    // Dynamically allocating arrays
    // Unlike a fixed array, where the array size must be fixed at compile time, dynamically allocating an array allows us to choose an array length at runtime.
    const int len = 100'000;
    int* array = new int[len];
    int fix_len_array[5]{};


    // code
    std::cout << "address of index 0: " << array << '\n';
    std::cout << "address of index 1: " << (array + 1) << "\n\n";

    std::cout << "data in index 0:\t" << *(array) << '\n';
    std::cout << "data in index 1:\t" << *(array + 1) << "\n\n"; // array[1]


    std::cout << "size of pointer:\t" << sizeof(array) << '\n';
    std::cout << "size of fix_len_array:\t" << (sizeof(fix_len_array) / sizeof(int)) << '\n';

    delete[] array;
    array = nullptr;

    std::cout << "=========================================================================================\n";
    
    std::cout << "enter how much is the len of array:\t";

    int length;
    std::cin >> length;

    int* point_to_array = new int[length];
    
    std::cout << "please enter " << length << " values:\n";
    for (int i = 0; i < length; i++)
        std::cin >> *(point_to_array + i);

    std::cout << "\n\nvalues:\n";
    for (int i = 0; i < length; i++)
        std::cout << *(point_to_array + i) << '\n';

    delete[] point_to_array;
    point_to_array = nullptr;

    // we don't need to set array to nullptr/0 here because it's going to go out of scope immediately after this anyway

    // Dynamically deleting arrays
    // When deleting a dynamically allocated array, we have to use the array version of delete, which is delete[].
    // One often asked question of array delete[] is, “How does array delete know how much memory to delete?” The answer is that array new[] keeps track of how much memory was allocated to a variable, so that array delete[] can delete the proper amount. Unfortunately, this size/length isn’t accessible to the programmer.


    // Dynamic arrays are almost identical to fixed arrays
    // A fixed array holds the memory address of the first array element. You also learned that a fixed array can decay into a pointer that points to the first element of the array. In this decayed form, the length of the fixed array is not available (and therefore neither is the size of the array via sizeof()), but otherwise there is little difference.
    // A dynamic array starts its life as a pointer that points to the first element of the array. Consequently, it has the same limitations in that it doesn’t know its length or size. A dynamic array functions identically to a decayed fixed array, with the exception that the programmer is responsible for deallocating the dynamic array via the delete[] keyword.


    // nitializing dynamically allocated arrays


}