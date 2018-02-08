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
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
void file(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
}
int b[6];
int main()
{
	//cout << setprecision(4) << fixed;
	JSE
		//file();
		//  freopen("friday.in", "r", stdin);
		///////////
		int a[6] = { 1, 1, 2, 2, 2, 8 };
	for (int i = 0; i < 6; i++)
	{
		cin >> b[i];
	}
	for (int i = 0; i < 6; i++)
	{
		cout << a[i] - b[i] << ' ';
	}
	cout << endl;
}