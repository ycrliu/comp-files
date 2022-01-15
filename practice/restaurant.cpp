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

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> events(2 * n);
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        events[2 * i] = {a, 1};
        events[2 * i + 1] = {b, -1};
    }
    sort(events.begin(), events.end());
    int ans = 0;
    int cur = 0;
    for(int i = 0; i < 2 * n; i++)
    {
        cur += events[i].second;
        ans = max(cur, ans);
    }
    cout << ans << endl;
    return 0;
}

