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
#include <unordered_set>

#define ll long long
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define MAXN 100000

using namespace std;

array<int, 2> swp[200005];
vector<int> pathFromStart[100005];
int adj[100005];

int main()
{
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < k; i++)
    {
        cin >> swp[i][0] >> swp[i][1];
    }

    vector<int> name(n + 1);
    for(int i = 1; i <= n; i++)
    {
        name[i] = i;
        pathFromStart[i].push_back(i);
    }
    for(int i = 0; i < k; i++)
    {
        pathFromStart[name[swp[i][0]]].push_back(swp[i][1]);
        pathFromStart[name[swp[i][1]]].push_back(swp[i][0]);
        swap(name[swp[i][0]], name[swp[i][1]]);
    }

    for(int i = 1; i <= n; i++)
    {
        adj[i] = pathFromStart[i].back();
    }

    for(int i = 1; i <= n; i++)
    {
        unordered_set<int> seen;

        int curPos = i;
        seen.insert(curPos);
        for(int node : pathFromStart[i])
        {
            curPos = node;
            seen.insert(curPos);
        }

        while(curPos != i)
        {
            for(int node : pathFromStart[curPos])
            {
                seen.insert(node);
            }
            curPos = adj[curPos];
        }
        cout << seen.size() << endl;
    }

    return 0;
}

