/*
ID: robertl8
LANG: C++11
TASK: milk3
*/
#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

typedef pair<int, int> ii;

int ca, cb, cc;
bool vis[21][21][21];
vector<int> ans;

void dfs(int a, int b, int c)
{
	if(vis[a][b][c])
		return;
	vis[a][b][c] = 1;
	
	if(!a)
		ans.push_back(c);

	dfs(a - min(a, cb - b), b + min(a, cb - b), c);
	dfs(a + min(b, ca - a), b - min(b, ca - a), c);
	dfs(a - min(a, cc - c), b, c + min(a, cc - c));
	dfs(a + min(c, ca - a), b, c - min(c, ca - a));
	dfs(a, b - min(b, cc - c), c + min(b, cc - c));
	dfs(a, b + min(c, cb - b), c - min(c, cb - b));
}
int main()
{
#ifndef HOME
	freopen("milk3.in", "r", stdin);
	freopen("milk3.out", "w", stdout);
#endif
	cin >> ca >> cb >> cc;
	
	dfs(0, 0, cc);
	sort(ans.begin(), ans.end());

	for(int i = 0; i < ans.size() - 1; ++i)
		cout << ans[i] << " ";
	cout << ans.back() << endl;

	return 0;
}

