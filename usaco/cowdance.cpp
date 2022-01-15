#include <bits/stdc++.h>

using namespace std;

int main()
{
	ifstream cin("cowdance.in");
	ofstream cout("cowdance.out");
	
	int n, tmax;
	cin >> n >> tmax;
	vector<int> d(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> d[i];
	}
	int l = 0, r = n, ans = -1;
	while(l <= r)
	{
		int k = l + (r - l) / 2;
		vector<int> cur = d;
		int time = 0;
		while(1)
		{
			if(cur.size() > k)
			{
				int tempmin = INT_MAX;
				for(int i = 0; i < k; ++i)
				{
					tempmin = min(cur[i], tempmin);
				}
				int i = 0, done = 0;
				while(done < k)
				{
					if(cur[i] - tempmin == 0)
					{
						cur.erase(cur.begin() + i);
						++done;
					}
					else
					{
						cur[i] -= tempmin;
						++done;
						++i;
					}
				}
				time += tempmin;
			}
			else
			{
				int tempmax = -1;
				for(int i = 0; i < cur.size(); ++i)
					tempmax = max(cur[i], tempmax);
				time += tempmax;
				break;

			}
		}
//		cout << k << " " << time << endl;
		if(time <= tmax)
		{
			ans = k;
			r = k - 1;
		}
		else
		{
			l = k + 1;
		}
	}
	cout << ans << endl;
	return 0;
}

