#include "random_numbers.hpp"

#include <random>


static std::vector<int> global_numbers;


static int random_number(std::mt19937 &random_engine)
{
    return std::uniform_int_distribution<int>(0,1)(random_engine);
}


void buildRandomNumbers(int n)
{
    std::mt19937 random_engine(1);
    global_numbers.resize(n);

    for (auto &x : global_numbers) {
        x = random_number(random_engine);
    }
}


const std::vector<int> &randomNumbers()
{
    return global_numbers;
}
