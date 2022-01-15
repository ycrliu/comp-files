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

int n;
multiset<int> s;

int main()
{
    int m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int h;
        cin >> h;
        s.insert(h);
    }
    // s is automatically sorted
    while(m--)
    {
        int t;
        cin >> t;
        auto it = s.upper_bound(t);
        if(it == s.begin())
        {
            cout << "-1\n";
        }
        else
        {
            it--;
            cout << *it << endl;
            s.erase(it);
        }
    }
    return 0;
}

