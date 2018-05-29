#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#define all(v) ((v).begin()),((v).end())
#define allr(v)	     ((v).rbegin()), ((v).rend())
#define sz(v) ((int)(v).size())
#define clr(v, d)        memset(v, d, sizeof(v))
#define JSE ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MP(i,j) make_pair(int i,int j);
typedef long long ll;
typedef unsigned long long ull;
typedef  double ld;
const double PI = acos(-1.0);
int dx[]{-1,0,1,0,-1,-1,1,1};
int dy[]{0,1,0,-1,-1,1,1,-1};
void file(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);// freopen("output.txt", "w", stdout);
#endif
}
int n, m, k;
char adj[2000][2000];
int vis[2000][2000];
int cnt = 1;
int ans;
bool valid(int i, int j)
{
	return i >= 0  &&j >= 0 && i < n&&j < m;
}
void dfs(int i, int j)
{
	if (!valid(i, j)||vis[i][j])
		return;
	if (adj[i][j] == '*')
	{
		ans++; return;
	}
	vis[i][j] = cnt;
	for (int x = 0; x < 4; x++)
	{
		if (!vis[i+dx[x]][j+dy[x]])
			dfs(i + dx[x], j + dy[x]);
	}
}
int dfs2(int i, int j)
{
	ans=0;
	dfs(i, j);
	return ans;
}
int main()
{
	//cout << setprecision(20) << fixed;
	JSE
		file();
	//	freopen("friday.in", "r", stdin);
	///////////

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> adj[i][j];
	}
	map<int, int>mp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (adj[i][j] == '.'&&!vis[i][j])
			{
				mp[cnt] = dfs2(i, j);
				cnt++;
			}
		}
	}
	while (k--)
	{
		int x, y;
		cin >> x >> y;
		cout << mp[vis[x - 1][y - 1]] << endl;
	}

}