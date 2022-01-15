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

long long dp[200005][2];

void solve()
{
    int n;
    long long a, b;
    string s;
    cin >> n >> a >> b >> s;

    memset(dp, INF, sizeof(dp));
    dp[0][0] = b;

    for(int i = 1; i <= n; i++)
    {
        if(s[i - 1] == '1')
        {
            dp[i][1] = dp[i - 1][1] + a + 2 * b;
        }
        else
        {
            dp[i][0] = min(dp[i - 1][0] + a + b, dp[i - 1][1] + 2 * a + b);
            dp[i][1] = min(dp[i - 1][0] + 2 * (a + b), dp[i - 1][1] + a + 2 * b);
        }
    }

    cout << dp[n][0] << endl;

    memset(dp, 0, sizeof(dp));
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}

