#include <iostream>
#include <bitset>


using std::cout;
using std::bitset;

int main() 
{
    system("cls & color B");

    
    const int len = 7;
    int number = 7;
    cout << "number is: " << number <<  "\tbin: "<< bitset<7>(number) << '\n';
    for (int i = 0; i < len; i++)
    {
        // cout << "i = " << i << "\t" << bitset<len>(1 << i) << '\n';
        if ((number & (1 << i)) != 0)
        {
            cout << "bit i exists: " << i << "\t(1 << i) = " << bitset<7>((1 << i))<<'\n'; 
        }
    }


    cout << "========================================================================\n\n";
    // =============================================================================
    int array[] = {2 , 4};
    // 00 => 0
    // 01 => 1
    // 10 => 2
    // 11 => 3

    int num = 0;
    for (int i = 0; i < 4; i++) 
    {
        cout << bitset<2>(num) << " => " << num << "\n\tsubset: ";

        for(int j = 0; j < 2; j++)
        {
            if ((num & (1 << j)) != 0)
            {
                cout << "\t" << array[j];
            }
        }
        cout << '\n';
        num++;
    }

    return 0;
}