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

int n;
long long x[5005];
long long dp[5005][5005][2];

long long recur(int l, int r, int curPlayer)
{
    if(l > r || l >= n || r < 0)
    {
        return 0;
    }
    if(dp[l][r][curPlayer])
    {
        return dp[l][r][curPlayer];
    }

    if(curPlayer == 1)
    {
        return dp[l][r][curPlayer] = max(x[l] + recur(l + 1, r, 3 - curPlayer),
                x[r] + recur(l, r - 1, 3 - curPlayer));
    }
    else
    {
        return dp[l][r][curPlayer] = min(recur(l + 1, r, 3 - curPlayer),
                recur(l, r - 1, 3 - curPlayer));
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    cout << max(recur(0, n - 1, 1), recur(0, n - 1, 2)) << endl;
    return 0;
}

