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

bool b[200005];
vector<int> adj[200005];
bool vis[200005];

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
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int to;
        cin >> to;
        adj[i].push_back(to);
    }

    int comps = 0;
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            dfs(i);
            comps++;
        }
    }

    int on = 0;
    int off = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> b[i];
        on += b[i];
        off += (!b[i]);
    }

    cout << (comps - 1) * 2 + (!on) + (!off) << endl;
    return 0;
}

