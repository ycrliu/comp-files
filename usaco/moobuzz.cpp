#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;

typedef pair<int, int> ii;

int main()
{
#ifndef HOME
	freopen("moobuzz.in", "r", stdin);
	freopen("moobuzz.out", "w", stdout);
#endif
	int n;
	cin >> n;
	int cycle_index = n % 16;
	int cycle_num = n / 16;
	int cycle_row = -1;
	if(cycle_index <= 5)
		cycle_row = 1;
	else if(cycle_index <= 11)
		cycle_row = 2;
	else
		cycle_row = 3;
	long long digits = 3 * cycle_num;
	if(cycle_row == 2)
		digits ++;
	else if(cycle_row == 3)
		digits += 2;
	int last_digits[] = {1, 2, 4, 7, 8, 1, 3, 4, 6, 7, 9, 2, 3, 6, 8, 9};
	int last_dig = last_digits[cycle_index - 1];
	if(digits != 0)
		cout << digits;
	cout << last_dig << endl;
	return 0;
}
