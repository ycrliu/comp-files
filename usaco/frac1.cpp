/*
ID: robertl8
LANG: C++11
TASK: frac1
*/
#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int, int> p1, pair<int, int> p2)
{
	double f1 = p1.first / static_cast<double>(p1.second);
	double f2 = p2.first / static_cast<double>(p2.second);
	return f1 < f2;
}

int main()
{
	ifstream cin("frac1.in");
	ofstream cout("frac1.out");

	int n;
	cin >> n;
	vector<pair<int, int>> v;
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j < i; ++j)
		{
			if(__gcd(i, j) == 1)
			{
				v.push_back({j, i});
			}
		}
	}
	sort(v.begin(), v.end(), comp);
	cout << "0/1\n";
	for(pair<int, int> p : v)
		cout << p.first << "/" << p.second << endl;
	cout << "1/1\n";
	return 0;
}

