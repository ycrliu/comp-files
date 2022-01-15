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

pair<int, int> movies[200005];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> movies[i].second >> movies[i].first;
    }
    sort(movies, movies + n);
    int last_finish = -1;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(movies[i].second >= last_finish)
        {
            last_finish = movies[i].first;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

