#include "arbitrary_number.hpp"


static int arbitrary_number;


void set_arbitrary_number(int arg)
{
    arbitrary_number = arg;
}


int arbitrary_number_by_value()
{
    return arbitrary_number;
}


const int& arbitrary_number_by_reference()
{
    return arbitrary_number;
}


void do_nothing()
{
}
