#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#define all(v) ((v).begin()),((v).end())
#define allr(v)	     ((v).rbegin()), ((v).rend())
#define sz(v) ((int)(v).size())
#define clr(v, d)        memset(v, d, sizeof(v))
#define JSE ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
ll mod = ll(1e9 + 7);
typedef  double ld;
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
void file(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); //freopen("out.txt", "w", stdout);  
#endif
}

int main()
{
	cout << setprecision(7) << fixed;
	//JSE
	//file();
	//	freopen("friday.in", "r", stdin);
	///////////
	vector<ll>v(5);
	for (int i = 0; i < 5; i++)
		cin >> v[i];
	sort(all(v));
	ll mn = 0, mx = 0;
	mn += v[0] + v[1] + v[2] + v[3];
	mx += v[4] + v[1] + v[2] + v[3];
	cout << mn << ' ' << mx << endl;
}