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
bool check(string &a, string &b)
{
	bool f = 1;
	for (int i = 0; i < sz(a); i++)
	{
		if (a[i] != b[i%sz(b)])
		{
			f = 0; break;
		}
	}
	return f;
}
int main()
{
	//cout << setprecision(7) << fixed;
	JSE
		//	file();
		//  freopen("friday.in", "r", stdin);
		string s, t;
	cin >> s >> t;
	string val; int ans = 0;
	val += s[0];
	for (int i = 1; i < min(sz(s), sz(t)); i++)
	{


		if (sz(s) % i == 0 && sz(t) % i == 0)
		{
			if (check(s, val) && check(t, val))
			{
				ans++;
			}

		}
		val += s[i];
	}
	if (sz(s) % sz(val) == 0 && sz(t) % sz(val) == 0)
	{
		if (check(s, val) && check(t, val))
		{
			ans++;
		}
	}
	cout << ans << endl;
}