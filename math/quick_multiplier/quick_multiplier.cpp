#include <iostream>

// Quick Multiplier is only used for integer multiplication.
// This version not use multiply operator and divide operator.
int quick_multiplier(int multiplier, int multiplicand)
{
    int result = 0;
    while (multiplicand > 0) {
        if ((multiplicand & 1) == 1) {
            result += multiplier;
        }
        // k >>= 1 is the same as k = k / 2
        multiplicand >>= 1;
        // Because k right shift 1 bit, a need to be added to itself(a * 2).
        multiplier += multiplier;
    }
    return result;
}

int main()
{
    int a = 12837;
    int b = 52;
    int result = quick_multiplier(a, b);
    std::cout << "result: " << result << std::endl;
    return 0;
}