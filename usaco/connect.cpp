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

vector<int> adj[100005];
bool vis[100005];

pair<int, int> dfs(int u)
{
    vis[u] = true;
    int minU = u;
    int maxU = u;
    for(int v : adj[u])
    {
        if(!vis[v])
        {
            auto temp = dfs(v);
            minU = min(temp.first, minU);
            maxU = max(temp.second, maxU);
        }
    }
    return {minU, maxU};
}

int sqr(int a)
{
    return a * a;
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
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<pair<int, int>> c;
        for(int i = 1; i <= n; i++)
        {
            if(!vis[i])
            {
                pair<int, int> temp = dfs(i);
                c.push_back({temp.first, temp.second});
            }
        }
        
        if(c.size() == 1)
        {
            cout << 0 << endl;
        }
        else if(c.size() == 2)
        {
            cout << 1 << endl;
        }
        else
        {
//            cout << c.front().second << endl;
//            cout << c[c.size() / 2].first << endl;
//            cout << c[c.size() / 2].second << endl;
//            cout << c.back().first << endl;
            cout << sqr(abs(c.front().second - c[c.size() / 2].first))
                + sqr(abs(c[c.size() / 2].second - c.back().first)) << endl;
        }
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= n; i++)
        {
            adj[i].clear();
        }
    }
    return 0;
}

