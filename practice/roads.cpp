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

void dfs(int u)
{
    vis[u] = true;
    for(int v : adj[u])
    {
        if(!vis[v])
        {
            dfs(v);
        }
    }
}

int main()
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
    int c = 0;
    vector<int> r;
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            dfs(i);
            c++;
            r.push_back(i);
        }
    }
    cout << c - 1 << endl;
    for(int i = 0; i < r.size() - 1; i++)
    {
        cout << r[i] << " " << r[i + 1] << endl;
    }
    return 0;
}

