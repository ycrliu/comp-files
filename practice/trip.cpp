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
int vis[100005];
int p[100005];

void dfs(int u)
{
    vis[u] = true;
    for(int v : adj[u])
    {
        if(!vis[v])
        {
            p[v] = u;
            dfs(v);
        }
        else if(vis[v] && v != p[u])
        {
            vector<int> path;
            path.push_back(v);
            for(; u != v; u = p[u])
            {
                path.push_back(u);
            }
            path.push_back(v);
            cout << path.size() << endl;
            for(int i = path.size() - 1; i >= 0; i--)
            {
                cout << path[i] << " ";
            }
            cout << endl;
            exit(0);
        }
    }
}

int main()
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
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}

