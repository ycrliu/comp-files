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

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		string s;
		cin >> n >> s;
		vector<int> dig(n);
		long long digSum = 0;
		for(int i = 0; i < n; i++)
		{
			dig[i] = s[i] - '0';
			digSum += dig[i];
		}
		int numNonEndPieces = 0;
		for(int i = 0; i < n - 1; i++)
		{
			if(dig[i] != 0)
			{
				numNonEndPieces++;
			}
		}
		cout << numNonEndPieces + digSum << endl;
	}
	return 0;
}

