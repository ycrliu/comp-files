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

int x[200005];
map<int, int> ind_of;

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> x[i];
        ind_of[x[i]] = i;
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(ind_of[x[i] + 1] < i)
        {
            ans++;
        }
    }
    cout << ans + 1 << endl;
    return 0;
}

