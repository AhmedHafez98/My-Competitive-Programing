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
struct node{
	int x, r;
	bool ch;
};
int main()
{
	//cout << setprecision(20) << fixed;
	// negative MOD (a%x+x)%x;
	
	//	freopen("friday.in", "r", stdin);
	///////////
	file();
	fast
		ll l, g;
	while (cin >> l >> g)
	{
		if (l + g == 0)
			break;
		vector<node>v(g);
		for (int i = 0; i < g; i++)
		{
			cin >> v[i].x >> v[i].r; v[i].ch = 1;
		}
		ll cur = 0;
		while (cur < l)
		{
			ll mx = INT_MIN;
			int idx = 0;
			bool ch = 0;
			for (int i = 0; i < g; i++)
			{
				if (v[i].x - v[i].r <= cur&&v[i].ch)
				{
					if (v[i].x + v[i].r > mx)
					{
						mx = v[i].x + v[i].r;
						idx = i;
						ch = 1;
					}
				}
			}
			if (ch == 0)
				break;
			cur = v[idx].x + v[idx].r;
			v[idx].ch = 0;
		}
		if (cur < l)
			cout << -1 << endl;
		else
		{
			int cnt = 0;
			for (int i = 0; i < g; i++)
			{
				if (v[i].ch == 1)
					cnt++;
			}
			cout << cnt << endl;
		}

	}

	return 0;
}