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

long long d[505][505];

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++)
    {
        fill(begin(d[i]), end(d[i]), INFLL);
    }
    for(int i = 0; i < m; i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        d[a][b] = min(c, d[a][b]);
        d[b][a] = min(c, d[b][a]);
    }
    for(int i = 1; i <= n; i++)
    {
        d[i][i] = 0ll;
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

