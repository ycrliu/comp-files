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

#define ll long long
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define MAXN 100000

using namespace std;

int k, m, n;
pair<int, int> p[200005];
int f[200005];

int lsearch(int cur)
{
    int l = 0, r = m - 1, ans = -1;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(f[mid] <= cur)
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return ans;
}

int rsearch(int cur)
{
    int l = 0, r = m - 1, ans = -1;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(f[mid] >= cur)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}

int main()
{
    cin >> k >> m >> n;
    for(int i = 0; i < k; i++)
    {
        cin >> p[i].first >> p[i].second;
    }
    for(int i = 0; i < m; i++)
    {
        cin >> f[i];
    }
    sort(p, p + k);
    sort(f, f + m);
    int i = k - 1;
    long long ans = 0;

    while(i >= 0 && n > 0)
    {
        int cur = p[i].first;
        int opp_l = lsearch(cur);
        int opp_r = rsearch(cur);
        int opp_i;
        if(opp_l == -1)
        {
            opp_i = opp_r;
        }
        else if(opp_r == -1)
        {
            opp_i = opp_l;
        }
        else
        {
            opp_i = abs(cur - f[opp_l]) < abs(cur - f[opp_r]) ? opp_l : opp_r;
        }
        cout << cur << " " << f[opp_i] << endl;
        while(opp_i >= 0 && i >= 0 && f[opp_i] < cur)
        {
            ans += p[i].second;
            opp_i--;
            i--;
            cur = p[i].first;
        }
        n--;
    }
    cout << ans << endl;
    return 0;
}

