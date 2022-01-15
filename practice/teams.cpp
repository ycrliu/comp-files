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
int col[100005];

bool dfs(int u, int c)
{
    col[u] = c;
    bool ok = true;
    for(int v : adj[u])
    {
        if(!col[v])
        {
            ok &= dfs(v, 3 - c);
        }
        else if(col[v] == c)
        {
            return false;
        }
    }
    return ok;
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
        if(!col[i])
        {
            if(!dfs(i, 1))
            {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        cout << col[i] << " ";
    }
    cout << endl;
    return 0;
}

