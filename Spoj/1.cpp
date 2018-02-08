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
bool prime(ll x)
{
	if (x == 1)
		return 0;
	for (ll i = 2; i*i <= x; i++)
	{
		if (x%i == 0)
			return 0;
	}
	return 1;
}
int main()
{
	//cout << setprecision(7) << fixed;
	JSE
		//	file();
		//  freopen("friday.in", "r", stdin);
		///////////

		int t;
	cin >> t;
	while (t--)
	{
		ll n, m;
		cin >> m >> n;
		for (int i = m; i <= n; i++)
		{
			if (prime(i))
				cout << i << endl;
		}
	}
	return 0;
}