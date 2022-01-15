#include <bits/stdc++.h>

using namespace std;

int cap1, cap2, k, m, ans = INT_MAX;
bool vis[105][105];
void recur(int amt1, int amt2, int moves)
{
	if(vis[amt1][amt2])
		return;
	vis[amt1][amt2] = 1;

	ans = min(abs(amt1 + amt2 - m), ans);
	if(moves == k)
		return;

	recur(cap1, amt2, moves + 1);
	recur(amt1, cap2, moves + 1);
	recur(0, amt2, moves + 1);
	recur(amt1, 0, moves + 1);
	recur(amt1 + min(cap1 - amt1, amt2), amt2 - min(cap1 - amt1, amt2), moves + 1);
	recur(amt1 - min(cap2 - amt2, amt1), amt2 + min(cap2 - amt2, amt1), moves + 1);
}
int main()
{
	ifstream cin("pails.in");
	ofstream cout("pails.out");
	
	cin >> cap1 >> cap2 >> k >> m;

	recur(0, 0, 0);

	cout << ans << endl;
	return 0;
}

