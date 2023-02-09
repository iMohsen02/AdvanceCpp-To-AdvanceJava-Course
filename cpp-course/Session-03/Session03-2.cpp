#include <iostream>

void doSomething() {
    int* ptr = new int { 55 };
} // pointer destroyed

int main() {

    // Dynamic memory allocation with new and delete

    // The need for dynamic memory allocation
    // C++ supports three basic types of memory allocation
    // 1- Static memory allocation happens for static and global variables. Memory for these types of variables is allocated once when your program is run and persists throughout the life of your program.
    // 2- Automatic memory allocation happens for function parameters and local variables. Memory for these types of variables is allocated when the relevant block is entered, and freed when the block is exited, as many times as necessary.
    // 3- Dynamic memory allocation is the topic of this article.

    // Both static and automatic allocation have two things in common:
    // The size of the variable / array must be known at compile time.
    // Memory allocation and deallocation happens automatically (when the variable is instantiated / destroyed).

    // Most of the time, this is just fine. However, you will come across situations where one or both of these constraints cause problems, usually when dealing with external (user or file) input.
    
    // For example, we may want to use a string to hold someone’s name, but we do not know how long their name is until they enter it. Or we may want to read in a number of records from disk, but we don’t know in advance how many records there are. Or we may be creating a game, with a variable number of monsters (that changes over time as some monsters die and new ones are spawned) trying to kill the player.
    // If we have to declare the size of everything at compile time, the best we can do is try to make a guess the maximum size of variables we’ll need and hope that’s
    // This is a poor solution

    // most normal variables (including fixed arrays) are allocated in a portion of memory called the stack. The amount of stack memory for a program is generally quite small -- Visual Studio defaults the stack size to 1MB. If you exceed this number, stack overflow will result, and the operating system will probably close down the program.
    // int array[1'000'000]; // allocate 1 million integers (probably 4MB of memory)
    std::cout << "Stack Overflow never happen\n\n"; // uncomment top line to stack overflow happens.
    // Being limited to just 1MB of memory would be problematic for many programs, especially those that deal with graphics.

    // ==========================================================================================================================
    // Dynamic memory allocation is a way for running programs to request memory from the operating system when needed. This memory does not come from the program’s limited stack memory -- instead, it is allocated from a much larger pool of memory managed by the operating system called the heap. On modern machines, the heap can be gigabytes in size.

    // Dynamically allocating single variables
    // To allocate a single variable dynamically, we use the scalar (non-array) form of the new operator
    new int; // dynamically allocate an integer (and discard the result)
    // we’re requesting an integer’s worth of memory from the operating system. The new operator creates the object using that memory, and then returns a pointer containing the address of the memory that has been allocated.
    int* ptr = new int; // dynamically allocate an integer and assign the address to ptr so we can access it later
    // We can then perform indirection through the pointer to access the memory
    *ptr = 7; // assign value of 7 to allocated memory

    // How does dynamic memory allocation work?
    // When you dynamically allocate memory, you’re asking the operating system to reserve some of that memory for your program’s use. If it can fulfill this request, it will return the address of that memory to your application. From that point forward, your application can use this memory as it wishes. When your application is done with the memory, it can return the memory back to the operating system to be given to another program.
    // Unlike static or automatic memory, the program itself is responsible for requesting and disposing of dynamically allocated memory.


    // Initializing a dynamically allocated variable
    // When you dynamically allocate a variable, you can also initialize it via direct initialization or uniform initialization

    int* pointer1 = new int(5);   // use direct initialization
    int* pointer2 = new int{ 6 }; // use uniform initialization

    // Deleting single variables
    // When we are done with a dynamically allocated variable, we need to explicitly tell C++ to free the memory for reuse. For single variables, this is done via the scalar (non-array) form of the delete operator

    // assume ptr has previously been allocated with operator new
    delete ptr;    // return the memory pointed to by ptr to the operating system
    ptr = nullptr; // set ptr to be a null pointer

    delete pointer1;
    delete pointer2;
    pointer1 = nullptr;
    pointer2 = nullptr;

    // What does it mean to delete memory?
    // The delete operator does not actually delete anything. It simply returns the memory being pointed to back to the operating system. The operating system is then free to reassign that memory to another application (or to this application again later).
    // Although it looks like we’re deleting a variable, this is not the case! The pointer variable still has the same scope as before, and can be assigned a new value just like any other variable.
    // Note that deleting a pointer that is not pointing to dynamically allocated memory may cause bad things to happen.


    // Dangling pointers
    // C++ does not make any guarantees about what will happen to the contents of deallocated memory, or to the value of the pointer being deleted. In most cases, the memory returned to the operating system will contain the same values it had before it was returned, and the pointer will be left pointing to the now deallocated memory.
    // A pointer that is pointing to deallocated memory is called a dangling pointer. Indirection through- or deleting a dangling pointer will lead to undefined behavior.

    int* intPointer = new int; // dynamiclly allocate an integer
    *intPointer = 25; // oyt a value in that memory location

    delete intPointer; // return the memory to the operating system.  ptr is now a dangling pointer.
    std::cout << "Dangling Pointer: " << *intPointer << "\n\n";  // Indirection through a dangling pointer will cause undefined behavior
    delete intPointer; // trying to deallocate the memory again will also lead to undefined behavior.
    // It is possible that the value at deleted memory address could have changed. It’s also possible the memory could be allocated to another application (or for the operating system’s own usage), and trying to access that memory will cause the operating system to shut the program down.


    // Deallocating memory may create multiple dangling pointers.
    int* ptr3 = new int{  }; // dynamically allocate an integer
    int* otherPtr{ ptr3 }; // otherPtr is now pointed at that same memory location

    delete ptr3; // return the memory to the operating system.  ptr and otherPtr are now dangling pointers.
    ptr3 = nullptr; // ptr is now a nullptr

    // however, otherPtr is still a dangling pointer!
    // try to avoid having multiple pointers point at the same piece of dynamic memory.
    // Set deleted pointers to nullptr unless they are going out of scope immediately afterward.

    // Operator new can fail
    // When requesting memory from the operating system, in rare circumstances, the operating system may not have any memory to grant the request with.
    // By default, if new fails, a bad_alloc exception is thrown. If this exception isn’t properly handled (and it won’t be, since we haven’t covered exceptions or exception handling yet), the program will simply terminate (crash) with an unhandled exception error.
    // In many cases, having new throw an exception (or having your program crash) is undesirable, so there’s an alternate form of new that can be used instead to tell new to return a null pointer if memory can’t be allocated.
    int* value { new (std::nothrow) int{ 0 } }; // value will be set to a null pointer if the integer allocation fails
    if (!value) // handle case where new returned null
    {
        // Do error handling here
        std::cerr << "Could not allocate memory\n";
    }
    delete value;
    value = nullptr;
    // and almost never in a dev environment), it’s common to forget to do this check!

    // Null pointers and dynamic memory allocation
    // If ptr isn't already allocated, allocate it
    if (!ptr)
        ptr = new int;
    // Deleting a null pointer has no effect. Thus, there is no need for the following:
    // if (ptr)  delete ptr;
    // Instead do this
    delete ptr;
    // If ptr is non-null, the dynamically allocated variable will be deleted. If it is null, nothing will happen.


    // Memory leaks
    // Dynamically allocated memory stays allocated until it is explicitly deallocated or until the program ends (and the operating system cleans it up, assuming your operating system does that). However, the pointers used to hold dynamically allocated memory addresses follow the normal scoping rules for local variables. This mismatch can create interesting problems.
    doSomething();
    // This function allocates an integer dynamically, but never frees it using delete. Because pointers variables are just normal variables, when the function ends, ptr will go out of scope. And because ptr is the only variable holding the address of the dynamically allocated integer, when ptr is destroyed there are no more references to the dynamically allocated memory. This means the program has now “lost” the address of the dynamically allocated memory. As a result, this dynamically allocated integer can not be deleted.
    // This is called a memory leak. Memory leaks happen when your program loses the address of some bit of dynamically allocated memory before giving it back to the operating system.
    // When this happens, your program can’t delete the dynamically allocated memory, because it no longer knows where it is. The operating system also can’t use this memory, because that memory is considered to be still in use by your program.
    // Memory leaks eat up free memory while the program is running. Only after your program terminates is the operating system able to clean up and “reclaim” all leaked memory.

    // Although memory leaks can result from a pointer going out of scope, there are other ways that memory leaks can result. For example, a memory leak can occur if a pointer holding the address of the dynamically allocated memory is assigned another value
{
    int number = 20;
    int* ptr4 = new int{}; // allocate memory
    ptr4 = &number; // old address lost, memory leak results
    delete ptr4;
}
{
    // This can be fixed by deleting the pointer before reassigning it:

    int value = 5;
    int* ptr = new int{}; // allocate memory
    delete ptr; // return memory back to operating system
    ptr = &value; // reassign pointer to address of value
}
{
    // it is also possible to get a memory leak via double-allocation
    int* ptr = new int{};
    ptr = new int{}; // old address lost, memory leak results
    delete ptr;
}

    // Conclusion
    // Operators new and delete allow us to dynamically allocate single variables for our programs.
    // Dynamically allocated memory has dynamic duration and will stay allocated until you deallocate it or the program terminates.
    // Be careful not to perform indirection through dangling or null pointers.
}