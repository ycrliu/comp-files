/*
ID: robertl8
LANG: C++11
TASK: numtri
*/
#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

typedef pair<int, int> ii;

int a[1005][1005], dp[1005][1005];

int main()
{
#ifndef HOME
	freopen("numtri.in", "r", stdin);
	freopen("numtri.out", "w", stdout);
#endif
	int r;
	cin >> r;
	for(int i = 0; i < r; ++i)
		for(int j = 0; j <= i; ++j)
			cin >> a[i][j];

	dp[0][0] = a[0][0];

	for(int i = 1; i < r; ++i)
	{
		for(int j = 0; j < r; ++j)
		{
			if(j - 1 >= 0)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + a[i][j];
			else
				dp[i][j] = dp[i - 1][j] + a[i][j];
		}
	}
	int ans = -1;
	for(int i = 0; i < r; ++i)
		ans = max(dp[r - 1][i], ans);
	cout << ans << endl;

	return 0;
}

