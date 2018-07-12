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
 struct point
{
	int x, y;
	ll d;
};
bool ch(point a, point b)
{
	ll mnx = a.x - a.d, mxx = a.x + a.d;
	ll mny = a.y - a.d, mxy = a.y + a.d;
	return b.x <= mxx && b.x >= mnx && b.y <= mxy && b.y >= mny;
}
vector<int>vis;
bool f = 0;
stack<int>st;
void dfs(int u)
{
	vis[u] = 1;
	for (int &v : adj[u])
		if (!vis[v])
			dfs(v);
	if (f)
		st.push(u);
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
		int n;
		cin >> n;
		adj = vector<vector<int>>(n + 1);
		vector<point>v;

		for (int i = 0; i < n; i++)
		{
			point u;
			
			cin >> u.x >> u.y >> u.d;
			u.d /= 2;
			v.push_back(u);
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (ch(v[i], v[j])&&i!=j)
				{
					adj[i+1].push_back(j+1);
					
				}
			}
		}
		f = 1;
		vis = vector<int>(n + 1, 0);
		for (int i = 1; i <= n; i++)
		{
			if (!vis[i])
				dfs(i);
		}
		f = 0;
		int cnt = 0;
		vis = vector<int>(n + 1);
		while (sz(st))
		{
			int u = st.top();
			st.pop();
			if (!vis[u])
			{
				cnt++;
				dfs(u);
			}
		}
		cout << cnt<< endl;
	}
	return 0;
}