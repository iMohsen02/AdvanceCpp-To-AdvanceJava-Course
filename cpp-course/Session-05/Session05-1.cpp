#include <iostream>

void printValue(std::string& str) { // type changed to std::string&
    std::cout << str << '\n';
} // str is destroyed here

void addOneToCopy(int x) { x++; }
void addOneToRefrence(int& x) { x++; }

void printConstRef(const int& x) {
    std::cout << x << '\n';
    // x++; // it is not allowed because of const refrence
}

int main() {

    // Pass by reference
    // Some objects are expensive to copy. Class types are usually expensive to copy. 
    // One way to avoid making an expensive copy of an argument when calling a function is to use pass by reference instead of pass by value. When using pass by reference, we declare a function parameter as a reference type (or const reference type) rather than as a normal type. When the function is called, each reference parameter is bound to the appropriate argument. Because the reference acts as an alias for the argument, no copy of the argument is made.



    // Pass by reference allows us to change the value of an argument
    // When an object is passed by value, the function parameter receives a copy of the argument. This means that any changes to the value of the parameter are made to the copy of the argument, not the argument itself:
    // However, since a reference acts identically to the object being referenced, when using pass by reference, any changes made to the reference parameter will affect the argument
    int x = 5;
    std::cout << "x is:\t" << x << '\n';
    addOneToCopy(x);
    std::cout << "x is:\t" << x << '\n';

    addOneToCopy(x);
    std::cout << "x is:\t" << x << "\n\n";

    

    // Pass by reference to non-const can only accept modifiable arguments
    // Pass by const reference
    // Unlike a reference to non-const (which can only bind to modifiable value). if we make our reference parameter const, then it will be able to bind to any type of argument
    int value { 6 };
    printConstRef(value);      // guarantee that value never will be changed

    const int constValue { 20 };
    printConstRef(constValue); // const value also can passed to function

    // You can also mix pass by value and pass by reference


    // We can now answer the question of why we don’t pass everything by reference:
    //     - For objects that are cheap to copy, the cost of copying is similar to the cost of binding, so we favor pass by value so the code generated will be faster.
    //     - For objects that are expensive to copy, the cost of the copy dominates, so we favor pass by (const) reference to avoid making a copy.
    return 0;
}