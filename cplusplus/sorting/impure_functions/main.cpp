#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>

using std::vector;
using std::cout;
using std::cerr;
using std::ostream;
using iter = vector<int>::iterator;


static ostream& operator<<(ostream& stream,const vector<int> &values)
{
    stream << "[";
    bool first = true;

    for (const auto x : values) {
        if (!first) {
            stream << ",";
        }
        else {
            first = false;
        }
        stream << x;
    }

    stream << "]";
    return stream;
}


static iter get_values_less_than(int pivot,iter range_start,iter range_end)
{
    iter read_iter = range_start;
    iter write_iter = range_start;

    while (read_iter != range_end) {
        if (*read_iter < pivot) {
            std::swap(*write_iter,*read_iter);
            ++write_iter;
        }
        ++read_iter;
    }

    return write_iter;
}


static iter get_values_equal_to(int pivot,iter range_start,iter range_end)
{
    iter read_iter = range_start;
    iter write_iter = range_start;

    while (read_iter != range_end) {
        if (*read_iter == pivot) {
            std::swap(*write_iter,*read_iter);
            ++write_iter;
        }
        ++read_iter;
    }

    return write_iter;
}


static void mysort_range(iter range_begin,iter range_end)
{
    if (range_end-range_begin<2) return;

    int pivot = *(range_begin + (range_end-range_begin)/2);

    iter equal_begin = get_values_less_than(pivot,range_begin,range_end);
    iter equal_end = get_values_equal_to(pivot,equal_begin,range_end);

    iter lower_begin = range_begin;
    iter lower_end = equal_begin;

    iter upper_begin = equal_end;
    iter upper_end = range_end;

    mysort_range(lower_begin,lower_end);
    mysort_range(upper_begin,upper_end);
}


static void test_mysort(const vector<int> &values,const vector<int> &expected)
{
    vector<int> sorted_values = values;
    mysort_range(sorted_values.begin(),sorted_values.end());
    assert(sorted_values==expected);
}


static void run_tests()
{
    test_mysort({},{});
    test_mysort({1},{1});
    test_mysort({1,2},{1,2});
    test_mysort({2,1},{1,2});
    test_mysort({1,2,3},{1,2,3});
    test_mysort({1,3,2},{1,2,3});
}


int main()
{
    run_tests();

    vector<int> sorted_values = {5,7,3,2,9};
    mysort_range(sorted_values.begin(),sorted_values.end());
    cout << sorted_values << "\n";
}
