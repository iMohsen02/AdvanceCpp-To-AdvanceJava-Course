#include <iostream>

int* getArrayInputs(int array_len);
void printArray(int* array, int array_len);
void sortArray(int* array, int array_len);

int main()
{
    using std::cin;
    using std::cout;


    int len;
    cout << "please enter len of array:\t";
    cin >> len;

    int* array = getArrayInputs(len);
    sortArray(array, len);
    printArray(array, len);
    
    delete[] array;

    
    return 0;
}

int* getArrayInputs(int array_len)
{

    std::cout << "please enter " << array_len << " element:\n";

    int* array = new int[array_len];
    for(int i = 0; i < array_len; i++)
    {
        std::cin >> *(array + i);
    }

    return array;
}

void printArray(int* array, int array_len) 
{
    std::cout << "array { ";
    for(int i = 0; i < array_len; i++)
        std::cout << *(array + i) << ", ";
    std::cout << "\b\b }";
}

void sortArray(int* array, int array_len)
{
    for(int i = 0; i < array_len; i++) 
    {
        for (int j = i + 1; j < array_len; j++)
            {
                if (*(array + i) > *(array + j))
                {
                    // swap
                    *(array + i) ^= *(array + j);
                    *(array + j) ^= *(array + i);
                    *(array + i) ^= *(array + j);
                }
            }
    }
}