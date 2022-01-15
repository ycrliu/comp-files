#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int petals[105];
int psum[105];

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> petals[i];
		psum[i] = petals[i] + (!i ? 0 : psum[i - 1]);
	}
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			int tot_petals = psum[j] - (i - 1 >= 0 ? psum[i - 1] : 0);
			int num_flowers = j - i + 1;
			int avg = -1;
			if(tot_petals % num_flowers == 0)
				avg = tot_petals / num_flowers;
			for(int k = i; k <= j; k++)
				if(petals[k] == avg)
				{
					cnt++;
					break;
				}
		}
	}
	cout << n + cnt << endl;
	return 0;
}

