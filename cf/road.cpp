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
#include <stack>

#define ll long long
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define MAXN 100000

using namespace std;

vector<pair<int, int>> adj[105];
int in[105];
int out[105];

int main()
{
    int n;
    cin >> n;

    int totCost = 0;
    for(int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        inGraph[a] = true;
        inGraph[b] = true;
        adj[a].push_back({b, c});

        in[b]++;
        out[a]++;


        totCost += c;
    }

    int changeOut = 0;
    for(int i = 1; i <= 100; i++)
    {
        if(inGraph[i])
        {
            for(auto succ : adj[i])
            {
                changeOut += succ.second;
            }
        }
    }
    return 0;
}

