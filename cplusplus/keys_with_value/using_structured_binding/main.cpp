#include <cassert>
#include <vector>
#include <map>
#include <string>
#include <set>

using std::vector;
using std::set;
using std::map;
using std::string;


template <typename Key,typename Value>
static vector<Key>
keys_with_value(map<Key,Value> &map,const Value &value_to_find)
{
    vector<Key> found_keys;

    for (auto& [key,value] : map) {
        if (value==value_to_find) {
            found_keys.push_back(key);
        }
    }

    return found_keys;
}


template <typename T>
static set<T> set_of(const vector<T> &v)
{
    return set<T>(v.begin(),v.end());
}


int main()
{
    map<string,int> days_in_month = {
        {"Januray",  31},
        {"February", 28},
        {"March",    31},
        {"April",    30},
        {"May",      31},
        {"June",     30},
        {"July",     31},
        {"August",   31},
        {"September",30},
        {"October",  31},
        {"November", 30},
        {"December", 31},
    };

    vector<string> months_with_30_days = keys_with_value(days_in_month,30);
    vector<string> expected_months = {{"September","April","June","November"}};

    assert(set_of(months_with_30_days)==set_of(expected_months));
}
