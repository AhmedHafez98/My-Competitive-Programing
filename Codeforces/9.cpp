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
		int n, d;
	cin >> n >> d;
	vector < pair < ll, ll>>v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i].first >> v[i].second;
	sort(all(v));
	int l = 0, r = 0;
	ll ans = 0, mx = 0;
	while (l < n)
	{
		while (r < n&&v[r].first - v[l].first < d)
		{
			ans += v[r].second;
			r++;
		}
		mx = max(ans, mx);
		ans -= v[l].second;
		l++;
	}
	cout << mx << endl;
}