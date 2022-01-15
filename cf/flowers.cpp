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

long long dp[100005];
long long psum[100005];

int main()
{
    int t, k;
    cin >> t >> k;

    dp[0] = 1ll;
    psum[0] = 1ll;

    for(int i = 1; i <= 100000; i++)
    {
        dp[i] += dp[i - 1];
        dp[i] %= MOD;

        if(i - k >= 0)
        {
            dp[i] += dp[i - k];
            dp[i] %= MOD;
        }

        psum[i] = dp[i] + psum[i - 1];
    }

    while(t--)
    {
        int a, b;
        cin >> a >> b;

        cout << (psum[b] - psum[a - 1]) % MOD << endl;

    }

    return 0;
}

