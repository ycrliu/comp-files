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
    vector<int> parent;
    vector<int> size;

    dsu(int N) : n(N), parent(N), size(N)
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


char s1[100005];
char s2[100005];

int main()
{
    int n;
    cin >> n;

    dsu G(26);
    for(int i = 0; i < n; i++)
    {
        cin >> s1[i];
        G.make_set(s1[i] - 'a');
    }
    for(int i = 0; i < n; i++)
    {
        cin >> s2[i];
        G.make_set(s2[i] - 'a');
    }


    vector<pair<char, char>> ans;
    for(int i = 0; i < n; i++)
    {
        if(G.find_set(s1[i] - 'a') != G.find_set(s2[i] - 'a'))
        {
            G.union_sets(s1[i] - 'a', s2[i] - 'a');
            ans.push_back({s1[i], s2[i]});
        }
    }

    cout << ans.size() << endl;
    for(auto an : ans)
    {
        cout << an.first << " " << an.second << endl;
    }
    return 0;
}

