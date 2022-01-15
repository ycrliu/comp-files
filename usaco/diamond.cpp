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

int sizes[1005];

int main()
{
	ifstream cin("diamond.in");
	ofstream cout("diamond.out");

	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		cin >> sizes[i];
	}
	sort(sizes, sizes + n);
	int maxNumPossible = 1;
	for(int i = 0; i < n; i++)
	{
		int numPossible = 1;
		for(int j = i + 1; j < n; j++)
		{
			if(sizes[j] - sizes[i] > k)
			{
				break;
			}
			numPossible++;
		}
		maxNumPossible = max(numPossible, maxNumPossible);
	}
	cout << maxNumPossible << endl;
	return 0;
}

