/*
ID: robertl8
LANG: C++11
PROB: subset
*/
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

int dp[39 * (39 + 1) / 2 + 1][39 + 5];

int main()
{
    ifstream cin("subset.in");
    ofstream cout("subset.out");
    int n;
    cin >> n;

    int sm = n * (n + 1) / 2;

    if(sm % 2 == 1)
    {
        cout << 0 << endl;
        return 0;
    }
//    for(int i = 1; i <= n; i++)
//    {
//        dp[i][i] = 1;
//    }
    
    for(int i = 1; i <= n; i++)
    {
        dp[0][i] = 1;
    }
    
    for(int i = 1; i <= sm / 2; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i][j - 1];

            if(i - j >= 0)
            {
                dp[i][j] += dp[i - j][j - 1];
            }
        }
    }

    cout << dp[sm / 2][n] << endl;

    return 0;
}

