// Demonstrates returning a large object by reference,
// which avoids a copy.

#include <vector>
#include <random>
#include <algorithm>


static int random_number(std::mt19937 &random_engine)
{
    return std::uniform_int_distribution<int>(0,1)(random_engine);
}


namespace {
    class random_numbers {
        public:
            void build(int n)
            {
                std::mt19937 random_engine(1);
                numbers_member.resize(n);

                for (auto &x : numbers_member) {
                    x = random_number(random_engine);
                }
            }

            const std::vector<int> &numbers() const
            {
                return numbers_member;
            }

        private:
            std::vector<int> numbers_member;
    };
}


static int sum_of(const std::vector<int> &numbers)
{
    return std::accumulate(numbers.begin(),numbers.end(),0);
}


int main()
{
    random_numbers r;
    r.build(100000000);
    return sum_of(r.numbers());
}
