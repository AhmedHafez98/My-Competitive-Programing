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

	freopen("output.txt", "w", stdout);

#endif
}


int main()
{
	//cout << setprecision(20) << fixed;
	// negative MOD (a%x+x)%x;
	file();
	//	freopen("friday.in", "r", stdin);
	///////////
	fast
		int t;
	int idx = 1;
	cin >> t;
	while (t--)
	{
		int n, p, q;
		cin >> n >> p >> q;
		vector<int>v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		int l = 0, r = 0,sum=0,mx=0;
		while (l < n)
		{
			while (r < n&&sum+v[r]<=q)
			{
				sum += v[r];
				r++;
			}
			mx = max(mx, r - l);
			sum -= v[l];
			l++;
		}
		mx = max(mx, r - l);
		if (mx>p)
			cout << "Case " << idx++ << ": " << p << endl;
		else 
			cout << "Case " << idx++ << ": " << mx << endl;
	}
	return 0;
}