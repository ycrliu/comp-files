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

pair<long long, long long> a[100005];
long long ps[100005];

int main()
{
    int n, d;
    cin >> n >> d;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n);

    for(int i = 0; i < n; i++)
    {
        ps[i] += a[i].second;
        if(i)
        {
            ps[i] += ps[i - 1];
        }
    }

    long long ans = 0;
    for(int i = 0; i < n; i++)
    {
        int lo = 0;
        int hi = n - 1;
        int lim = -1;
        while(lo <= hi)
        {
            int mid = (lo + hi + 1) / 2;
            if(a[mid].first - a[i].first < d)
            {
                lo = mid + 1;
                lim = mid;
            }
            else
            {
                hi = mid - 1;
            }
        }
        long long curSum = ps[lim] - (!i ? 0ll : ps[i - 1]);
        ans = max(curSum, ans);
    }
    cout << ans << endl;
    return 0;
}

