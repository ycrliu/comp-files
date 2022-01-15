#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

typedef pair<int, int> ii;

int a[50005], minn[7], maxx[7];

int main()
{
#ifndef HOME
	freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);
#endif
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < 7; ++i)
	{
		minn[i] = n + 1;
		maxx[i] = -1;
	}
	minn[0] = 0;
	maxx[0] = 0;
	int ssf = 0;
	for(int i = 1; i <= n; ++i)
	{
		ssf = ((long long)(ssf + a[i - 1])) % 7;
		minn[ssf] = min(minn[ssf], i);
		maxx[ssf] = max(maxx[ssf], i);
	}
	int ans = 0;
	for(int i = 0; i < 7; ++i)
		ans = max(maxx[i] - minn[i], ans);
	cout << ans;
	return 0;
}

