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

int dp[1005][100005];
int price[1005];
int pages[1005];
// dp[i][j] = max number of pages from the first i books using j dollars
// 😃

int main()
{
    int n, x;
    cin >> n >> x;
    for(int i = 1; i <= n; i++)
    {
        cin >> price[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> pages[i];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= x; j++)
        {
            // option 1: don't buy the current book
            dp[i][j] = dp[i - 1][j];
            // compare to option 2: buying the current book
            // which choice produces a greater answer?
            if(j - price[i] >= 0)
            {
                dp[i][j] = max(dp[i - 1][j - price[i]] + pages[i], dp[i][j]);
            }
        }
    }
    cout << dp[n][x] << endl;
    return 0;
}

