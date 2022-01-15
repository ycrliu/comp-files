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
int x[MAXN + 1];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }

    stack<pair<int, int>> st;
    vector<int> ans(n + 1, -1);

    for(int i = 1; i <= n; i++)
    {
        // set PREVIOUS answers
        while(!st.empty() && st.top().first < x[i])
        {
            ans[st.top().second] = x[i];

            st.pop();
        }

        st.push({x[i], i});
    }

    for(int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
9
12 15 22 9 7 2 18 23 27
15 22 23 18 18 18 23 27 -1
*/
