/*
ID: robertl8
LANG: C++11
TASK: dualpal
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
	freopen("dualpal.in", "r", stdin);
	freopen("dualpal.out", "w", stdout);
#endif
	int n, s;
	cin >> n >> s;
	for(int i = s + 1; n; ++i)
	{
		int cnt = 0;
		for(int b = 2; b <= 10; ++b)
		{
			if(pal(conv(i, b)))
				++cnt;
			if(cnt == 2)
				break;
		}
		if(cnt == 2)
		{
			--n;
			cout << i << endl;
		}
	}
	return 0;
}

