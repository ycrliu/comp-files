#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

typedef pair<int, int> ii;

map<string, vector<string>> m;

int main()
{
#ifndef HOME
	freopen("guess.in", "r", stdin);
	freopen("guess.out", "w", stdout);
#endif
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		string animal;
		int k;
		cin >> animal >> k;
		for(int j = 0; j < k; ++j)
		{
			string c;
			cin >> c;
			m[animal].push_back(c);
		}
	}
	int maxocc = 0;
	for(map<string, vector<string>>::iterator it1 = m.begin(); it1 != m.end(); ++it1)
	{
		for(map<string, vector<string>>::iterator it2 = m.begin(); it2 != m.end(); ++it2)
		{
			if(it1 != it2)
			{
				int samec = 0;
				for(int i = 0; i < it1->se.size(); ++i)
				{
					if(find(it2->se.begin(), it2->se.end(), it1->se[i]) != it2->se.end())
						++samec;
				}
				maxocc = max(samec, maxocc);
			}
		}
	}
	cout << maxocc + 1 << endl;
	return 0;
}