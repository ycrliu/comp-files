/*
ID: robertl8
LANG: C++11
TASK: barn1
*/
#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

typedef pair<int, int> ii;

bool cow[205];

int main()
{
#ifndef HOME
	freopen("barn1.in", "r", stdin);
	freopen("barn1.out", "w", stdout);
#endif
	int m, s, c, minn = INT_MAX, maxx = INT_MIN;
	cin >> m >> s >> c;
	for(int i = 0, a; i < c; ++i)
	{
		cin >> a;
		cow[a] = 1;
		minn = min(a, minn);
		maxx = max(a, maxx);
	}

	vector<int> emptysegs; //lengths of segments with empty stalls
	int last = -1;
	for(int i = minn; i <= maxx; ++i)
	{
		if(cow[i] && last != -1)
		{
			emptysegs.push_back(i - last);
			last = -1; //reset
		}
		if(!cow[i] && last == -1)
		{
			last = i; //begin segment
		}
	}
	sort(emptysegs.rbegin(), emptysegs.rend());

	int tot = maxx - minn + 1;
	for(int i = 0; i < min(m - 1, (int)emptysegs.size()); ++i)
	{
		tot -= emptysegs[i];
	}
	cout << tot << endl;

	return 0;
}

