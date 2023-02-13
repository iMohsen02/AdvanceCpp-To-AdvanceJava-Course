#include <iostream>

int* getArrayInputs(int array_len);
void printArray(int* array, int array_len);

int main()
{
    using std::cin;
    using std::cout;


    int len;
    cout << "please enter len of array:\t";
    cin >> len;

    int* array = getArrayInputs(len);
    printArray(array, len);
    
    delete[] array;

    
    return 0;
}

int* getArrayInputs(int array_len)
{

    int* array = new int[array_len];
    for(int i = 0; i < array_len; i++)
    {
        std::cin >> *(array + i);
    }

    return array;
}

void printArray(int* array, int array_len) 
{
    std::cout << "{ ";
    for(int i = 0; i < array_len; i++)
        std::cout << *(array + i) << ", ";
    std::cout << "\b\b }";
}