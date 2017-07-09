// Create a sum of unknown int values that are returned by value.

#include "random_numbers.hpp"


static int sum_of_numbers_by_value(int n)
{
    int sum = 0;

    for (int i=0; i!=n; ++i) {
        sum += arbitrary_number_by_value();
        do_nothing();
    }

    return sum;
}


int main()
{
    int n = 100000000;
    create_random_number();
    return sum_of_numbers_by_value(n);
}
