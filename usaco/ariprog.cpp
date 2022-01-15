/*
ID: robertl8
LANG: C++11
TASK: ariprog
*/
#include <bits/stdc++.h>

using namespace std;

bool bisquare[125005];

int main()
{
	ifstream cin("ariprog.in");
	ofstream cout("ariprog.out");

	int n, m;
	cin >> n >> m;
	for(int i = 0; i <= m; ++i)
		for(int j = 0; j <= m; ++j)
			bisquare[i*i + j*j] = 1;

	bool empty = 1;
	//a+0b a+1b a+2b a+3b ... a+(n-1)b <= 2*m*m
	for(int b = 1; (n-1)*b <= 2*m*m; ++b)
	{
		for(int a = 0; a + (n-1)*b <= 2*m*m; ++a)
		{
			if(!bisquare[a + b] || !bisquare[a])
				continue;
			bool ok = 1;
			for(int k = 0; k < n; ++k)
			{
				if(!bisquare[a + k*b])
				{
					ok = 0;
					break;
				}
			}
			if(ok)
			{
				cout << a << " " << b << endl;
				if(empty)
					empty = 0;
			}
		}
	}
	if(empty)
		cout << "NONE\n";

	return 0;
}
