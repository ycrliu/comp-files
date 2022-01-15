/*
ID: robertl8
LANG: C++11
TASK: crypt1
*/
#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

typedef pair<int, int> ii;

vector<int> ar;

int len(int num)
{
	int len = 0;
	do
	{
		++len;
		num /= 10;
	} while(num);
	return len;
}
bool ok(int num)
{
	while(num)
	{
		int dig = num % 10;
		if(find(ar.begin(), ar.end(), dig) == ar.end())
			return false;
		num /= 10;
	}
	return true;
}
int main()
{
#ifndef HOME
	freopen("crypt1.in", "r", stdin);
	freopen("crypt1.out", "w", stdout);
#endif
	int n;
	cin >> n;
	for(int i = 0, ai; i < n; ++i)
	{
		cin >> ai;
		ar.push_back(ai);
	}
	int cnt = 0;
	for(int a : ar)
	{
		for(int b : ar)
		{
			for(int c : ar)
			{
				for(int d : ar)
				{
					for(int e : ar)
					{
						int top = c + 10*b + 100*a;
						int bot = e + 10*d;
						int prod1 = top * e;
						int prod2 = top * d;
						if(ok(prod1) && ok(prod2) && ok(top * bot) && len(prod1) == 3 && len(prod2) == 3)
						{
							++cnt;
						}
					}
				}
			}
		}
	}
	cout << cnt << endl;
	return 0;
}

