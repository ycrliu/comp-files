#include <bits/stdc++.h>

using namespace std;

pair<int, int> a[1005];
int main()
{
	ifstream cin("balancing.in");
	ofstream cout("balancing.out");
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i].first >> a[i].second;
	sort(a, a + n);
	
	int ans = INT_MAX;
	for(int i = 0; i < n - 1; ++i) //place vertical border after each x value
	{
		for(int j = 0; j < n; ++j) //place horizontal border on each y value
		{
			int topleft = 0, botleft = 0, topright = 0, botright = 0;
			int y = a[j].second;
			for(int k = 0; k <= i; ++k)
				if(a[k].second <= y)
					++botleft;
			for(int k = i + 1; k < n; ++k)
				if(a[k].second <= y)
					++botright;
			topleft = i - botleft + 1;
			topright = n - (i + 1) - botright;
			int maxq = max(topleft, max(botleft, max(topright, botright)));
			ans = min(maxq, ans);
		}
	}
	cout << ans << endl;
	return 0;
}

