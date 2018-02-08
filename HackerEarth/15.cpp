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
		int n;
	cin >> n;
	string s;
	cin >> s;
	string a;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'w')
			a += "vv";
		else
			a += s[i];
	}
	int mx = sz(a);
	int cnt = 0;
	//cout << a << endl;
	for (int i = 0; i < sz(a); i++)
	{
		if (a[i] == 'v'&&a[i + 1] == 'v')
			i++;
		cnt++;
	}
	cout << cnt << ' ' << mx << endl;
}