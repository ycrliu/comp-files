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
#include <stack>

#define ll long long
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define MAXN 100000

using namespace std;

struct event
{
    int time;
    int delta;
    int id;

    event()
    {}

    event(int t, int d, int pos) : time(t), delta(d), id(pos)
    {}
};

event es[400005];
int roomOf[200005];

int main()
{
    int n;
    cin >> n;

    stack<int> available;

    for(int i = 0; i < n; i++)
    {
        int s, f;
        cin >> s >> f;

        es[2 * i] = event(s, 1, i);
        es[2 * i + 1] = event(f, -1, i);

        available.push(n - i);
    }

    sort(es, es + 2 * n, [](const event& e1, const event& e2)
            { return e1.time == e2.time ? e1.delta == 1 : e1.time < e2.time; });

    int cur = 0;
    int ans = 0;

    map<int, int> occupied;
    for(int i = 0; i < 2 * n; i++)
    {
        cur += es[i].delta;
        if(es[i].delta == 1)
        {
            occupied[es[i].id] = available.top();
            roomOf[es[i].id] = available.top();
            available.pop();
        }
        else
        {
            available.push(occupied[es[i].id]);
            occupied[es[i].id] = 0;
        }
        ans = max(cur, ans);
    }

    cout << ans << endl;

    for(int i = 0; i < n; i++)
    {
        cout << roomOf[i] << " ";
    }
    cout << endl;

    return 0;
}

