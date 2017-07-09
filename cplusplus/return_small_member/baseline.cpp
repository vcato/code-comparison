// Baseline run where we don't actually calculate the sum, but
// we still go through the loop.

#include "random_numbers.hpp"


static int empty_loop(int n)
{
    int sum = 0;

    for (int i=0; i!=n; ++i) {
        do_nothing();
    }

    return sum;
}


int main()
{
    int n = 100000000;
    create_random_number();
    return empty_loop(n);
}
