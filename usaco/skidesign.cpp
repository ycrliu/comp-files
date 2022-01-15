/*
ID: robertl8
LANG: C++11
TASK: skidesign
*/
#include <bits/stdc++.h>

using namespace std;

int a[1005];

int main()
{
#ifndef HOME
	freopen("skidesign.in", "r", stdin);
	freopen("skidesign.out", "w", stdout);
#endif
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	int mincost = INT_MAX;
	for(int i = 0; i <= 83; ++i)
	{
		int cost = 0;
		for(int j = 0; j < n; ++j)
		{
			if(a[j] < i)
				cost += (i - a[j]) * (i - a[j]);
			else if(a[j] > i + 17)
				cost += (a[j] - (i + 17)) * (a[j] - (i + 17));
		}
		mincost = min(cost, mincost);
	}
	cout << mincost << endl;
	return 0;
}

