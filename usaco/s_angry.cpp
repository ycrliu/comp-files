#include <bits/stdc++.h>

using namespace std;

long long a[50005];
int main()
{
#ifndef HOME
	freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);
#endif
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n);
	long long l = 0ll, r = 2000000005ll, ans = -1;
	while(l <= r)
	{
		long long mid = l + (r - l) / 2;
		int i = 0, it = 0, cnt = 0;
		while(it < k)
		{
			int j = i;
			for(; j < n && a[j] <= 2*mid + a[i]; ++j)
				++cnt;
			++it;
			if(j == i)
				break;
			else
				i = j;
		}
		if(cnt == n)
		{
			ans = mid;
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	cout << ans;
	return 0;
}

