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
vector<vector<int>>adj;
vector<int>idx, low, art,vis;
map<pair<int, int>, bool>brid;
int tim, ch;
void dfs(int u, int p)
{
	idx[u] = low[u] = ++tim;
	for (int i = 0; i < sz(adj[u]); i++)
	{
		int v = adj[u][i];
		if (idx[v] == 0)
		{
			if (p == -1)
				++ch;
			dfs(v, u);

			low[u] = min(low[u], low[v]);
			if (low[v] > idx[u])
			{
				brid[{u, v}] = 1;
				brid[{v, u}] = 1;
			}
			if (low[v] >= idx[u])
				art[u] = 1;
		}
		else if (v != p)
			low[u] = min(low[u], idx[v]);
	}
}
void dfs2(int u)
{
	vis[u] = tim;
	for (int &v : adj[u])
	{
		if (!vis[v] && brid[{u, v}])
			dfs2(v);
	}
}
int main()
{
	fast();
	file();
	///////////////////
	int r, c, q;
	while (cin >> r >> c >> q)
	{
		if (r + c + q == 0)
			break;
		adj = vector<vector<int>>(r + 1);
		for (int i = 0; i < c; i++)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		idx.clear();
		low.clear();
		art.clear();
		vis.clear();
		vis.resize(r + 1);
		brid.clear();
		
		ch = 0;
		tim = 0;
		idx.resize(r + 1);
		low.resize(r + 1);
	
		art = vector<int>(r + 1, 0);
		dfs(1, -1);
		art[1] = ch > 1;
		tim = 0;
		for (int i = 1; i <= r; i++)
		{
			if (!vis[i])
			{
				++tim;
				dfs2(i);
			}
		}
		for (int i = 0; i < q; i++)
		{
			int u, v;
			cin >> u >> v;
			if (vis[u] == vis[v])
				cout << "Y" << endl;
			else
				cout << "N" << endl;
		}
		cout << "-" << endl;

	}


	return 0;
}
