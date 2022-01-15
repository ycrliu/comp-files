/*
ID: robertl8
LANG: C++11
TASK: beads
*/
#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

typedef pair<int, int> ii;

int n;
bool used[355];

int prv(int i)
{
	return !i ? n - 1 : i - 1;
}
int nxt(int i)
{
	return i == n - 1 ? 0 : i + 1; 
}
int main()
{
#ifndef HOME
	freopen("beads.in", "r", stdin);
	freopen("beads.out", "w", stdout);
#endif
	string s;
	cin >> n >> s;
	int maxx = -1;
	for(int i = 0; i < n; ++i)
	{
		int pi = i, ni = nxt(i), cur = 0;
		char o1 = 'a', o2 = 'a';
		while(s[pi] == 'w' || ((s[i] == 'w') ? (s[pi] == o1 || o1 == 'a') : s[pi] == s[i]))
		{
			if(used[pi])
				break;
			used[pi] = 1;
			++cur;
			if(s[pi] != 'w' && o1 == 'a')
				o1 = s[pi];
			pi = prv(pi);
			if(pi == i)
				return cout << n << endl, 0;
		}
		while(s[ni] == 'w' || ((s[nxt(i)] == 'w') ? (s[ni] == o2 || o2 == 'a') : s[ni] == s[nxt(i)]))
		{
			if(used[ni])
				break;
			used[ni] = 1;
			++cur;
			if(s[ni] != 'w' && o2 == 'a')
				o2 = s[pi];
			ni = nxt(ni);
			if(ni == i)
				return cout << n << endl, 0;
		}
//		cout << i << " " << cur << endl;
		maxx = max(cur, maxx);
		memset(used, 0, sizeof used);
	}
	cout << maxx << endl;
	return 0;
}

