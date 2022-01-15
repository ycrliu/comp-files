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

array<int, 2> f[155];
int ans[105];

int main()
{
	ifstream cin("revegetate.in");
	ofstream cout("revegetate.out");
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> f[i][0] >> f[i][1];
	}
	ans[1] = 1;
	for(int i = 2; i <= n; i++)
	{
		for(int s = 1; s <= 4; s++)
		{
			bool ok = true;
			for(int j = 0; j < m; j++)
			{
				if(f[j][0] == i)
				{
					if(ans[f[j][1]] == s)
					{
						ok = false;
						break;
					}
				}
				if(f[j][1] == i)
				{
					if(ans[f[j][0]] == s)
					{
						ok = false;
						break;
					}
				}
			}
			if(ok)
			{
				ans[i] = s;
				break;
			}
		}
	}
	for(int i = 1; i <= n; i++)
		cout << ans[i];
	cout << endl;
	return 0;
}

