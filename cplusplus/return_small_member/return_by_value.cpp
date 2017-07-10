// Create a sum of unknown int values that are returned by value.

#include "arbitrary_number.hpp"


static int sum_of_numbers_by_value()
{
    int sum = 0;

    for (int i=0; i!=n_runs; ++i) {
        sum += arbitrary_number_by_value();
        do_nothing();
    }

    return sum;
}


int main()
{
    set_arbitrary_number(1);
    return sum_of_numbers_by_value();
}
