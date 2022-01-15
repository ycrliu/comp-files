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

struct p
{
    long long start, finish, reward;

    p()
    {}

    p(long long a, long long b, long long w) : start(a), finish(b), reward(w)
    {}
};

int n;
p ps[200005];
long long dp[200005];

long long recur(int i)
{
    if(i < 0 || i >= n)
    {
        return 0ll;
    }

    if(dp[i])
    {
        return dp[i];
    }

    int nextProj = -1;
    int lo = i, hi = n - 1;
    while(lo <= hi)
    {
        int mid = (lo + hi) / 2;

        if(ps[mid].start > ps[i].finish)
        {
            nextProj = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    return dp[i] = max(ps[i].reward + recur(nextProj), recur(i + 1));
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        ps[i] = p(a, b, w);
    }

    sort(ps, ps + n, [](const p& p1, const p& p2) { return p1.start < p2.start; });

    cout << recur(0) << endl;

    return 0;
}

