#include <bits/stdc++.h>

using namespace std;

map<string, int> m;

int main()
{
	ifstream cin("citystate.in");
	ofstream cout("citystate.out");
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		string c, s;
		cin >> c >> s;
		string k = c.substr(0, 2) + s;
		++m[k];
	}
	long long ans = 0;
	for(auto f : m)
	{
		string cp = f.first.substr(2) + f.first.substr(0, 2);
		if(cp != f.first)
			ans += (long long)m[cp] * f.second;
	}
	cout << ans/2 << endl;

	return 0;
}

