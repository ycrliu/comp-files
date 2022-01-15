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

int c[105];
int n;
int dp[105][1000005]; // dp[i][j] = number of ways to form j using first i coins

void add(int& a, int b)
{
    long long res = a + b;
    if(res >= MOD)
    {
        res -= MOD;
    }
    a = res;
}

//int mem[105][1000005];
//bool ready[105][1000005];
//
//int recur(int x, int i)
//{
//    if(x == 0)
//    {
//        return 1;
//    }
//    if(ready[i][x])
//    {
//        return mem[i][x];
//    }
//    int res = 0;
//    if(x - c[i] >= 0)
//    {
//        add(res, recur(x - c[i], i));
//    }
//    if(i - 1 > 0)
//    {
//        add(res, recur(x, i - 1));
//    }
//    ready[i][x] = true;
//    mem[i][x] = res;
//    return res;
//}

int main()
{
    int x;
    cin >> n >> x;
    for(int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    for(int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= x; j++)
        {
            // don't use the i-th coin
            if(i - 1 > 0)
            {
                add(dp[i][j], dp[i - 1][j]);
            }
            if(j - c[i] >= 0)
            {
                // the remaining subtask is dp[i - c[j]][j], NOT dp[i - c[j]][j - 1]
                // because we are allowed to REPEAT coins
                add(dp[i][j], dp[i][j - c[i]]);
            }
        }
    }
    cout << dp[n][x] << endl;
//    cout << recur(x, n) << endl;
    return 0;
}

