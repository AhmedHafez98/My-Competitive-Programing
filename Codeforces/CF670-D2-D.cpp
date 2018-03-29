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
struct asd
{
	ll x;
	ll y;
	double div;
};
bool operator <(asd a, asd b)
{
	if (a.div == b.div)
	{
		if (a.y == b.y)
			return a.x<b.x;
		return a.y < b.y;
	}
	return a.div < b.div;
}
bool f(vector<asd>&v, ll mid,ll k)
{
	for (int i = 0; i < sz(v) && v[i].div < mid; i++)
	{
		if (mid*v[i].x - v[i].y>k)
			return 0;
		k -= mid*v[i].x - v[i].y;
	}
	return 1;
}
int main()
{
	cout << setprecision(7) << fixed;
	// negative MOD (a%x+x)%x;

	//	freopen("friday.in", "r", stdin);
	///////////
	file();

	fast
		int n, k;
	cin >> n >> k;
	vector<asd>v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].x;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].y;
		v[i].div = v[i].y / (double)v[i].x;
	}
	sort(all(v));

	ll lo = 0, hi = 1e10, ans = 0;
	while (lo <= hi)
	{
		ll mid = (lo + hi) / 2;
		if (f(v, mid, k))
		{
			ans = mid;
			lo = mid + 1;
		}
		else
			hi = mid - 1;
	}
	cout << ans << endl;
	return 0;
}