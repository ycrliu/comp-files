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

vector<pair<int, long long>> adj[2505];
long long d[2505];
bool inQ[2505];
int cnt[2505];
int p[2505];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b, x;
        cin >> a >> b >> x;
        adj[a].push_back({b, x});
    }

    fill(begin(d), end(d), -INFLL);
    d[1] = 0ll;
    queue<int> q;
    q.push(1);
    inQ[1] = true;
    cnt[1]++;
    while(!q.empty())
    {
        int v = q.front();
        inQ[v] = false;
        q.pop();
        bool cyc = false;
        for(auto e : adj[v])
        {
            int to = e.first;
            long long len = e.second;
            bool cyc = false;
            if(d[v] + len > d[to])
            {
                d[to] = d[v] + len;
                p[to] = v;
                if(!inQ[to])
                {
                    inQ[to] = true;
                    q.push(to);
                    cnt[to]++;
                    if(cnt[to] > n)
                    {
                        cyc = true;
                        bool ok = true;
                        for(; to != 1; to = p[to])
                        {
                            if(to == n)
                            {
                                ok = false;
                                break;
                            }
//                            cout << "hi";
                        }
                        if(!ok)
                        {
                            cout << -1 << endl;
                            return 0;
                        }
                        break;
                    }
                }
            }
        }
        if(cyc)
        {
            break;
        }
    }
    cout << d[n] << endl;
    return 0;
}

