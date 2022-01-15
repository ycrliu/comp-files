#include <bits/stdc++.h>

using namespace std;
using ll = long long;

map<string, string> parent;

int main()
{
	if(fopen("family.in", "r"))
	{
		freopen("family.in", "r", stdin);
		freopen("family.out", "w", stdout);
	}
	int n;
	string a, b;
	cin >> n >> a >> b;
	for(int i = 0; i < n; i++)
	{
		string par, child;
		cin >> par >> child;
		parent[child] = par;
	}

	// find out which cow is higher on the family tree
	// da and db = depth of a and b from root
	int da = 0, db = 0;
	string pa = parent[a], pb = parent[b];
	while(pa != "")
	{
		pa = parent[pa];
		da++;
	}
	while(pb != "")
	{
		pb = parent[pb];
		db++;
	}

	// brute force to find the common ancestor
	// ca and cb = number of levels traversed from a and b
	string newa = da < db ? a : b;
	string newb = da < db ? b : a;
	pa = newa;
	int ca = 0;
	bool common_ancestor = false;
	while(pa != "")
	{
		pb = newb;
		int cb = 0;
		while(pb != "" && pb != pa)
		{
			pb = parent[pb];
			cb++;
		}
		if(pa == pb)
		{
			common_ancestor = true;
			if(ca == cb && ca == 1) // sibling
			{
				cout << "SIBLINGS\n";
			}
			else if(ca == 0 || ca == 1) // mother: ca==0, aunt: ca==1
			{
				cout << newa << " is the ";
				string prefix = "";
				//if the elder is an aunt
				if(ca == 1)
				{
					cb -= 2;
				}
				//if the elder is a mother
				if(ca == 0)
				{
					cb--;
				}
				if(ca == 0 && cb >= 1)
				{
					prefix = "grand-" + prefix;
					cb--;
				}
				//record lineage
				while(cb > 0)
				{
					prefix = "great-" + prefix;
					cb--;
				}
				cout << prefix << (ca == 0 ? "mother" : "aunt") << " of " << newb << "\n";
			}
			else // cousins
			{
				cout << "COUSINS\n";
			}
			break;
		}
		pa = parent[pa];
		ca++;
	}
	if(!common_ancestor)
	{
		cout << "NOT RELATED\n";
	}
	return 0;
}

