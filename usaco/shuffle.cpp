#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

typedef pair<int, int> ii;

int a[105];
string id[105];

int main()
{
#ifndef HOME
	freopen("shuffle.in", "r", stdin);
	freopen("shuffle.out", "w", stdout);
#endif
	int n;
	cin >> n;
	for(int i = 1, ai; i <= n; ++i)
	{
		cin >> ai;
		a[ai] = i;
	}

	for(int i = 1; i <= n; ++i)
		cin >> id[i];

	vector<string> res(n + 1, "");

	//i -> a[i] (forwards)
	//a[i] -> i (backwards)
	for(int i = 1; i <= n; ++i)
	{
		int newindex = i;
		for(int j = 0; j < 3; ++j)
			newindex = a[newindex];
		res[newindex] = id[i];

	}

	for(int i = 1; i <= n; ++i)
		cout << res[i] << endl;
	return 0;
}

