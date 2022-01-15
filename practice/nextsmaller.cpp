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

int n;
int x[200005];

void solve1()
{
    stack<pair<int, int>> stck;
    string ans;

    for(int i = n; i >= 1; i--)
    {
        while(!stck.empty() && stck.top().first >= x[i])
        {
            stck.pop();
        }

        if(stck.empty())
        {
            ans = "-1" + ans;
        }
        else
        {
            ans = to_string(stck.top().first) + ans;
        }
        if(i > 1)
        {
            ans = " " + ans;
        }

        stck.push({x[i], i});
    }

    cout << ans << endl;
}

void solve2()
{
    stack<pair<int, int>> stck;
    vector<int> ans(n + 1, -1);

    for(int i = 1; i <= n; i++)
    {
        // because we continue popping until x[i] >= stck.top(), we can guarantee
        // that the stack is monotonic: in particular, increasing
        while(!stck.empty() && x[i] < stck.top().first)
        {
            // x[i] is the first element to be less than stck.top().first
            // set x[i] as the answer at index = stck.top().second
            ans[stck.top().second] = x[i];
            stck.pop();
        }
        // add most recent element
        stck.push({x[i], i});
    }

    for(int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }

    // solve1();
    solve2();

    return 0;
}

