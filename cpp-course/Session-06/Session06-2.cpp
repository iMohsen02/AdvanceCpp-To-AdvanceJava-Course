#include <iostream>


int main(int argc, char** argv)
{
    // command line arguments
    // you can pass arguments from command line into the program, and can use them.
    // just pass the aguments after typing name of program (file.exe agument1 argument2 argument3 ... )
    // ex: Session06-02.exe hello Cpp Course
    // each word(separated via space) will be stored in array
    // frist argument is the address of executable file, where the program start to run
    std::cout << "start program\n";

    std::cout << "input args are:\t" << argc << '\n';
    for(int i = 0; i < argc; i++)
    {
        std::cout << argv[i] << '\n';
    }

    std::cout << "end program\n";
    return 0;
}