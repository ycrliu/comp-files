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

pair<int, int> task[200005];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> task[i].first >> task[i].second;
    }
    sort(task, task + n);
    long long ans = 0;
    long long t = 0;
    for(int i = 0; i < n; i++)
    {
        t += task[i].first;
        ans += task[i].second - t;
    }
    cout << ans << endl;
    return 0;
}

