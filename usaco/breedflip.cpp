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

using namespace std;

int main()
{
	ifstream cin("breedflip.in");
	ofstream cout("breedflip.out");

	int n;
	string a, b;
	cin >> n >> a >> b;
	
	int unequalSegments = 0;
	int i = 0;
	while(i < n)
	{
		int j = i;
		if(a[j] != b[j])
		{
			while(j < n && a[j] != b[j])
			{
				j++;
			}
		}
		if (i == j)
			i++;
		else
		{
			i = j;
			unequalSegments++;
		}
	}
	cout << unequalSegments << endl;
	return 0;
}

