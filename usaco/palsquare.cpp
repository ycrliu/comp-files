/*
ID: robertl8
LANG: C++11
TASK: palsquare
*/
#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

typedef pair<int, int> ii;

string conv(int num10, int b)
{
	if(!num10)
		return "";
	else
	{
		if(num10 % b > 9)
		{
			string a = "";
			a += 'A' + ((num10 % b) - 10);
			return conv(num10 / b, b) + a;
		}
		else
			return conv(num10 / b, b) + to_string(num10%b);
	}
}
bool pal(string s)
{
	for(int i = 0; i < s.length() / 2; ++i)
		if(s[i] != s[s.length() - 1 - i])
			return false;
	return true;
}
int main()
{
#ifndef HOME
	freopen("palsquare.in", "r", stdin);
	freopen("palsquare.out", "w", stdout);
#endif
	int b;
	cin >> b;
	for(int i = 1; i <= 300; ++i)
	{
		string sq_b = conv(i*i, b);
		if(pal(sq_b))
			cout << conv(i, b) << " " << sq_b << endl;
	}


	return 0;
}

