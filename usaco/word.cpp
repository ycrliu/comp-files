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

string word[105];

int main()
{
	ifstream cin("word.in");
	ofstream cout("word.out");

	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		cin >> word[i];
	}
	int i = 0;
	while(i < n)
	{
		int lineCount = 0;
		int j = i;
		while(j < n && lineCount + word[j].size() <= k)
		{
			cout << word[j];
			lineCount += word[j].size();
			if(j + 1 < n && lineCount + word[j + 1].size() <= k)
			{
				cout << " ";
			}
			j++;
		}
		cout << endl;
		i = j;
	}
	return 0;
}

