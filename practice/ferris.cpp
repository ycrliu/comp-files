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

int w[200005];

int main()
{
    int n, max_w;
    cin >> n >> max_w;
    for(int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    sort(w, w + n);
    int l = 0;
    int r = n - 1;
    int ans = 0;
    while(l <= r)
    {
        int cur = w[r];
        if(w[l] + cur <= max_w)
        {
            // best option
            ans++;
            l++;
            r--;
        }
        else
        {
            // only way to reduce size is decrease right pointer
            r--;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
