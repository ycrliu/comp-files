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

int k[200005];
multiset<int> curMins;

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> k[i];
    }
    for(int i = 0; i < n; i++)
    {
        auto it = curMins.upper_bound(k[i]);
        if(it != curMins.end())
        {
            curMins.erase(it);
        }
        curMins.insert(k[i]);
    }
    cout << curMins.size() << endl;
    return 0;
}

