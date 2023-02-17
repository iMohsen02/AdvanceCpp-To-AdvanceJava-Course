#include<iostream>

int main()
{

    int** array = new int*[50];
    int counter = 0;

    for(int i = 0; i < 10; i++)
        array[i] = new int[5] {counter++, counter++, counter++, counter++, counter++};


    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 5; j++)
        {
            std::cout << array[i][j] << '\t';
        }
        std::cout << '\n';
    }

    for(int i = 0; i < 10; i++)
        delete[] array[i];
    delete[] array;



    return 0;
}