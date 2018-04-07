#define _CRT_SECURE_NO_WARNINGS

#include<bits/stdc++.h>

using namespace std;

#define all(v) ((v).begin()),((v).end())
#define allr(v)	     ((v).rbegin()), ((v).rend())
#define sz(v) ((int)(v).size())
#define clr(arr, val)        memset(arr, val, sizeof(arr))
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;
typedef unsigned long long ull;
typedef  double ld;

const ll OO = (ll)1e18;
const ll mod = (1e9) + 7;
const ld PI = acos(-1.0);
const ld EPS = 1e-8;

int dx[]{-1, -1, -1, 0, 0, 1, 1, 1}; // Dir array
int dy[]{-1, 0, 1, -1, 1, -1, 0, 1}; // Dir array

void file(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);

	//freopen("output.txt", "w", stdout);

#endif
}
ll f(ll x)
{
	int num = 0;
	ll y = x;
	while (y)
	{
		num += y % 10;
		y /= 10;
	}
	return x*x + num*x;
}

int main()
{
	//cout << setprecision(20) << fixed;
	// negative MOD (a%x+x)%x;
	file();
	//	freopen("friday.in", "r", stdin);
	///////////
	fast
		ll n;
	cin >> n;
	ll ans = -1;
	for (ll x = sqrt(n); x >= sqrt(n)-1000; x--)
	{
		int num = 0;
		ll y = x;
		while (y)
		{
			num += y % 10;
			y /= 10;
		}
		if (x*x + num*x == n)
		{
			cout << x << "\n"; return 0;
		}

	}
	cout << ans << endl;

	return 0;
}
