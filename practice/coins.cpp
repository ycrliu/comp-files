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
int coins[105];
int mem[1000005];

int dp[1000005];

int r(int x)
{
    if(x < 0)
    {
        return INF;
    }
    if(x == 0)
    {
        return 0;
    }
    if(mem[x])
    {
        return mem[x];
    }
    int res = INF;
    for(int i = 0; i < n; i++) // don't use for equal loop
    {
        res = min(1 + r(x - coins[i]), res);
    }
    mem[x] = res;
    return res;
}

int main()
{
    int x;
    cin >> n >> x;
    for(int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
//    int ans = r(x);
//    cout << (ans < INF ? ans : -1) << endl;

    memset(dp, INF, sizeof(dp));
    dp[0] = 0;
    for(int i = 1; i <= x; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i - coins[j] >= 0)
            {
                dp[i] = min(1 + dp[i - coins[j]], dp[i]);
            }
        }
    }
    cout << (dp[x] < INF ? dp[x] : -1) << endl;
    return 0;
}

