#include <bits/stdc++.h>

using namespace std;

bool isCharGood[26], isCharBad[26];

int main()
{
	string goodCharsStr, patternStr;
	cin >> goodCharsStr >> patternStr;

	fill(begin(isCharBad), end(isCharBad), true);

	for(char c : goodCharsStr)
	{
		isCharGood[c - 'a'] = true;
		isCharBad[c - 'a'] = false;
	}

	int starLocation = patternStr.find("*");

	int numQueries;
	cin >> numQueries;
	for(; numQueries > 0; numQueries--)
	{
		string testStr;
		cin >> testStr;

		if(starLocation == -1)
		{
			// No star -- strings are static and must be equal length
			if(testStr.size() != patternStr.size())
			{
				cout << "NO\n";
				continue;
			}

			// Analyze the two strings from beginning to end
			bool match = true;
			for(int i = 0, j = 0; i < patternStr.size() && j < testStr.size(); i++, j++)
			{
				if(patternStr[i] == '?')
				{
					if(!isCharGood[testStr[j] - 'a'])
					{
						match = false;
						break;
					}
				}
				else if(patternStr[i] != testStr[j])
				{
					match = false;
					break;
				}
			}

			cout << (match ? "YES" : "NO") << endl;
		}
		else
		{
			// Eliminate the case where the star has a negative length
			if(testStr.size() < patternStr.size() - 1)
			{
				cout << "NO\n";
				continue;
			}

			bool match = true;

			// Analyze the two strings up to the location of the star
			for(int i = 0, j = 0; i < starLocation && j < starLocation; i++, j++)
			{
				if(patternStr[i] == '?')
				{
					if(!isCharGood[testStr[j] - 'a'])
					{
						match = false;
						break;
					}
				}
				else if(patternStr[i] != testStr[j])
				{
					match = false;
					break;
				}
			}

			if(!match)
			{
				cout << "NO\n";
				continue;
			}

			// Analyze the presumed "star segment" in the testStr
			int presumedLengthOfStarSegInTestStr = testStr.size() - (patternStr.size() - 1);
			for(int i = starLocation; i < starLocation + presumedLengthOfStarSegInTestStr; i++)
			{
				if(!isCharBad[testStr[i] - 'a'])
				{
					match = false;
					break;
				}
			}

			// Analyze the rest of the two strings from where the pointers previously left off
			for(int i = starLocation + 1, j = starLocation + presumedLengthOfStarSegInTestStr;
					i < patternStr.size() && j < testStr.size(); i++, j++)
			{
				if(patternStr[i] == '?')
				{
					if(!isCharGood[testStr[j] - 'a'])
					{
						match = false;
						break;
					}
				}
				else if(patternStr[i] != testStr[j])
				{
					match = false;
					break;
				}
			}

			cout << (match ? "YES" : "NO") << endl;
		}
	}
	return 0;
}

