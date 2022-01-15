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
#include <stack>

#define ll long long
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define MAXN 100000

using namespace std;

long long x[5005];
long long dp[5005][5005];
// p1 maximizes score_1 - score_2
// p2 minimizes score_1 - score_2

int main()
{
    int n;
    cin >> n;

    long long tot = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> x[i];
        dp[i][i] = x[i];

        tot += x[i];
    }

    for(int l = n - 1; l >= 0; l--)
    {
        for(int r = l + 1; r < n; r++)
        {
            dp[l][r] = max(x[l] - dp[l + 1][r], x[r] - dp[l][r - 1]);
        }
    }

    // tot = s1 + s2
    // dp = s1 - s2
    // s1 = (s1 + s2 + s1 - s2) / 2
    cout << (tot + dp[0][n - 1]) / 2 << endl;
    return 0;
}

