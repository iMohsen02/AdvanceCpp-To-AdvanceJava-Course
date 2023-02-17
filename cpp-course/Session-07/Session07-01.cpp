#include <iostream>

struct DateStruct // members are public by default
{
    int month { };     // public by default, can be accessed by anyone
    int day { };       // public by default, can be accessed by anyone
    int year { };      // public by default, can be accessed by anyone
};

class DateClass1 // members are private by default
{
    int m_month { };    // private by default, can only be accessed by other members
    int m_day { };      // private by default, can only be accessed by other members
    int m_year { };     // private by default, can only be accessed by other members
};

class DateClass
{
public: // note use of public keyword here, and the colon
    int m_month {};     // public, can be accessed by anyone
    int m_day {};       // public, can be accessed by anyone
    int m_year {};      // public, can be accessed by anyone
};

class DateClass2 // members are private by default
{
    int m_month {};     // private by default, can only be accessed by other members
    int m_day {};       // private by default, can only be accessed by other members
    int m_year {};      // private by default, can only be accessed by other members

public:
    void setDate(int month, int day, int year) // public, can be accessed by anyone
    {
        // setDate() can access the private members of the class because it is a member of the class itself
        m_month = month;
        m_day = day;
        m_year = year;
    }

    void print() // public, can be accessed by anyone
    {
        std::cout << m_month << '/' << m_day << '/' << m_year;
    }
};


int main()
{
    // Public vs private access specifiers
    // Public and private members

    // we declare a DateStruct and then we directly access its members in order to assign values to them. This works because all members of a struct are public members by default. Public members are members of a struct or class that can be accessed directly by anyone, including from code that exists outside the struct or class. 
    // the public is only allowed to access the public members of a struct or class, which makes sense.
    {
        DateStruct date;
        date.month = 10;
        date.day = 14;
        date.year = 2020;
    }
    // by default, all members of a class are private. Private members are members of a class that can only be accessed by other members of the class (not by the public). Because main() is not a member of DateClass, it does not have access to date’s private members.

    /*
        DateClass1 date;
        date.m_month = 10;  // error
        date.m_day = 14;    // error
        date.m_year = 2020; // error
    */

    // Access specifiers
    // Access specifiers determine who has access to the members that follow the specifier. Each of the members “acquires” the access level of the previous access specifier (or, if none is provided, the default access specifier).
    
    // Although class members are private by default, we can make them public by using the public keyword
    {
        DateClass date;
        date.m_month = 10;      // okay because m_month is public
        date.m_day = 14;        // okay because m_day is public
        date.m_year = 2020;     // okay because m_year is public
        // Because DateClass’s members are now public, they can be accessed directly by main().

        // C++ provides 3 different access specifier keywords: public, private, and protected. Public and private are used to make the members that follow them public members or private members respectively. The third access specifier, protected, works much like private does. We will discuss the difference between the private and protected access specifier when we cover inheritance.
    }

    // Mixing access specifiers
    // In general, member variables are usually made private, and member functions are usually made public.
    {
        DateClass2 date;
        date.setDate(2, 17, 2023); // okay, because setDate() is public
        date.print();               // okay, because print() is public
        std::cout << "\n\n";
    }

    
    // Structs vs classes
    // in C++. A class defaults its members to private. A struct defaults its members to public.
    // structs inherit from other classes publicly and classes inherit privately. We’ll cover later

    return 0;
}