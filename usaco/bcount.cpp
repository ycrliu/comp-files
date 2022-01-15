#include <bits/stdc++.h>

using namespace std;

int h[100005], g[100005], j[100005];

int main()
{
#ifndef HOME
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int n, q;
	cin >> n >> q;
	for(int i = 1, tp; i <= n; ++i)
	{
		cin >> tp;
		h[i] += (tp == 1) + h[i - 1];
		g[i] += (tp == 2) + g[i - 1];
		j[i] += (tp == 3) + j[i - 1];
	}
	for(int i = 0, a, b; i < q; ++i)
	{
		cin >> a >> b;
		cout << h[b] - h[max(a - 1, 0)] << " " << g[b] - g[max(a - 1, 0)] << " " << j[b] - j[max(a - 1, 0)] << endl;
	}
	return 0;
}

