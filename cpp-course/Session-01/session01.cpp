#include<iostream>
#include<typeinfo>
#include<bitset>

void func(float x) {std::cout << "float is:\t" << x << '\n'; }
void func(double x) { std::cout << "double is:\t" << x << '\n'; }
void func(double x, float y) 
{ 
    std::cout << "double is:\t" << x << '\n' << "float is:\t" << y << '\n';
}

int main()
{
    system("cls");

    // Intro to contstant-literals(Decimal => int-double-float-unsigned)
    // Auto variables

    // auto variable = 2.45;  // double
    // auto variable = 2.45f; // float
    // 1101 (signed) => -3 
    // auto variable = 2      // int
    // auto variable = 8ull   // unsinged long long



    // 0b-0-ox
    int binary_num = 0b111010101111;
    std::cout << "insert binary nummber: " << binary_num <<"\n\n";

    int octal_num = 0123613;
    std::cout << "insert octal number: " << octal_num << "\toct: " << std::oct << octal_num <<"\n\n";

    int hex_num = 0x346aB3;
    std::cout << "insert hex-decimal number: " << hex_num << "\thex: " << std::hex << hex_num <<"\n\n";

    std::cout << std::dec; // lets set print output as decimal number
    std::cout << "==========================================================================\n\n";
    // scientific symbol e, E
    int scientific_int = 2.4E4; // 2.4e4
    std::cout << "scientific int:\t" << scientific_int << '\n'; 

    double sicentific_double = 75.8e-5;
    std::cout << "scientific double:\t" << sicentific_double << '\n'; 

    // number-separator
    int number = 23'485'492;





    // --------------------------------------------------------------------------
    // Function overloading and useing constant literals

    // func(2.3); // call double function
    // func(2.3f);// call float function


    // --------------------------------------------------------------------------
    // Unary arithmetic operators
    // There are two unary arithmetic operators, plus (+), and minus (-). As a reminder, unary operators are operators that only take one operand.

    // Operator	        Symbol	    Form	    Operation
    // ----------------------------------------------------------
    // Unary plus	    +	        +x	        Value of x
    // Unary minus	    -	        -x	        Negation of x

    

    // Binary arithmetic operators
    // There are 5 binary arithmetic operators. Binary operators are operators that take a left and right operand.

    // Operator	                Symbol	    Form	    Operation
    // --------------------------------------------------------------------------------
    // Addition	                +	        x + y	    x plus y
    // Subtraction          	-	        x - y	    x minus y
    // Multiplication	        *	        x * y	    x multiplied by y
    // Division             	/	        x / y	    x divided by y
    // Modulus (Remainder)  	%	        x % y	    The remainder of x divided by y

    // point: (int) % (int)



    // The modulus operator
    // The modulus operator (also informally known as the remainder operator) is an operator that returns the remainder after doing an integer division. e.g 7 / 4 = 1




    // Where’s the exponent operator?
    // You’ll note that the ^ operator (commonly used to denote exponentiation in mathematics) is a Bitwise XOR operation in C++.C++ does not include an exponent operator.




    // Increment/decrement operators, and side effects
    // Incrementing (adding 1 to) and decrementing (subtracting 1 from)

    // Operator	                                Symbol	    Form	    Operation
    // ---------------------------------------------------------------------------------------------------------------
    // Prefix increment (pre-increment)	        ++	        ++x	        Increment x, then return x
    // Prefix decrement (pre-decrement)	        ––	        ––x	        Decrement x, then return x
    // Postfix increment (post-increment)	    ++	        x++	        Copy x, then increment x, then return the copy
    // Postfix decrement (post-decrement)	    ––	        x––	        Copy x, then decrement x, then return the copy

    std::cout << "==========================================================================\n\n";

    int x = 4;
    std::cout << ++x << '\n'; // x = 5;
    std::cout << x++ << '\n'; // print 5 => x = 6
    std::cout << x   << '\n'; // print 6



    // Relational operators and floating point comparisons (Q?)
    // Relational operators are operators that let you compare two values. There are 6 relational operators:

    
    // Operator	                Symbol	    Form	    Operation
    // ------------------------------------------------------------------------------------------------
    // Greater than 	        >	        x > y   	true if x is greater than y, false otherwise
    // Less than	            <	        x	        true if x is less than y, false otherwise
    // Greater than or equals	>=	        x >= y	    true if x is greater than or equal to y, false otherwise
    // Less than or equals	    <=	        x	        true if x is less than or equal to y, false otherwise
    // Equality	                ==	        x == y  	true if x equals y, false otherwise
    // Inequality	            !=	        x != y	    true if x does not equal y, false otherwise




    // Logical operators
    // Often we need to know whether multiple conditions are true simultaneously. Logical operators provide us with the capability to test multiple conditions.

    
    // Operator     	Symbol	        Form	        Operation
    // -------------------------------------------------------------------------------------------------
    // Logical NOT	    !	            !x	            true if x is false, or false if x is true
    // Logical AND	    &&	            x && y	        true if both x and y are true, false otherwise
    // Logical OR	    ||	            x || y	        true if either x or y are true, false otherwise

    // operand => boolean 
    // "Hassan" => True
    // if (condition) => don't use inc/dec operator
    // { 
    // // code
    // }


    // --------------------------------------------------------------------------
    // bitwise operator

    // Operator	        Symbol	    Form	    Operation
    // ----------------------------------------------------------------------------
    // left shift	    <<	        x << y	    all bits in x shifted left y bits
    // right shift	    >>	        x >> y  	all bits in x shifted right y bits
    // bitwise NOT	    ~	        ~x	        all bits in x flipped
    // bitwise AND	    &	        x & y   	each bit in x AND each bit in y
    // bitwise OR	    |	        x | y   	each bit in x OR each bit in y
    // bitwise XOR	    ^	        x ^ y   	each bit in x XOR each bit in y

    std::cout << "==========================================================================\n";
    std::cout << "Bitwise &" << "\n\n";
    // &
    // 1 & 1 => 1
    // binary_num & binary_num
    // 1 0 1 1 AND
    // 0 1 1 0
    // ===========
    // 0 0 1 0

    std::bitset<4> x1 = 0b1011;
    std::bitset<4> x2 = 0b0110;

    std::cout << "x1 is:\t" << x1 << '\n';
    std::cout << "x2 is:\t" << x2 << '\n';

    std::cout << "bitwise x1 & x2: " << (x1 & x2) << "\n\n";

    std::cout << "==========================================================================\n";
    std::cout << "Bitwise |" << "\n\n";
    // |
    // 1 | 0 => 1
    // binary_num | binary_num
    // 1 0 1 1 OR
    // 0 1 1 0
    // ===========
    // 1 1 1 1
    std::cout << "x1 is:\t" << x1 << '\n';
    std::cout << "x2 is:\t" << x2 << '\n';

    std::cout << "bitwise x1 | x2: " << (x1 | x2) << "\n\n";
    std::cout << "==========================================================================\n";
    std::cout << "Bitwise ^" << "\n\n";

    // ^
    // 1 ^ 0 => 1
    // 0 ^ 1 => 1
    // 1 ^ 1 => 0
    // 0 ^ 0 => 1
    std::cout << "x1 is:\t" << x1 << '\n';
    std::cout << "x2 is:\t" << x2 << '\n';

    std::cout << "bitwise x1 ^ x2: " << (x1 ^ x2) << "\n\n";


    // Swap two variable which aren't refer to the same location =>
    std::cout << "==========================================================================\n";
    std::cout << "Usage of bitwise ^" << "\n\n";

    int var1 = 20;
    int var2 = 40;

    // int temp = var1;
    // var1 = var2;
    // var2 = temp;


    std::cout << "x is: " << var1 << '\n';
    std::cout << "y is: " << var2 << "\n\n";

    var1 ^= var2;
    var2 ^= var1;
    var1 ^= var2;

    std::cout  << "x is: " << var1 << '\n';
    std::cout << "y is: " << var2 << "\n\n\n";

    std::cout << "==========================================================================\n";
    std::cout << "Bitwise ~" << "\n\n";

    // ~ tilde
    // ~011101 => 100010
    std::cout << "x1 is:\t" << x1 << '\n';
    std::cout << "bitwise ~x1: " << ~x1 << "\n\n";


    std::cout << "==========================================================================\n";
    std::cout << "Bitwise shift" << "\n\n";

    // shift => binary_num (shift) num
    std::cout << "x1 is:\t" << x1 << '\n';
    std::cout << "x1 >> 1:\t" << (x1 >> 2) << '\n'; 

    std::cout << "x1 << 1:\t" << (x1 << 2) << '\n'; 

    return 0;
}