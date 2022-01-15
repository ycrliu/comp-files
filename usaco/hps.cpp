#include <bits/stdc++.h>

using namespace std;

int p[100005], h[100005], s[100005];
int main()
{
	ifstream cin("hps.in");
	ofstream cout("hps.out");
	int n;
	cin >> n;
	char move;
	for(int i = 0; i < n; ++i)
	{
		cin >> move;
		p[i] += (move == 'P');
		h[i] += (move == 'H');
		s[i] += (move == 'S');
		if(i)
		{
			p[i] += p[i - 1];
			h[i] += h[i - 1];
			s[i] += s[i - 1];
		}
	}
	int ans = INT_MIN;
	for(int i = 0; i + 1 < n; ++i)
	{
		ans = max(p[i] + h[n - 1] - h[i], ans);
		ans = max(p[i] + s[n - 1] - s[i], ans);
		ans = max(h[i] + s[n - 1] - s[i], ans);
		ans = max(h[i] + p[n - 1] - p[i], ans);
		ans = max(s[i] + p[n - 1] - p[i], ans);
		ans = max(s[i] + h[n - 1] - h[i], ans);
	}
	ans = max(p[n - 1], ans);
	ans = max(h[n - 1], ans);
	ans = max(s[n - 1], ans);
	cout << ans << endl;
	return 0;
}

