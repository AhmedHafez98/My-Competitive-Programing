﻿#define _CRT_SECURE_NO_WARNINGS
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
		map<char, bool>mp;
	mp['A'] = 1;
	mp['H'] = 1;
	mp['I'] = 1;
	mp['M'] = 1;
	mp['O'] = 1;
	mp['T'] = 1;
	mp['U'] = 1;
	mp['V'] = 1;
	mp['W'] = 1;
	mp['X'] = 1;
	mp['Y'] = 1;
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		bool f = 1;
		for (int i = 0; i < sz(s); i++)
		{
			if (mp[s[i]] != 1)
			{
				f = 0; break;
			}
		}
		if (f)
		{
			string x = s;
			reverse(all(x));
			if (x == s)
				cout << "yes" << endl;
			else
				cout << "no" << endl;
		}
		else
			cout << "no" << endl;
	}
}