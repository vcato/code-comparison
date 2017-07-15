#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>

using std::vector;
using std::cout;
using std::cerr;
using std::ostream;



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


// Namespace for pure functions.  These functions have no observable side-effects and
// the return value only depends on the parameter values.
// Note that these functions are pure, even though they call the impure functions
// like std::copy() and vector::push_back().
namespace pure {
    static vector<int> values_less_than(int pivot,const vector<int> &values)
    {
        vector<int> result;

        for (auto x : values) {
            if (x<pivot) {
                result.push_back(x);
            }
        }

        return result;
    }


    static vector<int> values_equal_to(int pivot,const vector<int> &values)
    {
        vector<int> result;

        for (auto x : values) {
            if (x==pivot) {
                result.push_back(x);
            }
        }

        return result;
    }


    static vector<int> values_greater_than(int pivot,const vector<int> &values)
    {
        vector<int> result;

        for (auto x : values) {
            if (x>pivot) {
                result.push_back(x);
            }
        }

        return result;
    }

    static vector<int> concat(const vector<int> &a,const vector<int> &b)
    {
        vector<int> result(a.size()+b.size());
        std::copy(a.begin(),a.end(),result.begin());
        std::copy(b.begin(),b.end(),result.begin()+a.size());
        return result;
    }


    static vector<int>
        concat(const vector<int> &a,const vector<int> &b,const vector<int> &c)
    {
        return concat(concat(a,b),c);
    }


    static vector<int> mysorted(const vector<int> &values)
    {
        if (values.size()<2) return values;

        size_t middle_index = values.size()/2;
        int pivot = values[middle_index];
        auto lower = mysorted(values_less_than(pivot,values));
        auto middle = values_equal_to(pivot,values);
        auto upper = mysorted(values_greater_than(pivot,values));

        return concat(lower,middle,upper);
    }
}


static void test_mysort(const vector<int> &values,const vector<int> &expected)
{
    assert(pure::mysorted(values)==expected);
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
    cout << pure::mysorted({5,7,3,2,9}) << "\n";
}
