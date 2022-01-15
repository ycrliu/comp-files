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

const int MAX_N = 100000;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		string s;
		cin >> n >> s;
		int na = 0, nb = 0;
		for(int i = 0; i < s.size(); i++)
		{
			na += (s[i] == 'a');
			nb += (s[i] == 'b');
		}
		if(na == nb)
		{
			cout << 1 << " " << n << endl;
		}
		int diff = abs(nb - na);
		if((n - diff) % 2 != 0)
		{
			cout << -1 << " " << -1 << endl;
		}
	}
	return 0;
}

