#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

typedef pair<int, int> ii;

struct guess
{
	int a, b, g;
};
guess en[100];
int main()
{
#ifndef HOME
	freopen("shell.in", "r", stdin);
	freopen("shell.out", "w", stdout);
#endif
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> en[i].a >> en[i].b >> en[i].g;
	int maxx = INT_MIN;
	for(int init = 0; init < 3; ++init)
	{
		array<int, 3> board = {0, 0, 0};
		board[init] = 1;
		int curpts = 0;
		for(int i = 0; i < n; ++i)
		{
			swap(board[en[i].a - 1], board[en[i].b - 1]);
			if(board[en[i].g - 1])
				++curpts;
		}
		maxx = max(curpts, maxx);
	}
	cout << maxx << endl;
	return 0;
}