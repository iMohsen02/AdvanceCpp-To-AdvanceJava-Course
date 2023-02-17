#include <iostream>
#include <climits>
#include <bitset>


int main()
{
    // system("cls");

    short value = SHRT_MAX + 1;
    std::cout << "max num for short is:\t" << SHRT_MAX << '\n';
    std::cout << "min num for short is:\t" << SHRT_MIN << '\n';

    std::cout << "\ndata is: " << (SHRT_MAX + 1) << "\tbut value is: " << value << '\n';

    std::cout << "data is: " << (SHRT_MIN - 1) << "\tbut value is: " << (value = SHRT_MIN - 1) << "\n\n";

    std::cout << "============================================================\n";
    using std::bitset;
    std::cout << "max value is: "  << bitset<4>(0b0111) << " value++: " <<  bitset<4>(7 + 1) << "\n";

    // unsigned
    // 0 0 0 0
    // 2^3 + 2^2 + 2^1 + 2^0

    // signed
    // 1 0 0 0 
    // -2^3 + 2^2 + 2^1 + 2^0
    // => 0111 => 7
    // => 1000 => -8
    return 0;
}