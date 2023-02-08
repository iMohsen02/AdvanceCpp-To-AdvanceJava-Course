#include <iostream>
#include <bitset>

struct Something {
    int value;
    bool rich;
    std::string name;
    double money;
};

int main()
{

    // --------------------------------------------------------------------------
    
    // Bitwise assignment operators
    // Similar to the arithmetic assignment operators, C++ provides bitwise assignment operators in order to facilitate easy modification of variables.
    
    // Operator	                    Symbol	    Form	    Operation
    // --------------------------------------------------------------------
    // Left shift assignment	    <<=	        x <<= y	    Shift x left by y bits
    // Right shift assignment	    >>=	        x >>= y	    Shift x right by y bits
    // Bitwise OR assignment	    |=	        x |= y	    Assign x | y to x
    // Bitwise AND assignment	    &=	        x &= y	    Assign x & y to x
    // Bitwise XOR assignment	    ^=	        x ^= y  	Assign x ^ y to x

    // For example, instead of writing x = x >> 1;, you can write x >>= 1;.
    std::cout << "Bitwise assignment operators =>\n\n";
    std::bitset<4> bits { 0b0100 };
    bits >>= 1; // bits = bits >> 1;

    std::cout << bits << "\n\n";
    // --------------------------------------------------------------------------
    std::cout << "==========================================================================\n";
    std::cout << "shift points =>" << "\n\n";

    int number = 5;
    std::cout << "number is:\t" << number << '\n';

    number = number << 2; // for each time number * 2
    number = number >> 2; // for each time number / 2 (int / int)
    std::cout << "after shift:\t" << number << "\n\n";


    // --------------------------------------------------------------------------
    std::cout << "==========================================================================\n";
    std::cout << "swapping without temp variable => \n\n";

    // ****** point that both variable shouldn't point to a same location ******

    int first_num = 20;
    int second_num = 40;

    // int temp = first_num;
    // first_num = second_num;
    // second_num = temp;

    std::cout << "first_num is:\t" << first_num << '\n';
    std::cout  << "second_nnum is:\t" << second_num << '\n';

    first_num ^= second_num; // x = (x ^ y)
    second_num ^= first_num; // y = y ^ (x ^ y) => x
    first_num ^= second_num; // x ^ (x ^ y) => y

    std::cout << "\nafter swapping =>\n";
    std::cout << "first_num is:\t" << first_num << '\n';
    std::cout << "second_nnum is:\t" << second_num << "\n\n";

    // --------------------------------------------------------------------------
    // what is scope ?



    // we noted that a variable is a name for a piece of memory that holds a value. When our program instantiates a variable, a free memory address is automatically assigned to the variable, and any value we assign to the variable is stored in this memory address.
{
    // The address-of operator (&)
    // The address-of operator (&) allows us to see what memory address is assigned to a variable.
    
    int year = 2023;
    std::cout  << "address of year in RAM: " << &year << "\n\n";

}

{
    // The indirection operator (*)
    // Getting the address of a variable isn’t very useful by itself.
    // The indirection operator (*) (also called dereference operator) allows us to access the value at a particular address

    int year = 2024;
    std::cout << "address year is: " << &year << '\n';
    std::cout << "what is in year add: " << *(&year) << "\n\n"; 

}

{
    // Pointers
    //  A pointer is a variable that holds a memory address as its value.

    // Declaring a pointer
    // Pointer variables are declared just like normal variables, only with an asterisk between the data type and the variable name. Note that this asterisk is not an indirection. It is part of the pointer declaration syntax.
    int variable = 4;

    int* point_to_int;
    int * point_to_int1; 
    int *point_to_int2;


    // Assigning a value to a pointer
    // Since pointers only hold addresses, when we assign a value to a pointer, that value has to be an address. One of the most common things to do with pointers is have them hold the address of a different variable.
    int* point_var = &variable;

    std::cout << "address variable:\t" << &variable << '\n';
    std::cout << "pointer to variable:\t" << point_var << "\n\n";


    // The type of the pointer has to match the type of the variable being pointed to
    std::cout << "what is in this pointer:\t" << *point_var << '\n';


    // Note that the following is also not legal
    // int* ptr{ 5 }; // pointers can only hold addresses, and the integer literal 5 does not have a memory address.



    // The address-of operator returns a pointer
    // It’s worth noting that the address-of operator (&) doesn’t return the address of its operand as a literal. Instead, it returns a pointer containing the address of the operand

}

{

    // Indirection through pointers
    // Indirection through the pointer to get the value of what it’s pointing at. Indirection through a pointer evaluates to the contents of the address it is pointing to.
    int year = 2025;
    int* pyear { &year };

    year = 2026;
    std::cout << "what is in year pointer:\t" << *pyear << '\n';

    *pyear = 2027;
    std::cout << "wha is in year:\t" << year << '\n';

    // This is why pointers must have a type. Without a type, when indirecting through a pointer, the pointer wouldn’t know how to interpret the contents it was pointing to. 
    // ؟؟؟


    // The size of pointers
    // The size of a pointer is dependent upon the architecture the executable is compiled for -- a 32-bit executable uses 32-bit memory addresses 
    char* ch_pointer;
    int* i_pointer;
    Something* s_pointer;

    std::cout << "\n\nSize of pointers =>\n";

    std::cout << "size of ch_pointer\t" << sizeof(ch_pointer) << '\n';
    std::cout << "size of i_pointer\t"  << sizeof(i_pointer)  << '\n';
    std::cout << "size of s_pointer\t"  << sizeof(s_pointer)  << '\n';


    // Note: If an application tries to access a memory location not allocated to it by the operating system, the operating system may shut down the application.
    // Note: Create an uninitialized pointer (that points to garbage)
}

    return 0;
}