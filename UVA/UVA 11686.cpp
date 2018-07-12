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
vector<vector<int>>adj;
stack<int>st;
vector<int>vis, inst;
int f;
void dfs(int u)
{
	if (vis[u] && inst[u])
	{
		f = 0;
		return;
	}
	if (vis[u])
		return;
	vis[u] = 1;
	inst[u] = 1;
	for (int &v : adj[u])
		dfs(v);
	inst[u] = 0;
	st.push(u);
}

int main()
{
	fast();
	file();
	///////////////////
	int n, m;
	while (cin >> n >> m)
	{
		if (n + m == 0)
			break;
		adj = vector<vector<int>>(n + 1);
		inst = vector<int>(n + 1);
		vis = vector<int>(n + 1);
		while (sz(st))
			st.pop();
		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);

		}
		f = 1;
		for (int i = 1; i <= n; i++)
		{
			if (!vis[i])
				dfs(i);
		}
		if (f)
			while (sz(st))
			{
				cout << st.top() << endl;
				st.pop();
			}
		else
			cout << "IMPOSSIBLE" << endl;

	}

	return 0;
}