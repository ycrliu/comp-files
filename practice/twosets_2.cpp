#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <algorithm>
#include <utility>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <numeric>
#include <cassert>

#define ll long long
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define MAXN 100000

using namespace std;

int dp[505][125255];
// dp[i][j] = number of ways to construct j using first i numbers

int main()
{
    int n;
    cin >> n;

    // two subsets of equal sum: each must sum to half the total sum
    int sm = n * (n + 1) / 2;
    if(sm % 2 == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    
    for(int i = 1; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    // the second set of numbers is irrelevant; 1 successful way to get sm/2 in
    // set1 guarantees a successful set2 that sums to sm/2
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= sm / 2; j++)
        {
            // don't take the current number
            dp[i][j] += dp[i - 1][j];

            // take the current number
            if(j - i >= 0)
            {
                dp[i][j] += dp[i - 1][j - i];
            }
            dp[i][j] %= MOD;
        }
    }
    
    cout << dp[n][sm / 2] << endl;
    return 0;
}
