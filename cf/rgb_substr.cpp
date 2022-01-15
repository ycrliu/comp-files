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

int dp[200005][3];
int dp1[200005];

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    memset(dp1, INF, sizeof(dp1));
    
    for(int i = 1; i + k <= n; i++)
    {
        for(int j = 0; j < k; j++)
        {
            for(int cs = 0; cs < 3; cs++)
            {
                for(int c = 0; c < 3; c++)
                {
                    if(c != cs)
                    {
                        dp[i][cs] += dp[i - 1][c];
                    }
                }
                dp1[i] = min(dp[i][cs], dp1[i]);
            }
        }
    }

    cout << dp1[n] << endl;
}

int main()
{
    int q;
    cin >> q;
    while(q--)
    {
        solve();
    }
    return 0;
}

