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
		string s;
	cin >> s;
	string a, b, c, d, e;
	int idx = s.find("username");
	int id = s.find("pwd");
	for (int i = idx + 9; i<id - 1; i++)
		a += s[i];
	idx = s.find("pwd");
	id = s.find("profile");
	for (int i = idx + 4; i<id - 1; i++)
		b += s[i];
	idx = s.find("profile");
	id = s.find("role");
	for (int i = idx + 8; i<id - 1; i++)
		c += s[i];
	idx = s.find("role");
	id = s.find("key");
	for (int i = idx + 5; i<id - 1; i++)
		d += s[i];
	idx = s.find("key");
	for (int i = idx + 4; i<sz(s); i++)
		e += s[i];
	cout << "username: " << a << endl;
	cout << "pwd: " << b << endl;
	cout << "profile: " << c << endl;
	cout << "role: " << d << endl;
	cout << "key: " << e << endl;
}