#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

typedef pair<int, int> ii;

int a[1005];

int main()
{
#ifndef HOME
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	int minn = INT_MAX;
	for(int i = 1; i <= n; ++i)
	{
		int tot = 0, dist = 1;
		for(int j = i + 1; j <= n; ++j)
		{
			tot += dist * a[j];
			++dist;
		}
		for(int j = 1; j < i; ++j)
		{
			tot += dist * a[j];
			++dist;
		}
		minn = min(tot, minn);
	}
	cout << minn;
	return 0;
}

