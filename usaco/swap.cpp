#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define all(c) (c).begin(), (c).end()
#define sz(x) (int)(x).size()

#define F0R(i, a) for(int i = 0; i < (a); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define F0Rd(i, a) for(int i = (a); i >= 0; i--)
#define FORd(i, a, b) for(int i = (a); i >= (b); i--)

int n;

bool eq(vector<int>& a)
{
	FOR(i, 1, n + 1) if(a[i] != i) return false;
	return true;
}

int main()
{
	ifstream cin("swap.in");
	ofstream cout("swap.out");
	int k, a1, a2, b1, b2;
	cin >> n >> k >> a1 >> a2 >> b1 >> b2;
	vector<int> a(n + 1);
	FOR(i, 1, n + 1) a[i] = i;
	F0R(i, (a2 - a1 + 1) / 2) swap(a[a1 + i], a[a2 - i]);
	F0R(i, (b2 - b1 + 1) / 2) swap(a[b1 + i], a[b2 - i]);
	map<int, int> mp;
	FOR(i, 1, n + 1) mp[i] = a[i];
	int cycle_size = 1;
	while(!eq(a))
	{
		vector<int> temp(a);
		FOR(i, 1, n + 1) a[i] = temp[mp[i]];
		cycle_size++;
	}
	k %= cycle_size;
	F0R(_, k) 
	{
		vector<int> temp(a);
		FOR(i, 1, n + 1) a[i] = temp[mp[i]];
	}
	FOR(i, 1, n + 1) cout << a[i] << endl;
	return 0;
}

