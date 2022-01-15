#include <bits/stdc++.h>

using namespace std;
using ll = long long;

char dir[55];
array<int, 2> loc[55];
vector<int> ans[55];

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> dir[i] >> loc[i][0] >> loc[i][1];
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(i != j)
			{
				// skip pairs without overlapping paths
				if(dir[i] == dir[j])
					continue;
				if(dir[j] == 'E' && loc[j][0] >= loc[i][0])
					continue;
				if(dir[j] == 'N' && loc[j][1] >= loc[i][1])
					continue;
				
				// analyze pairs with overlapping paths
				if(dir[i] == 'N')
				{
					int jdx = loc[i][0] - loc[j][0];
					int idy = loc[j][1] - loc[i][1];
					if(jdx < idy)
					{
						ans[i].push_back(i);
						ans[i].push_back(j);
						ans[i].push_back(idy);
//						cout << i << " " << j << " " << idy << endl;
						break;
					}
//					else if(jdx == idy)
//					{
//						cout << i << " " << j << " " << "Infinity\n";
//						break;
//					}
				}
				else
				{
					int idx = loc[j][0] - loc[i][0];
					int jdy = loc[i][1] - loc[j][1];
					if(idx > jdy)
					{
						ans[i].push_back(i);
						ans[i].push_back(j);
						ans[i].push_back(idx);
//						cout << i << " " << j << " " << idx << endl;
						break;
					}
//					else if(idx == jdy)
//					{
//						cout << i << " " << j << " " << "Infinity\n";
//						break;
//					}
				}
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(ans[i].empty())
			cout << "Infinity\n";
		else
		{
			for(int j : ans[i])
				cout << j << " ";
			cout << '\n';
		}
	}
	return 0;
}

