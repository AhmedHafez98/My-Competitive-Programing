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
int n, m;
vector<vector<int>>adj;
stack<int>st;
vector<int>vis;
void dfs(int u)
{
	vis[u] = 1;
	for (int &v : adj[u])
	{
		if (!vis[v])
			dfs(v);
	}
	st.push(u);
}
void dfs2(int u)
{
	vis[u] = 1;
	for (int &v : adj[u])
		if (!vis[v])
			dfs(v);
}
int main()
{
	fast();
	file();
	///////////////////
	int t;
	cin >> t;
	while (t--)
	{
		
		cin >> n >> m;
		adj = vector<vector<int>>(n + 1);
		vis = vector<int>(n + 1);
		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		for (int i = 1; i <= n; i++)
		{
			if(!vis[i])
			dfs(i);
		}
		vis.clear();
		vis.resize(n + 1);
		int cnt = 0;
		while (sz(st))
		{
			int u = st.top();
			st.pop();
			if (!vis[u])
			{
				cnt++;
				dfs2(u);
			}
		}
		cout << cnt << endl;

	}


	return 0;
}