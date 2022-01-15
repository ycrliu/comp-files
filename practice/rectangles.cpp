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

int dp[505][505];
// dp[i][j] = min # of moves to cut ixj rectangle into squares

int main()
{
    int a, b;
    cin >> a >> b;
    memset(dp, INF, sizeof(dp));
    for(int i = 0; i <= a; i++)
    {
        for(int j = 0; j <= b; j++)
        {
            if(i == j)
            {
                dp[i][j] = 0;
            }
            for(int cut = 0; cut <= i; cut++)
            {
                dp[i][j] = min(1 + dp[cut][j] + dp[i - cut][j], dp[i][j]);
            }
            for(int cut = 0; cut <= j; cut++)
            {
                dp[i][j] = min(1 + dp[i][cut] + dp[i][j - cut], dp[i][j]);
            }
        }
    }
    cout << dp[a][b] << endl;
    return 0;
}

