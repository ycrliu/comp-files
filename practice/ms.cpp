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

int n;
int x[105];

// generate all subsets
bool possible[100005];
int ans;
void recur(int amt, int i, bool something)
{
    if(i == n)
    {
        if(something)
        {
            if(!possible[amt])
            {
                possible[amt] = true;
                ans++;
            }
        }
    }
    else
    {
        recur(amt, i + 1, something);
        recur(amt + x[i], i + 1, true);
    }
}
void solve1()
{
    recur(0, 0, false);
    cout << ans << endl;
    for(int i = 0; i <= 100000; i++)
    {
        if(possible[i])
        {
            cout << i << " ";
        }
    }
    cout << endl;
}
void solve2()
{
    set<int> amts;
    for(int i = 0; i < (1<<n); i++)
    {
        int amt = 0;
        for(int j = 0; j < n; j++)
        {
            if(i & (1 << j))
            {
                amt += x[j];
            }
        }
        if(amt)
        {
            amts.insert(amt);
        }
    }
    cout << amts.size() << endl;
    for(int amt : amts)
    {
        cout << amt << " ";
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
//    solve1();
    solve2();
    return 0;
}

