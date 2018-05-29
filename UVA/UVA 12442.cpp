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
vector<int>vis,vis2;
vector<bool>inst;
map<int, int>mp;
int cnt, cn = 1;;
void dfs2(int node)
{
	if (vis2[node]!=-1)
		return;
	vis2[node] = cn;
	cnt++;
	for (int i = 0; i < sz(adj[node]); i++)
	{
		if (vis2[adj[node][i]]==-1)
			dfs2(adj[node][i]);
	}
}
void dfs(int node)
{
	if (vis[node] && inst[node])
	{
		cnt = 0;
		dfs2(node);
		mp[cn] = cnt;
		cn++;
		return;
	}
	if (vis[node])
		return;
	vis[node] = 1;
	inst[node] = 1;
	for (int i = 0; i < sz(adj[node]); i++)
	{
			dfs(adj[node][i]);
	}
	inst[node] = 0;
}
int dfsans(int node)
{
	if (vis2[node] != -1)
	{
		return vis2[node];
	}
		return vis2[node] = dfsans(adj[node][0]) + 1;
}
int main()
{
	//cout << setprecision(7) << fixed;
	// negative MOD (a%x+x)%x;

	//	freopen("friday.in", "r", stdin);
	///////////

	file();
	fast
		int t;
	cin >> t;
	for (int k = 1; k <= t; k++)
	{
		cin >> n;
		adj.clear();
		adj = vector<vector<int>>(n+1);
		vis = vector<int>(n + 1, 0);
		vis2 = vector<int>(n + 1, -1);
		inst = vector<bool>(n + 1, 0);
		for (int i = 0; i < n; i++)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		for (int i = 1; i <= n; i++)
		{
			if (!vis[i])
			{
				dfs(i);
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (vis2[i] != -1)
				vis2[i] = mp[vis2[i]]-1;
		}
		int mx = -1;
		int index = 1;
		for (int i = 1; i <= n; i++)
		{
			if (vis2[i] == -1)
			{
				vis2[i]=dfsans(i);
				
			}
			if (vis2[i] > mx)
			{
				mx = vis2[i];

				index = i;
			}

		}

		cout << "Case "<<k<<": "<<index << endl;
	}
}