#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include<cctype>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
void fast()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

using namespace std;
int main()
{
	string s;
	int n;
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		isupper(s[i]) ? s[i]=tolower(s[i]) : i=i;
	sort(s.begin(), s.end());
	for (int i = 0; i < s.length()-1; i++)
	{
		if (s[i] == s[i + 1])
		{
			s.erase(i, 1);
			i--;
		}
		if (s[i + 1] == string::npos)
			break;
	}
	s == "abcdefghijklmnopqrstuvwxyz" ? cout << "YES" : cout << "NO";

	return 0;
}