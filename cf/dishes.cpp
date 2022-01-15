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

int dish[20];
int adj[20][20];
long long dp[(1 << 19)][20];

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 0; i < n; i++)
    {
        cin >> dish[i];
    }
    for(int i = 0; i < k; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        adj[x][y] = c;
    }

    for(int i = 0; i < m; i++)
    {
        for(int s = 0; s < (1 << n); s++)
        {
            for(int j = 0; j < n; j++)
            {
                dp[s][i] = dp[s][i - 1];

                if((s & (1 << j)) > 0)
                {
                    dp[s][i] = max(dish[j] + dp[s ^ (1 << j)][i - 1], dp[s][i]);
                }
            }
        }
    }

    cout << dp[(1 << n) - 1][m - 1] << endl;

    return 0;
}

