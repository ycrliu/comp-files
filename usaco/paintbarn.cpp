#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <queue>
#include <cstring>
#include <fstream>

using namespace std;
using ll = long long;

int ps[1005][1005];

int main()
{
	ifstream cin("paintbarn.in");
	ofstream cout("paintbarn.out");
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		ps[x1][y1]++;
		ps[x1][y2]--;
		ps[x2][y1]--;
		ps[x2][y2]++;
	}
	int ans = 0;
	for(int i = 0; i <= 1000; i++)
	{
		for(int j = 0; j <= 1000; j++)
		{
			if(i > 0)
				ps[i][j] += ps[i - 1][j];
			if(j > 0)
				ps[i][j] += ps[i][j - 1];
			if(i > 0 && j > 0)
				ps[i][j] -= ps[i - 1][j - 1];
			if(ps[i][j] == k)
				ans++;
		}
	}
	cout << ans << endl;
	return 0;
}

