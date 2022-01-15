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

using namespace std;

int a[105];

int main()
{
	ifstream cin("taming.in");
	ofstream cout("taming.out");

	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	assert(a[0] <= 0);
	a[0] = 0;

	int lo = 0;
	int hi = 0;
	int i = 0;
	while(i < n)
	{
		if(a[i] != -1)
		{
			if(a[i] == 0)
			{
				lo++;
				hi++;
			}
			i++;
		}
		else
		{
			int j = i + 1;
			while(j < n && a[j] == -1)
				j++;
			int unknowns = j - i;
			if(j == n)
			{
				//no change to lo
				hi += unknowns;
			}
			else
			{
				if(a[j] != 0 && a[j] <= unknowns)
				{
					lo += 1;
					hi += (unknowns - (a[j] - 1));
				}
				else if(a[j] > unknowns)
				{
//					assert(i - 1 >= 0);
					if(a[i - 1] + unknowns < a[j] - 1)
					{
						cout << "-1\n";
						return 0;
					}
				}
				else if(a[j] == 0)
				{
					//no change to lo
					hi += unknowns;
				}
			}
			i = j;
		}
	}
	cout << lo << " " << hi << endl;
	return 0;
}

