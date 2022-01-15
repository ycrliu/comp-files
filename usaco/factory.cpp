#include <bits/stdc++.h>

using namespace std;

int incoming[105], outgoing[105];
int main()
{
	ifstream cin("factory.in");
	ofstream cout("factory.out");
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		outgoing[a]++;
		incoming[b]++;
	}
	int sink = -1;
	for (int i = 1; i <= n; i++)
	{
		if (outgoing[i] == 0 && sink != -1)
		{
			// can't have two sinks because then neither of the two sinks would satisfy
			// the requirement of every edge leading into it
			sink = -1;
			break;
		}
		if (outgoing[i] == 0)
		{
			sink = i;
		}
	}
	cout << sink << endl;
	return 0;
}
