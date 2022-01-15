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
#define MAXN 200005

using namespace std;

long long height[MAXN];
long long area[MAXN];

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> height[i];
    }

    stack<long long> st;
    
    for(int i = 0; i < n; i++)
    {
        // stop the rectangle on the first shorter bar on left
        while(!st.empty() && height[st.top()] >= height[i])
        {
            st.pop();
        }

        if(st.empty())
        {
            area[i] += height[i] * (i + 1);
        }
        else
        {
            area[i] += height[i] * (i - st.top());
        }

        st.push(i);
    }

    while(!st.empty())
    {
        st.pop();
    }

    for(int i = n - 1; i >= 0; i--)
    {
        // stop the rectangle on the first shorter bar on right
        while(!st.empty() && height[st.top()] >= height[i])
        {
            st.pop();
        }

        if(st.empty())
        {
            area[i] += height[i] * (n - i - 1);
        }
        else
        {
            area[i] += height[i] * (st.top() - i + 1 - 1 - 1);
        }
        st.push(i);
    }

    cout << *max_element(begin(area), end(area)) << endl;

    return 0;
}

