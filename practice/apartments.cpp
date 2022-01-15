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

int want[200005];
int size[200005];

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> want[i];
    }
    for(int i = 0; i < m; i++)
    {
        cin >> size[i];
    }
    sort(want, want + n);
    sort(size, size + m);
    int i = 0;
    int j = 0;
    int ans = 0;
    while(i < n && j < m)
    {
        if(abs(want[i] - size[j]) <= k)
        {
            ans++;
            i++;
            j++;
        }
        else if(want[i] > size[j])
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    cout << ans << endl;
    return 0;
}

