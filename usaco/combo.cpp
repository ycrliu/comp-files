/*
ID: robertl8
LANG: C++11
TASK: combo
*/
#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

typedef pair<int, int> ii;

int n, c1[3], c2[3];
bool used[101][101][101];

bool ok(int a, int b)
{
	return n - a + b <= 2 || n - b + a <= 2 || abs(a - b) <= 2;
}
int main()
{
#ifndef HOME
	freopen("combo.in", "r", stdin);
	freopen("combo.out", "w", stdout);
#endif
	cin >> n;
	for(int i = 0; i < 3; ++i)
		cin >> c1[i];
	for(int i = 0; i < 3; ++i)
		cin >> c2[i];
	int cnt = 0;
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			for(int k = 1; k <= n; ++k)
			{
				if(!used[i][j][k])
				{
					if((ok(i, c1[0]) && ok(j, c1[1]) && ok(k, c1[2])) || (ok(i, c2[0]) && ok(j, c2[1]) && ok(k, c2[2])))
						++cnt;
					used[i][j][k] = 1;
				}
			}
		}
	}
	cout << cnt << endl;

	return 0;
}

