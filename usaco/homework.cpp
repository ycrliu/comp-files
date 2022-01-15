#include <bits/stdc++.h>

using namespace std;

long long a[100005], s[100005];
int main()
{
	ifstream cin("homework.in");
	ofstream cout("homework.out");
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	s[n - 1] = a[n - 1];
	for(int i = n - 2; ~i; --i)
		s[i] = s[i + 1] + a[i];

	// find the maximum answer
	long double maxavg = -DBL_MAX;
	long long msf = LONG_MAX;
	for(int i = n - 1; ~i; --i)
	{
		msf = min(a[i], msf);
		long double cur = (1.0 * (s[i] - msf)) / (n - i - 1);
		maxavg = max(cur, maxavg);
	}
	msf = LONG_MAX;

	// collect indices
	vector<int> ans;
	for(int i = n - 1; ~i; --i)
	{
		msf = min(a[i], msf);
		long double cur = (1.0 * (s[i] - msf)) / (n - i - 1);
		if(cur == maxavg)
			ans.push_back(i);
	}
	sort(ans.begin(), ans.end());
	for(int i : ans)
		cout << i << endl;
	return 0;
}

