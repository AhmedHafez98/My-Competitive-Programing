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
	//freopen("input.txt", "r", stdin);

	//freopen("output.txt", "w", stdout);

#endif
}
pair<bool,ll> f(vector<int>&v,ll mid,ll s)
{
	
		ll sum = 0;
		vector < ll>ch(sz(v),0);
		for (int i = 0; i < sz(v); i++)
		{
			ch[i] += v[i] + (i + 1)*mid;
		}
		sort(all(ch));
		for (int i = 0; i < mid; i++)
		{
			sum += ch[i];
		}
		
	return make_pair(sum <= s,sum);
}
int main()
{
	//cout << setprecision(20) << fixed;
	// negative MOD (a%x+x)%x;

	//	freopen("friday.in", "r", stdin);
	///////////
	file();

	fast
		ll n ,s;
	cin >> n >> s;
	vector<int>v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	//sort(all(v));
	ll lo = 0, hi = n, mx = 0, sum = 0;
	while (lo <= hi)
	{
		ll mid = (lo + hi) / 2;
		if (f(v, mid, s).first)
		{
			mx = mid;
			sum = f(v, mid, s).second;
			lo = mid + 1;
		}
		else
			hi = mid - 1;
	}
	cout << mx << ' ' << sum << endl;
	return 0;
}