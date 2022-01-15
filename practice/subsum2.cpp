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

long long ps[200005];

int main()
{
    int n, target;
    cin >> n >> target;

    for(int i = 0; i < n; i++)
    {
        cin >> ps[i];
        if(i)
        {
            ps[i] += ps[i - 1];
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(ps[j] - (!i ? 0 : ps[i - 1]) == target)
            {
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}

