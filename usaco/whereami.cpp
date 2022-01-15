#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	ifstream cin("whereami.in");
	ofstream cout("whereami.out");
	int n;
	string s;
	cin >> n >> s;
	for(int len = 1; len <= n; len++)
	{
		map<string, int> cnt;
		for(int i = 0; i + len <= n; i++)
			cnt[s.substr(i, len)]++;
		bool ok = true;
		for(auto p : cnt)
			if(p.second > 1)
			{
				ok = false;
				break;
			}
		if(ok)
		{
			cout << len << endl;
			return 0;
		}
	}
}

