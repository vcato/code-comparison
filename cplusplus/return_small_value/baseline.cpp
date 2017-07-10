// Baseline run where we don't actually calculate the sum, but
// we still go through the loop.

#include "arbitrary_number.hpp"


int main()
{
    set_arbitrary_number(1);

    for (int i=0; i!=n_runs; ++i) {
        do_nothing();
    }

    return 0;
}
