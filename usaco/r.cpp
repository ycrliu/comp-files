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

int produce[100005];
array<int, 2> buy[100005];
int rent[100005];
ll srent[100005];
ll sprod[100005];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
//	ifstream cin("rental.in");
//	ofstream cout("rental.out");
	int n, m, r;
	cin >> n >> m >> r;
	for(int i = 0; i < n; i++)
		cin >> produce[i];
	for(int i = 0; i < m; i++)
		cin >> buy[i][1] >> buy[i][0]; // {price, amt}
	for(int i = 0; i < r; i++)
		cin >> rent[i];
	sort(produce, produce + n);
	sort(buy, buy + m);
	sort(rent, rent + r);
	for(int i = n - 1; i >= 0; i--)
		sprod[i] = (i == n - 1 ? produce[i] : produce[i] + sprod[i + 1]);
	for(int i = r - 1; i >= 0; i--)
		srent[i] = (i == r - 1 ? rent[i] : rent[i] + srent[i + 1]);
	ll max_profit = 0;
	for(int i = -1; i < n; i++)
	{
		ll profit = srent[r - i - 1];
		ll supply = sprod[i + 1];
		for(int j = m - 1; j >= 0; j--)
		{
			if(supply - buy[j][1] > 0)
			{
				profit += buy[j][0] * ((ll) buy[j][1]);
				supply -= buy[j][1];
			}
			else
			{
				profit += supply * ((ll) buy[j][0]);
				break;
			}
		}
		max_profit = max(profit, max_profit);
		if(i == r - 1)
			break;
	}
	cout << max_profit << endl;
	return 0;
}

