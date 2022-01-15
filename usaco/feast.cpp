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

int t, a, b;
int mem[5000005][2];

int recur(int cur, int drank)
{
    if(cur == t)
    {
        return t;
    }
    if(mem[cur][drank])
    {
        return mem[cur][drank];
    }
    int res = cur;
    if(cur + a <= t)
    {
        res = max(recur(cur + a, drank), res);
    }
    if(cur + b <= t)
    {
        res = max(recur(cur + b, drank), res);
    }
    if(!drank)
    {
        res = max(recur(cur / 2, 1), res);
    }
    mem[cur][drank] = res;
    return res;
}

int main()
{
    ifstream cin("feast.in");
    ofstream cout("feast.out");
    cin >> t >> a >> b;
    cout << recur(0, 0) << endl;
    return 0;
}

