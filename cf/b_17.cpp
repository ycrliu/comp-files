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

pair<int, string> mouse[300005];

int main()
{
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> mouse[i].first >> mouse[i].second;
    }
    sort(mouse, mouse + m);
    int t = 0;
    long long tc = 0;
    for(int i = 0; i < m && (a || b || c); i++)
    {
        if(a && mouse[i].second == "USB")
        {
            a--;
            t++;
            tc += mouse[i].first;
        }
        else if(b && mouse[i].second == "PS/2")
        {
            b--;
            t++;
            tc += mouse[i].first;
        }
        else if(c)
        {
            c--;
            t++;
            tc += mouse[i].first;
        }
    }
    cout << t << " " << tc << endl;
    return 0;
}

