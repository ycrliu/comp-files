#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	if(fopen("censor.in", "r"))
	{
		freopen("censor.in", "r", stdin);
		freopen("censor.out", "w", stdout);
	}
	string s, del;
	cin >> s >> del;
//	while(s.find(del) != string::npos)
//	{
//		int i = 0;
//		while(i < s.size())
//		{
//			if(s.substr(i, del.size()) == del)
//			{
//				s.erase(i, del.size());
//			}
//			else
//			{
//				i++;
//			}
//		}
//	}

	// - Instead of simulating, build the string from scratch
	// - Deleting the end of a string is more efficient than deleting the middle
	// because no data needs to be moved
	string r;
	for(int i = 0; i < s.size(); i++)
	{
		r += s[i];
		
		if(r.size() >= del.size() && r.substr(r.size() - del.size()) == del)
		{
			r.erase(r.size() - del.size());
		}
	}
	cout << r << endl;
	return 0;
}

