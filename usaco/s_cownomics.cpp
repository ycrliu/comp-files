#include <bits/stdc++.h>

using namespace std;
using ll = long long;

string spotty[505];
string plain[505];

int main()
{
	ifstream cin("cownomics.in");
	ofstream cout("cownomics.out");
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> spotty[i];
	for(int i = 0; i < n; i++)
		cin >> plain[i];
	int triples = 0;
	for(int i = 0; i < m; i++)
	{
		for(int j = i + 1; j < m; j++)
		{
			for(int k = j + 1; k < m; k++)
			{
				bool tripleWorks = true;
				map<pair<pair<char, char>, char>, bool> seen;
				for(int it = 0; it < n; it++)
				{
					seen[{{spotty[it][i], spotty[it][j]}, spotty[it][k]}] = true;
				}
				for(int it = 0; it < n; it++)
				{
					if(seen[{{plain[it][i], plain[it][j]}, plain[it][k]}])
					{
						tripleWorks = false;
						break;
					}
				}
//				for(int it = 0; it < n; it++)
//				{
//					for(int it2 = 0; it2 < n; it2++)
//					{
//						if(spotty[it][i] == plain[it2][i] && spotty[it][j] == plain[it2][j] && spotty[it][k] == plain[it2][k])
//						{
//							tripleWorks = false;
//							break;
//						}
//					}
//					if(!tripleWorks)
//						break;
//				}
				if(tripleWorks)
					triples++;
			}
		}
	}
	cout << triples << endl;
	return 0;
}

