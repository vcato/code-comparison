// In this version we explicitly qualify all names.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


static int solve(const std::string &a,const std::string &b)
{
    //   HARRY
    //  S00000
    //  A01111
    //  L01111
    //  L01111
    //  Y01112

    int n = a.size();
    int m = b.size();

    std::vector<std::vector<int>> table(n+1,std::vector<int>(m+1,0));

    for (int i=0; i!=n; ++i) {
        for (int j=0; j!=m; ++j) {
            if (a[i]==b[j]) {
                table[i+1][j+1] = table[i][j] + 1;
            }
            else {
                table[i+1][j+1] = std::max(table[i+1][j],table[i][j+1]);
            }
        }
    }

    return table[n][m];
}


int main()
{
    std::string a,b;
    std::cin >> a >> b;
    std::cout << solve(a,b) << "\n";
}
