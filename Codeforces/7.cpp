#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#define all(v) ((v).begin()),((v).end())
#define allr(v)      ((v).rbegin()), ((v).rend())
#define sz(v) ((int)(v).size())
#define clr(v, d)        memset(v, d, sizeof(v))
#define JSE ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl  "\n"
typedef long long ll;
typedef unsigned long long ull;
ll mod = ll(1e9 + 7);
typedef  double ld;
void file(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
}
int main()
{
	//cout << setprecision(7) << fixed;
	JSE
		//	file();
		//  freopen("friday.in", "r", stdin);
		///////////
		string s;
	cin >> s; int cnt = 0;
	for (int i = 1; i < sz(s); i++)
	{
		if (s[i] == s[i - 1] && cnt < 1)
			cnt++;
		else if (s[i] == s[i - 1])
		{
			s[i - 1] = '_';
		}
		else cnt = 0;
	}
	string x;

	for (int i = 0; i < sz(s); i++)
	{
		if (s[i] != '_')
			x.push_back(s[i]);
	}
	for (int i = 0; i < sz(x) - 3; i++)
	{
		if (x[i] == x[i + 1] && x[i + 2] == x[i + 3])
			x[i + 3] = '_';
	}
	s.clear();
	for (int i = 0; i < sz(x); i++)
	{
		if (x[i] != '_')
			s.push_back(x[i]);
	}
	cout << s << endl;
}