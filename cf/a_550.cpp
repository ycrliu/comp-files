#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <algorithm>
#include <utility>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <numeric>

#define ll long long
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define MAXN 100000

using namespace std;

int main()
{
	string s;
	cin >> s;
	bool works = false;
	for(int i = 0; i + 1 < s.length(); i++)
	{
		bool found_a = s[i] == 'A' && s[i + 1] == 'B';
		bool found_b = s[i] == 'B' && s[i + 1] == 'A';
		if(found_a || found_b)
		{
			for(int j = i + 2; j + 1 < s.length(); j++)
			{
				if(found_a && (s[j] == 'B' && s[j + 1] == 'A'))
				{
					works = true;
					break;
				}
				else if(found_b && (s[j] == 'A' && s[j + 1] == 'B'))
				{
					works = true;
					break;
				}
			}
		}
		if(works)
		{
			break;
		}
	}
	cout << (works ? "YES" : "NO") << endl;
	return 0;
}

