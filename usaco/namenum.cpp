/*
ID: robertl8
LANG: C++11
TASK: namenum
*/
#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

typedef pair<int, int> ii;

set<string> names;
char ch[10][3] = {{'\0','\0','\0'},{'\0','\0','\0'},{'A','B','C'},{'D','E','F'},{'G','H','I'},{'J','K','L'},{'M','N','O'},{'P','R','S'},{'T','U','V'},{'W','X','Y'}};
string n;
bool ok;

void recur(string s, int i)
{
	if(i == n.length())
	{
		if(names.find(s) != names.end())
		{
			ok = 1;
			cout << s << endl;
			return;
		}
	}
	else
		for(int j = 0; j < 3; ++j)
		{
			recur(s + ch[n[i] - '0'][j], i + 1);
		}
}
int main()
{
#ifndef HOME
	freopen("namenum.in", "r", stdin);
	freopen("namenum.out", "w", stdout);
#endif
	ifstream f("dict.txt");
	for(int i = 0; i < 4617; ++i)
	{
		string name;
		f >> name;
		names.insert(name);
	}
	cin >> n;
	recur("", 0);
	if(!ok)
		cout << "NONE\n";
	return 0;
}

