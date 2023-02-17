#include <iostream>
#include <cassert>

class Fraction
{
private:
    int m_numerator;
    int m_denominator;

public:
    Fraction() // default constructor
    {
         m_numerator = 0;
         m_denominator = 1;
    }

    // Constructor with two parameters, one parameter having a default value
    Fraction(int numerator, int denominator = 1)
    {
        assert(denominator != 0);
        m_numerator = numerator;
        m_denominator = denominator;
    }

    int getNumerator() { return m_numerator; }
    int getDenominator() { return m_denominator; }
    double getValue() { return static_cast<double>(m_numerator) / m_denominator; }
};

class Fraction2
{
private:
    int m_numerator {};
    int m_denominator {};

public:
    // Default constructor
    Fraction2(int numerator = 0, int denominator = 1)
    {
        assert(denominator != 0);

        m_numerator = numerator;
        m_denominator = denominator;
    }

    int getNumerator()   { return m_numerator; }
    int getDenominator() { return m_denominator; }
    double getValue()    { return static_cast<double>(m_numerator) / m_denominator; }
};

class Date
{
private:
    int m_year = 1900;
    int m_month = 1;
    int m_day = 1;

/*

public:
    Date() // an example of what the implicitly generated default constructor for Date looks like
    {
    
    }

*/
    // No user-provided constructors, the compiler generates a default constructor.
};

class Date2
{
private:
    int m_year = 1900;
    int m_month = 1;
    int m_day = 1;

public:
    // Tell the compiler to create a default constructor, even if there are other user-provided constructors.
    Date2() 
    {

    }

    Date2(int year, int month, int day) // normal non-default constructor
    {
        m_year = year;
        m_month = month;
        m_day = day;
    }
};


int main()
{

    // When all members of a class (or struct) are public, we can use aggregate initialization to initialize the class (or struct) directly using list-initialization
    // However, as soon as we make any member variables private, we’re no longer able to initialize classes in this way.

    // Constructors
    // A constructor is a special kind of class member function that is automatically called when an object of that class is created. Constructors are typically used to initialize member variables of the class to appropriate user-provided values, or to do any setup steps necessary for the class to be used (e.g. open a file or database).

    // Unlike normal member functions, constructors have specific rules for how they must be named:
    //      1- Constructors must have the same name as the class (with the same capitalization)
    //      2- Constructors have no return type (not even void)

    // Default constructors
    // A constructor that takes no parameters (or has parameters that all have default values) is called a default constructor. The default constructor is called if no user-provided initialization values are provided.
    // You do not need to value initialize (use empty braces) when defining a class object with no initializer. 
    
    
    Fraction six2 = Fraction(6);   // Copy initialize a Fraction, will call Fraction(6, 1)


    // Reducing your constructors
    {
        // Fraction frac; // Default-initialization, calls default constructor
        Fraction2 zero1;                           // will call Fraction(0, 1)
        Fraction2 zero = Fraction2();              // will call Fraction(0, 1)
        Fraction2 six = Fraction2(6);              // will call Fraction(6, 1)
        Fraction2 fiveThirds = Fraction2(5, 3);    // will call Fraction(5, 3)
    }

    // An implicitly generated default constructor
    // If your class has no constructors, C++ will automatically generate a public default constructor for you. This is sometimes called an implicit constructor (or implicitly generated constructor).

    Date date;
    // Note that this implicitly generated default constructor has an empty body, and thus does no initialization or assignment itself. However, members will still be initialized if they have non-static member initializers.
    // If your class has any other constructors, the implicitly generated constructor will not be provided. 
    double x = 2;

    // Constructor notes
    // Many new programmers are confused about whether constructors create the objects or not. They do not -- the compiler sets up the memory allocation for the object prior to the constructor call.
    // Constructors actually serve two purposes. First, constructors determine who is allowed to create an object. That is, an object of a class can only be created if a matching constructor can be found.
    // Second, constructors can be used to initialize objects. Whether the constructor actually does an initialization is up to the programmer. It’s syntactically valid to have a constructor that does no initialization at all (the constructor still serves the purpose of allowing the object to be created, as per the above).


    return 0;
}