#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

typedef pair<int, int> ii;

int n, b, a[255], depth[255], dist[255], ans = 1000;
bool done[255][255];

void recur(int pos, int ind)
{
	if(done[pos][ind])
		return;
	done[pos][ind] = 1;
	if(pos == n - 1)
	{
		ans = min(ind, ans);
		return;
	}
	for(int i = pos + 1; i < min(n, dist[ind] + pos + 1); ++i)
		if(depth[ind] >= a[i])
			recur(i, ind);

	for(int i = ind + 1; i < b; ++i)
		if(depth[i] >= a[pos])
			recur(pos, i);
}
int main()
{
#ifndef HOME
	freopen("snowboots.in", "r", stdin);
	freopen("snowboots.out", "w", stdout);
#endif
	cin >> n >> b;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < b; ++i)
		cin >> depth[i] >> dist[i];

	recur(0, 0);

	cout << ans << endl;

	return 0;
}

