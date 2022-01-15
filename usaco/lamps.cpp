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

bool before[100 + 1];
bool after[100 + 1];

int main()
{
    if(fopen("lamps.in", "r"))
    {
        freopen("lamps.in", "r", stdin);
        freopen("lamps.out", "w", stdout);
    }
    int n, c;
    cin >> n >> c;

    fill(begin(before), end(before), 1);

    vector<int> on, off;

    int in;
    cin >> in;
    while(in != -1)
    {
        on.push_back(in);
        cin >> in;
    }
    cin >> in;
    while(in != -1)
    {
        off.push_back(in);
        cin >> in;
    }


    return 0;
}

