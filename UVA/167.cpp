#define _CRT_SECURE_NO_WARNINGS

#include<bits/stdc++.h>

using namespace std;

#define all(v) ((v).begin()),((v).end())
#define allr(v)	     ((v).rbegin()), ((v).rend())
#define sz(v) ((int)(v).size())
#define clr(arr, val)        memset(arr, val, sizeof(arr))
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

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

int a[8][8];
int col[8];
int d1[17], d2[17];
int vis[8][8];
ll mn = LLONG_MIN;
int cnt = 0;
void check(int i)
{
	if (i == 8)
	{
// culc
		ll sum = 0;
		for (int j = 0; j < 8; j++)
		{
			for (int k = 0; k < 8; k++)
			{
				if (v[j][k])
					cout << j << ' ' << k << endl;
			}
		}
		
		return;
	}
	for (int j = 0; j < 8; j++)
	{
		if (!col[j] && !d1[j - i + 8] && !d2[i + j])
		{
			vis[i][j] = 1;
			col[j] = 1;
			d1[j - i + 8] = 1;
			d2[i + j] = 1;
			check(i + 1);
			vis[i][j] = 0;
			col[j] = 0;
			d1[j - i + 8] = 0;
			d2[i + j] = 0;
		}
	}
}
int main()
{
	//cout << setprecision(7) << fixed;
	// negative MOD (a%x+x)%x;

	//	freopen("friday.in", "r", stdin);
	///////////

	file();
	fast
			int k;
		cin >> k;
		
		while (k--)
		{
			clr(col, 0);
			clr(d1, 0);
			clr(d2, 0);
			clr(vis, 0);
			mn = LLONG_MIN;
		for (int i = 0; i < 8;i++)
		for (int j = 0; j < 8; j++)
		cin >> a[i][j];
		check(0);

		}
		
	
}