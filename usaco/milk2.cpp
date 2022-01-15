/*
ID: robertl8
LANG: C++11
TASK: milk2
*/
#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

pair<int, int> a[5005];

int main()
{
#ifndef HOME
	freopen("milk2.in", "r", stdin);
	freopen("milk2.out", "w", stdout);
#endif
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i].fi >> a[i].se;
	}
	sort(a, a + n);

	int startmilk = a[0].fi, endmilk = a[0].se;
	int longestmilk = endmilk - startmilk;
	for(int i = 1; i < n; ++i)
	{
		if(a[i].fi <= endmilk)
		{
			endmilk = max(a[i].se, endmilk);
		}
		else
		{
			startmilk = a[i].fi;
			endmilk = a[i].se;
		}
		longestmilk = max(endmilk - startmilk, longestmilk);
	}
	int longestnomilk = 0;
	int startseg = a[0].se;
	int endseg = 0;
	for(int i = 1; i < n; ++i)
	{
		if(a[i].fi > startseg)
		{
			endseg = a[i].fi;
			longestnomilk = max(endseg - startseg, longestnomilk);
			startseg = a[i].se;
		}
		else
		{
			startseg = max(a[i].se, startseg);
		}
	}
	cout << longestmilk << " " << longestnomilk << endl;
	return 0;
}

