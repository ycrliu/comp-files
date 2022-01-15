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
map<char, int> ind;
bool sG[4];
bool pG[4];

void information()
{
	ind['A'] = 0;
	ind['C'] = 1;
	ind['G'] = 2;
	ind['T'] = 3;
}

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
	information();
	int numPos = 0;

	// Record encountered genes at every position; count positions without genes
	// repeated in both plain and spotty genomes
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			sG[ind[spotty[j][i]]] = true;
			pG[ind[plain[j][i]]] = true;
		}
		bool posWorks = true;
		for(int j = 0; j < 4; j++)
		{
			if(sG[j] && pG[j])
			{
				posWorks = false;
				break;
			}
		}
		numPos += posWorks;
		memset(sG, false, sizeof(sG));
		memset(pG, false, sizeof(pG));
	}
	cout << numPos << endl;
	return 0;
}

