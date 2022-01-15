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

int n, k;
long long a[200005];

bool enoughOps(long long med)
{
    long long opsNeeded = 0;
    for(int i = n / 2; i < n; i++)
    {
        opsNeeded += max(0ll, med - a[i]);
        if(opsNeeded > k)
        {
            break;
        }
    }
    return opsNeeded <= k;
}

int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    long long l = 1;
    long long r = 2e9;
    long long maxMed = -1;
    while(l <= r)
    {
        long long med = l + (r - l) / 2;
        if(enoughOps(med))
        {
            maxMed = med;
            l = med + 1;
        }
        else
        {
            r = med - 1;
        }
    }
    cout << maxMed << endl;
    return 0;
}

