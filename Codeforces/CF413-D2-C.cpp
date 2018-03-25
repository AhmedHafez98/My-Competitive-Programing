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
struct node{
	int x, y;
};
bool operator < (node a, node b)
{
	if (a.x == b.x)
		return a.y>b.y;
	return a.x < b.x;
}
int main()
{
	//cout << setprecision(20) << fixed;
	// negative MOD (a%x+x)%x;
	
	//	freopen("friday.in", "r", stdin);
	///////////
	file();
	fast
		int n, m;
	cin >> n >> m;
	vector<ll>v(n);
	ll point = 0;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	map<ll, bool>mp;
	for (int i = 0; i < m; i++)
	{
		int x;
		cin >> x;
		mp[x - 1] = 1;
	}
	vector<ll>ac;
	for (int i = 0; i < n; i++)
	{
		if (mp[i])
			ac.push_back(v[i]);
		else
			point += v[i];
	}
	sort(allr(ac));
	for (int i = 0; i < m; i++)
	{
		if (point>ac[i])
			point *= 2;
		else
			point += ac[i];
	}
	cout << point << endl;

	return 0;
}