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
int d[100005];
int p[100005];

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
    memset(d, INF, sizeof(d));
    d[1] = 0;
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v : adj[u])
        {
            if(!vis[v])
            {
                vis[v] = true;
                d[v] = min(1 + d[u], d[v]);
                p[v] = u;
                q.push(v);
            }
        }
    }
    if(vis[n])
    {
        cout << d[n] + 1 << endl;
        vector<int> path;
        for(int v = n; v != 1; v = p[v])
        {
            path.push_back(v);
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        for(int u : path)
        {
            cout << u << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}

