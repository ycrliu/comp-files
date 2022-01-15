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

int song[200005];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> song[i];
    }
    int ans = 0;
    map<int, bool> vis;
    for(int l = 0, r = 0; l < n; l++)
    {
        while(r < n && !vis[song[r]])
        {
            vis[song[r]] = true;
            r++;
        }
        ans = max(r - l, ans);
        vis[song[l]] = false;
    }
    cout << ans << endl;
    return 0;
}

