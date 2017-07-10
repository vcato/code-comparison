// Demonstrates returning a large object by value which
// requires a copy.

#include "random_numbers.hpp"


int main()
{
    int n = 100000;
    buildRandomNumbers(n);

    int sum = 0;

    for (int i=0; i!=n; ++i) {
        sum += randomNumbersByValue()[i];
    }

    return sum;
}
