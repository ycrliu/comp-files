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

int dp[5005][5005];
// Let dp[i][j] be the edit distance between a[:i] and b[:j]
// Then dp[i][j] = min({dp[i - 1][j - 1] + cost(i, j),
//                      dp[i][j - 1] + 1, // insert character into a
//                      dp[i - 1][j] + 1  // remove characte from a
//                      })

int main()
{
    string a, b;
    cin >> a >> b;

    memset(dp, INF, sizeof(dp));

    for(int i = 0; i <= a.size(); i++)
    {
        dp[i][0] = i;
    }
    for(int i = 0; i <= b.size(); i++)
    {
        dp[0][i] = i;
    }
    for(int i = 1; i <= a.size(); i++)
    {
        for(int j = 1; j <= b.size(); j++)
        {
            dp[i][j] = min({dp[i - 1][j - 1] + (a[i - 1] != b[j - 1]),
                            dp[i][j - 1] + 1,
                            dp[i - 1][j] + 1});
        }
    }
    cout << dp[a.size()][b.size()] << endl;
    return 0;
}

