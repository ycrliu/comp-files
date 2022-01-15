#include <bits/stdc++.h>

using namespace std;
using ll = long long;

map<string, int> year_of;

int main()
{
	int n;
	cin >> n;
	information();
	map<string, int> age_relative_to_bessie;
//	age_relative_to_bessie["Bessie"] = 0;
	for(int i = 0; i < n; i++)
	{
		string a1, a2, comp, animal, trash;
		cin >> a1;
		for(int j = 0; j < 2; j++)
			cin >> trash;
		cin >> comp;
		cin >> animal;
		for(int j = 0; j < 2; j++)
			cin >> trash;
		cin >> a2;
		
		if(comp == "previous")
		{
			age_relative_to_bessie[a2] - year_of[animal]
		}
		else
		{

		}
	}
	return 0;
}

void information()
{
	year_of["Ox"] = 0;
	year_of["Tiger"] = 1;
	year_of["Rabbit"] = 2
	year_of["Dragon"] = 3;
	year_of["Snake"] = 4;
	year_of["Horse"] = 5;
	year_of["Goat"] = 6;
	year_of["Monkey"] = 7;
	year_of["Rooster"] = 8;
	year_of["Dog"] = 9;
	year_of["Pig"] = 10;
	year_of["Rat"] = 11;
}
