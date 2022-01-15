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

vector<int> adj[100005];
bool vis[100005];

int dfs(int u)
{
    vis[u] = true;
    int maxU = u;
    for(int v : adj[u])
    {
        if(!vis[v])
        {
            maxU = max(dfs(v), maxU);
        }
    }
    return maxU;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int i = 1;
        long long ans = 0;
        while(i <= n)
        {
            int j = dfs(i);
            if(j == n)
            {
                break;
            }
            i = j + 1;
            ans++;
        }
        cout << ans << endl;
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= n; i++)
        {
            adj[i].clear();
        }
    }
    return 0;
}

