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
class Solution {
public:
	long long largestRectangleArea(vector<long long>& heights) {
		int n = heights.size();
		if (!n) return 0;
		stack<int> stck;
		vector<long long> area(n, 0);
		for (int i = 0; i < n; i++) {
			while (!stck.empty() && heights[stck.top()] >= heights[i]) stck.pop();
			int width = i - (!stck.empty() ? stck.top() : -1);
			area[i] += width * heights[i];
            if(!stck.empty()) cout << heights[stck.top()] << " " << heights[i] <<" " << width <<  endl;
			stck.push(i);
		}
		while (!stck.empty()) stck.pop();
		for (int i = n - 1; ~i; i--) {
			while (!stck.empty() && heights[stck.top()] >= heights[i]) stck.pop();
			int width = (!stck.empty() ? stck.top() : n) - i;
			area[i] += (width - 1) * heights[i];
			stck.push(i);
		}
		return *max_element(area.begin(), area.end());
	}
};
int main()
{
    int n;
    cin >> n;

    vector<long long> height(n);
    for(int i = 0; i < n; i++)
    {
        cin >> height[i];
    }
    cout << Solution().largestRectangleArea(height) << endl;
    return 0;
}

