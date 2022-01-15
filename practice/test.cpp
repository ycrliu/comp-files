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
 
long long adj[505][505];
long long d[505][505];
 
int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++)
    {
        fill(begin(adj[i]), end(adj[i]), INFLL);
    }
    for(int i = 0; i < m; i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        adj[a][b] = min(c, adj[a][b]);
        adj[b][a] = min(c, adj[b][a]);
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(adj[i][j] && i != j) //adj[i][j] always true b/c it's set to inf
            {
                d[i][j] = adj[i][j];
            }
            if(!adj[i][j] && i != j)
            {
                d[i][j] = INFLL;
            }
            if(i == j)
            {
//                cout << d[i][j] << endl;
                d[i][j] = 0;
            }
        }
    }
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
            }
        }
    }
    while(q--)
    {
        int a, b;
        cin >> a >> b;
        cout << (d[a][b] < INFLL ? d[a][b] : -1) << endl;
    }
    return 0;
}
