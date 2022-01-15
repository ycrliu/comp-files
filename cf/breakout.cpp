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

void solve()
{
    int n;
    cin >> n;

    int lx = -MAXN;
    int rx = MAXN;
    int ly = -MAXN;
    int uy = MAXN;
    for(int i = 0; i < n; i++)
    {
        int cx, cy;
        cin >> cx >> cy;

        bool left, up, right, down;
        cin >> left >> up >> right >> down;

        if(!left)
        {
            lx = max(cx, lx);
        }
        if(!right)
        {
            rx = min(cx, rx);
        }
        if(!down)
        {
            ly = max(cy, ly);
        }
        if(!up)
        {
            uy = min(cy, uy);
        }

    }
    if(lx <= rx && ly <= uy)
    {
        cout << 1 << " " << min(lx, rx) << " " << max(ly, uy) << endl;
    }
    else
    {
        cout << 0 << endl;
    }
}

int main()
{
    int q;
    cin >> q;
    while(q--)
    {
        solve();
    }
    return 0;
}

