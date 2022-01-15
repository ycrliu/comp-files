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

struct dsu
{
    int n;
    vector<int> size, parent;
    dsu(int N) : n(N), size(N), parent(N)
    {}
    void make_set(int v)
    {
        parent[v] = v;
        size[v] = 1;
    }
    int find_set(int v)
    {
        if(v == parent[v])
        {
            return v;
        }
        return parent[v] = find_set(parent[v]);
    }
    void union_sets(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if(a != b)
        {
            if(size[a] < size[b])
            {
                swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];
            size[b] = 0;
        }
    }
};

bool grid[1005][1005];
int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};

int main()
{
    int n, m;
    cin >> n >> m;
    dsu G((n + 1) * (m + 1));
    for(int i = 0; i < n; i++)
    {
        string l;
        cin >> l;
        for(int j = 0; j < m; j++)
        {
            if(l[j] == '.')
            {
                grid[i][j] = true;
                G.make_set(i * m + j);
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j])
            {
                for(int it = 0; it < 4; it++)
                {
                    int ni = i + di[it];
                    int nj = j + dj[it];
                    if(ni < n && ni >= 0 && nj < m && nj >= 0 && grid[ni][nj])
                    {
                        G.union_sets(i * m + j, ni * m + nj);
                    }
                }
            }
        }
    }
    set<int> cs;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(G.size[i * m + j] > 0)
            {
                cs.insert(G.find_set(i * m + j));
            }
        }
    }
    cout << cs.size() << endl;
    return 0;
}

