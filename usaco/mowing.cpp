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

char dir[105];
int steps[105];
map<pair<int, int>, int> lastTimeVis;

int main()
{
	ifstream cin("mowing.in");
	ofstream cout("mowing.out");

	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> dir[i] >> steps[i];
	}
	
	int cI = 1;
	int cJ = 1;
	int t = 5;
	int x = INT_MAX;
	bool repeats = false;
	for(int i = 0; i < n; i++)
	{
		while(steps[i]--)
		{
			if(lastTimeVis[{cI, cJ}] > 0)
			{
				if(!repeats)
				{
					repeats = true;
				}
				x = min(t - lastTimeVis[{cI, cJ}], x);
			}
			lastTimeVis[{cI, cJ}] = t++;
			if(dir[i] == 'N')
			{
				cI--;
			}
			else if(dir[i] == 'E')
			{
				cJ++;
			}
			else if(dir[i] == 'S')
			{
				cI++;
			}
			else
			{
				cJ--;
			}
		}
	}
	cout << (repeats ? x : -1) << endl;
	return 0;
}

