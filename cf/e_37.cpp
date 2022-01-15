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

#define ll long long
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define MAXN 100000

using namespace std;

int n;
set<int> unAdj[200005]; //logn find()
set<int> unVis;

int bfs(int u)
{
    int sz = 1;
    unVis.erase(unVis.find(u));
    queue<int> q;
    q.push(u);
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        vector<int> toErase;
        for(auto it = unVis.begin(); it != unVis.end(); it++)
        {
            int to = *it;
            // check if "to" is in the same connected component as v
            // basically just use logic to get unAdj to produce a similar conditional
            // as a "normal" adj list would
            if(unAdj[v].find(to) == unAdj[v].end())
            {
                toErase.push_back(to);
                sz++;
                q.push(to);
            }
        }
        for(int te : toErase)
        {
            unVis.erase(unVis.find(te));
        }
    }
    return sz;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        unAdj[x].insert(y);
        unAdj[y].insert(x);
    }
    for(int i = 1; i <= n; i++)
    {
        unVis.insert(i);
    }
    int ans = 0;
    vector<int> szs;
    for(int i = 1; i <= n; i++)
    {
        if(unVis.find(i) != unVis.end())
        {
            ans++;
            szs.push_back(bfs(i));
        }
    }
    cout << ans << endl;
    sort(szs.begin(), szs.end());
    for(int sz : szs)
    {
        cout << sz << " ";
    }
    return 0;
}

