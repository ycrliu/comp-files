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

vector<pair<int, int>> adj[MAXN];
int d[MAXN];
int p[MAXN];

// same node can be visited twice; however we only perform a relaxation
// when the distance can be reduced
void sssp(int s)
{
    memset(d, INF, sizeof(d));
    memset(p, -1, sizeof(p));

    dequeue<int> q;
    q.push(s);
    d[s] = 0;
    while(!q.empty())
    {
        int v = q.front();
        q.pop_front();
        for(auto edge : adj[v])
        {
            int to = edge.first, len = edge.second;
            if(d[v] + len < d[to])
            {
                d[to] = d[v] + len;
                p[to] = v;
                if(len == 1)
                {
                    q.push_back(to);
                }
                else
                {
                    q.push_front(to);
                }
            }
        }
    }
}

vector<int> restore_path(int s, int e)
{
    vector<int> path;
    for(int v = e; v != s; v = p[v])
    {
        path.push_back(v);
    }
    path.push_back(s);
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    return 0;
}

