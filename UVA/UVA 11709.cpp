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
	freopen("output.txt", "w", stdout);  
#endif
}
void fast()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int n, m, tim, cmp = 1;
vector<vector<int>>adj;
vector<int>idx, low, vis, comid;
stack<int>st;
void dfs(int u)
{
	idx[u] = low[u] = ++tim;
	vis[u] = 1;
	st.push(u);
	for (int i = 0; i < sz(adj[u]); ++i)
	{
		int v = adj[u][i];
		if (idx[v] == 0)
			dfs(v);
		if (vis[v])
			low[u] = min(low[u], low[v]);
	}
	if (idx[u] == low[u])
	{
		while (1)
		{
			int v = st.top();
			st.pop();
			vis[v] = 0;
			comid[v] = cmp;
			if (v == u)
				break;
		}
		cmp++;
	}
}
int main()
{
	fast();
	file();
	///////////////////
	while (cin >> n >> m)
	{
		if (n + m == 0)
			break;
		adj = vector<vector<int>>(n + 1);
		idx.clear();
		low.clear();
		vis.clear();
		comid.clear();
		tim = 0;
		cmp = 1;
		idx.resize(n + 1);
		low.resize(n + 1);
		vis.resize(n + 1);
		comid.resize(n + 1);
		while (sz(st))
			st.pop();
		map<string, int>mp;
		cin.ignore();
		for (int i = 0; i < n; i++)
		{
			string s;
			getline(cin, s);
			mp[s] = i+1;
		}
		for (int i = 0; i < m; i++)
		{
			string u, v;
			getline(cin, u);
			getline(cin, v);
			adj[mp[u]].push_back(mp[v]);
		}
		for (int i = 1; i <= n; i++)
		{
			if(idx[i]==0)
			dfs(i);
		}
		cout << cmp - 1 << endl;
	}
	return 0;
}