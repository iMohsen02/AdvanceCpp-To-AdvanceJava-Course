#include <iostream>

class Simple
{
private:
    int m_id;

public:
    Simple(int id)
    {
        m_id = id;
    }

    void setID(int id) { m_id = id; }
    int getID() { return m_id; }
};

class Something
{
private:
    int data;

public:
    Something(int data)
    {
        this->data = data; // this->data is the member, data is the local parameter
    }
};


int main()
{
    // The hidden “this” pointer
    // One of the questions about classes that new object-oriented programmers often ask is, “When a member function is called, how does C++ keep track of which object it was called on?”. The answer is that C++ utilizes a hidden pointer named “this”!

    Simple simple(1);
    Simple simple2(2);
    simple.setID(2);
    std::cout << simple.getID() << "\n\n";
    // Somehow, when we call simple.setID(2);, C++ knows that function setID() should operate on object simple, and that m_id actually refers to simple.m_id. 

    // simple.setID(2);    Although the call to function setID() looks like it only has one argument, it actually has two! When compiled, the compiler converts simple.setID(2); into the: setID(&simple, 2); // note that simple has been changed from an object prefix to a function argument!          
    // simple.setID(2);     =>      setID(&simple, 2);
    // Note that this is now just a standard function call, and the object simple (which was formerly an object prefix) is now passed by address as an argument to the function.

    // what is -> ???
    // inestead of using (*pointer).something, use: pointer->something
    // Simple* s = new Simple(2);
    // (*s).setID(4); // s->setID(4);

    // But that’s only half of the answer. Since the function call now has an added argument, the member function definition needs to be modified to accept (and use) this argument as a parameter.
    // void setID(int id) { m_id = id; }    =>     void setID(Simple* const this, int id) { this->m_id = id; }

    // When the compiler compiles a normal member function, it implicitly adds a new parameter to the function named “this”. The this pointer is a hidden const pointer that holds the address of the object the member function was called on.
    // There’s just one more detail to take care of. Inside the member function, This is easily done by adding a “this->” prefix to each of them. Thus, in the body of function setID(), m_id (which is a class member variable) has been converted to this->m_id. Thus, when “this” points to the address of simple, this->m_id will resolve to simple.m_id.


    // Putting it all together:
    //     1) When we call simple.setID(2), the compiler actually calls setID(&simple, 2).
    //     2) Inside setID(), the “this” pointer holds the address of object simple.
    //     3) Any member variables inside setID() are prefixed with “this->”. So when we say m_id = id, the compiler is actually executing this->m_id = id, which in this case updates simple.m_id to id.


    // The good news is that all of this happens automatically, and it doesn’t really matter whether you remember how it works or not. All you need to remember is that all normal member functions have a “this” pointer that refers to the object the function was called on.

    
    // Explicitly referencing “this”
    // if you have a constructor (or member function) that has a parameter with the same name as a member variable, you can disambiguate them by using “this”
    Something something(2);

    return 0;
}