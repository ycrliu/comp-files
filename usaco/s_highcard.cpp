#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

typedef pair<int, int> ii;

bool f[100005];
vector<int> b, e;

int main()
{
#ifndef HOME
	freopen("highcard.in", "r", stdin);
	freopen("highcard.out", "w", stdout);
#endif
	int n;
	cin >> n;
	for(int i = 0, j; i < n; ++i)
	{
		cin >> j;
		f[j] = 1;
	}
	for(int i = 1; i <= 2*n; ++i)
	{
		if(f[i])
			e.push_back(i);
		else
			b.push_back(i);
	}
	int done = 0, cnt = 0;
	for(int i = n - 1; ~i; --i)
	{
		for(int j = n - 1 - done; ~j; --j)
		{
			++done;
			if(b[i] > e[j])
			{
				++cnt;
				break;
			}
		}
	}
	cout << cnt;
	return 0;
}

