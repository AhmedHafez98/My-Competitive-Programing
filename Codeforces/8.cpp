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
ll dis(pair<ll, ll>a, pair<ll, ll>b) { return pow(a.first - b.first, 2) + pow(a.second - b.second, 2); }
vector<vector<pair<int, int>>>v(26);
bool a[26];
int main()
{
	//cout << setprecision(7) << fixed;
	JSE
		//		file();
		//  freopen("friday.in", "r", stdin);
		///////////
		int n, m, x;
	cin >> n >> m >> x;
	x *= x;
	vector<pair<int, int>>shift;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char a;
			cin >> a;
			if (a == 'S')
				shift.push_back(make_pair(i, j));
			else
				v[a - 'a'].push_back(make_pair(i, j));
		}
	}
	int q;
	cin >> q;
	string s;
	cin >> s;
	for (char i = 'a'; i <= 'z'; i++)
	{
		for (int j = 0; j < sz(v[i - 'a']); j++)
		{
			//cout << "ss" << endl;
			for (int k = 0; k < sz(shift); k++)
			{
				if (dis(v[i - 'a'][j], shift[k]) <= x)
				{
					a[i - 'a'] = 1;
					j = sz(v[i - 'a']);
					break;
				}
			}
		}
	}
	int cnt = 0;
	bool f = 1;

	for (int i = 0; i < q; i++)
	{
		if (sz(v[tolower(s[i]) - 'a']) == 0 || (isupper(s[i]) && sz(shift) == 0))
		{
			cnt = -1;
			break;
		}
		if (isupper(s[i]))
		{
			s[i] = tolower(s[i]);
			if (a[s[i] - 'a'] == 0)
				cnt++;
		}
	}
	cout << cnt << endl;



}