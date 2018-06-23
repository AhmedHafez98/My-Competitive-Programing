#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>
using namespace std;
#define all(v) ((v).begin()),((v).end())
#define allr(v)	     ((v).rbegin()), ((v).rend())
#define sz(v) ((int)(v).size())
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef  double ld;
const double PI = acos(-1.0);
const int OO = 1e7;
void file() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);  
#endif
}
void fast()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int n, m;
vector<int>adj[1001];
vector<int>idx, low,vis;
vector<pair<int, int>>br;
int tim;
vector<pair<int, int>>ans;
void dfs(int u, int p)
{
	idx[u] = low[u] = ++tim;
	vis[u] = 1;
	for (int i = 0; i < sz(adj[u]); i++)
	{
		int v = adj[u][i];
		if (idx[v] == 0)
		{
				ans.push_back({ u,v });
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] > idx[u])
			{
				br.push_back({ v,u });
			}
		}
		else if (v != p)
		{
			low[u] = min(low[u], idx[v]);
			if (vis[v])
			ans.push_back({ u,v });
		}
		
	}
	vis[u] = 0;
	
}
int main()
{
	fast();
	file();
	///////////////////
	int T = 0;
	while (cin >> n >> m)
	{
		if (n + m == 0)
			break;
		idx.clear();
		low.clear();
		vis.clear();
		br.clear();
		ans.clear();
		idx.resize(n + 1);
		low.resize(n + 1);
		vis.resize(n + 1);
		for (int i = 1; i <= n; i++)
			adj[i].clear();
		tim = 0;
		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		dfs(1, -1);
		for (int i = 0; i < sz(br); i++)
		{
			ans.push_back(br[i]);
		}
		cout << ++T << endl << endl;
		for (int i = 0; i < sz(ans); i++)
		{
			cout << ans[i].first << ' ' << ans[i].second << endl;
		}
		cout << '#' << endl;
	}
	return 0;
}