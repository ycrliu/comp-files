/*
ID: robertl8
LANG: C++11
TASK: milk
*/
#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

typedef pair<int, int> ii;

ii a[5005];

int main()
{
#ifndef HOME
	freopen("milk.in", "r", stdin);
	freopen("milk.out", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; ++i)
	{
		cin >> a[i].fi >> a[i].se;
	}
	sort(a, a + m);
	int totcost = 0;
	for(int i = 0; i < m; ++i)
	{
		if(n - a[i].se > 0)
		{
			totcost += a[i].fi * a[i].se;
			n -= a[i].se;
		}
		else
		{
			totcost += a[i].fi * n;
			break;
		}
	}
	cout << totcost << endl;

	return 0;
}

