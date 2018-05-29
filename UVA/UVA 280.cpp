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
int n;
vector<vector<int>>adj;
vector<int>vis;
void dfs(int node)
{
	if (vis[node])
		return;
	vis[node] = !vis[node];
	for (int i = 0; i < sz(adj[node]); i++)
	{
		if (!vis[adj[node][i]])
			dfs(adj[node][i]);
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
	while (cin >> n)
	{
		if (!n)
			break;
		adj = vector<vector<int>>(n+1);
		bool f=0;
		int x;
		int s;
		while (cin >> x)
		{
			if (!f&&x)
			{
				f = 1;
				s = x;
			}
			else if (!f&&!x)
				break;
			else if (f&&x)
				adj[s].push_back(x);
			else f = 0;
		}
		int q;
		cin >> q;
		while (q--)
		{
			int x;
			cin >> x;
			vis = vector<int>(n+1, 0);
			for (int i = 0; i < sz(adj[x]); i++)
			{
				if (!vis[adj[x][i]])
				dfs(adj[x][i]);
			}
			vector<int>ans;
			for (int i = 1; i <= n; i++)
			{
				if (!vis[i])
					ans.push_back(i);
			}
			if (sz(ans))
				cout << sz(ans) << ' ';
			else
				cout << sz(ans);
			for (int i = 0; i < sz(ans) ; i++)
			{
				if (i != sz(ans) - 1)
					cout << ans[i] << ' ';
				else
					cout << ans[i];
			}
			cout << endl;
		}

	}
	
}