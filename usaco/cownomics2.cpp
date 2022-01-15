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
#include <cassert>
#include <climits>

using namespace std;

string spotty[105];
string plain[105];

int main()
{
	ifstream cin("cownomics.in");
	ofstream cout("cownomics.out");

	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> spotty[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin >> plain[i];
	}
	int numPos = 0;
	for(int i = 0; i < m; i++)
	{
		bool posWorks = true;
		for(int j = 0; j < n; j++)
		{
			for(int k = 0; k < n; k++)
			{
				if(spotty[j][i] == plain[k][i])
				{
					posWorks = false;
					break;
				}
			}
			if(!posWorks)
			{
				break;
			}
		}
		if(posWorks)
		{
			numPos++;
		}
	}
	cout << numPos << endl;
	return 0;
}

