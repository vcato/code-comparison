// Demonstrates returning a large object by reference,
// which avoids a copy.

#include "random_numbers.hpp"


int main()
{
    int n = 100000;
    buildRandomNumbers(n);

    int sum = 0;

    for (int i=0; i!=n; ++i) {
        sum += randomNumbersByReference()[i];
    }

    return sum;
}
