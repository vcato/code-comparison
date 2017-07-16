// In this example, we use using declarations.  This minimizes the
// amount of qualification in the main code.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::cerr;
using std::string;
using std::vector;
using std::max;


static int solve(const string &a,const string &b)
{
    //   HARRY
    //  S00000
    //  A01111
    //  L01111
    //  L01111
    //  Y01112

    size_t n = a.size();
    size_t m = b.size();

    vector<vector<int>> table(n+1,vector<int>(m+1,0));

    for (size_t i=0; i!=n; ++i) {
        for (size_t j=0; j!=m; ++j) {
            if (a[i]==b[j]) {
                table[i+1][j+1] = table[i][j] + 1;
            }
            else {
                table[i+1][j+1] = max(table[i+1][j],table[i][j+1]);
            }
        }
    }

    return table[n][m];
}


int main()
{
    string a,b;
    cin >> a >> b;
    cout << solve(a,b) << "\n";
}
