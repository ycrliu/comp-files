/*
ID: robertl8
LANG: C++11
TASK: transform
*/
#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

typedef pair<int, int> ii;

int n;
bool eq(vector<vector<char>> a, vector<vector<char>> b)
{
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			if(a[i][j] != b[i][j])
				return false;
	return true;
}
vector<vector<char>> rotate(vector<vector<char>> a)
{
	vector<vector<char>> ret = a;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			ret[j][n - 1 - i] = a[i][j];
	return ret;
}
vector<vector<char>> reflect(vector<vector<char>> a)
{
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n / 2; ++j)
			swap(a[i][j], a[i][n - 1 - j]);
	return a;
}
int main()
{
#ifndef HOME
	freopen("transform.in", "r", stdin);
	freopen("transform.out", "w", stdout);
#endif
	cin >> n;
	vector<vector<char>> a(n, vector<char>(n, '\0')), b(n, vector<char>(n, '\0'));
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			cin >> a[i][j];
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			cin >> b[i][j];
	if(eq(rotate(a), b))
		cout << "1\n";
	else if(eq(rotate(rotate(a)), b))
		cout << "2\n";
	else if(eq(rotate(rotate(rotate(a))), b))
		cout << "3\n";
	else if(eq(reflect(a), b))
		cout << "4\n";
	else if(eq(rotate(reflect(a)), b) || eq(rotate(rotate(reflect(a))), b) || eq(rotate(rotate(rotate(reflect(a)))), b))
		cout << "5\n";
	else if(eq(a, b))
		cout << "6\n";
	else
		cout << "7\n";
	return 0;
}

