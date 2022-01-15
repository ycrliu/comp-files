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

array<int, 2> pos[26];

int main()
{
	ifstream cin("circlecross.in");
	ofstream cout("circlecross.out");

	string s;
	cin >> s;
	// A ... B ... A ... B
	for(int i = 0; i < 52; i++)
	{
		int j = s[i] - 'A';
		if(!pos[j][0])
			pos[j][0] = i + 1;
		else
			pos[j][1] = i + 1;
	}
	int count = 0;
	for(int i = 0; i < 26; i++)
	{
		for(int j = 0; j < 26; j++)
		{
			if(pos[i][0] < pos[j][0] && pos[i][1] < pos[j][1] && pos[i][1] > pos[j][0])
			{
				count++;
			}
		}
	}
	cout << count << endl;
	return 0;
}

