#include "random_numbers.hpp"


#include <random>


static int random_number;


static int make_random_number(std::mt19937 &random_engine)
{
    int min = 0;
    int max = 1;
    auto zero_or_one = std::uniform_int_distribution<int>(min,max);
    return zero_or_one(random_engine);
}


void create_random_number()
{
    int seed = 1;
    std::mt19937 random_engine(seed);
    random_number = make_random_number(random_engine);
}



int arbitrary_number_by_value()
{
    return 7;
}


const int& arbitrary_number_by_reference()
{
    return random_number;
}


void do_nothing()
{
}
