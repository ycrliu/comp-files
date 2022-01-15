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

int dp[1000005];

int main()
{
    string s;
    cin >> s;

    int maxLen = 0;
    int cnt = 0;

    for(int i = 0; i < s.size(); i++)
    {
        maxLen = max(dp[i], maxLen);
    }

    cout << maxLen << " " << count << endl;
    return 0;
}

