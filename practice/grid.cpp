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

bool grid[1005][1005];
int dp[1005][1005];

void add(int& a, int b)
{
    long long res = a + b;
    if(res >= MOD)
    {
        res -= MOD;
    }
    a = res;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string l;
        cin >> l;
        for(int j = 0; j < n; j++)
        {
            grid[i][j] = l[j] == '.';
        }
    }
    if(grid[0][0])
    {
        dp[0][0] = 1;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(grid[i][j])
            {
                if(j - 1 >= 0)
                {
                    add(dp[i][j], dp[i][j - 1]);
                }
                if(i - 1 >= 0)
                {
                    add(dp[i][j], dp[i - 1][j]);
                }
            }
        }
    }
    cout << dp[n - 1][n - 1] << endl;
    return 0;
}

