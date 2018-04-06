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
int n;
int a[17];
bool vis[17];
vector<int>v;
bool prime(int x)
{
	for (int i = 2; i*i <= x; i++)
	{
		if (x%i == 0)
			return 0;
	}
	return 1;

}
void solve(int cnt, int last)
{
	if (cnt == n-1)
	{
		if (prime(1 + v[sz(v) - 1]))
		{
			cout << 1 << ' ';
			for (int i = 0; i < sz(v)-1; i++)
				cout << v[i] << ' ';
			cout <<v[sz(v)-1]<< endl;

		}
		
		return;
	}
	for (int j = 0; j < n-1; j++)
	{
		if (!vis[j] && prime(last + a[j]))
		{
			vis[j] = 1;
			v.push_back(a[j]);
			solve(cnt + 1, a[j]);
			v.pop_back();
			vis[j] = 0;
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
	for (int i = 2; i <= 16; i++)
		a[i - 2] = i;
	int cas = 1;
	while (cin >> n)
	{
		if (cas != 1)
			cout << endl;
		cout << "Case " << cas++ << ":" << endl;
		v.clear();
		clr(vis, 0);
		solve(0, 1);
		
	}
	




}