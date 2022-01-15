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

int b[1005];
int ans[1005];
bool used[2005];

int main()
{
	ifstream cin("photo.in");
	ofstream cout("photo.out");
	int n;
	cin >> n;
	for(int i = 0; i < n - 1; i++)
		cin >> b[i];
	for(int init = 1; init <= n; init++)
	{
		used[init] = true;
		ans[0] = init;
		int num = init;
		bool ok = true;
		for(int i = 0; i < n - 1; i++)
		{
			num = b[i] - num;
			if(num <= 0 || num > n || used[num])
			{
				ok = false;
				break;
			}
			ans[i + 1] = num;
			used[num] = true;
		}
		if(ok)
		{
			for(int i = 0; i < n; i++)
				cout << ans[i] << (i == n - 1 ? "\n" : " ");
			return 0;
		}
		memset(used, 0, sizeof used);
	}
}

