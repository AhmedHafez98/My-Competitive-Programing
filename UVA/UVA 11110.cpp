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
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,-1,1 };
void fast()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int n;
int adj[101][101];
int vis[101][101];
bool valid(int i, int j)
{
	return i >= 1 && j >= 1 && i <= n && j <= n;
}
void dfs(int x, int y)
{
	if (!valid(x, y) || vis[x][y])
		return;
	vis[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		int fx = x + dx[i], fy = y + dy[i];
		if(adj[x][y]==adj[fx][fy])
		dfs(fx, fy);
	}

}
int main()
{
	fast();
	file();
	///////////////////
	while (cin >>n)
	{
		cin.ignore();
		if (!n)
			break;
		memset(adj, 0, sizeof(adj));
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n - 1; i++)
		{
			string s;
			getline(cin, s);
			s.push_back(' ');
			vector<int>v;
			int u=0;
			for (int j = 0; j < sz(s); j++)
			{
				if (s[j] == ' ')
				{
					if(u!=0)
					v.push_back(u);
					u = 0;
				}
				else
				{
					u *= 10;
					u += s[j] - '0';
				}
			}
			for (int j = 0; j < sz(v); j += 2)
			{
				adj[v[j]][v[j + 1]] = i + 1;
			}

		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				if (!adj[i][j])
					adj[i][j] = n;
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (!vis[i][j])
				{
					cnt++;
					dfs(i, j);
				}
			}
		}
		cout << (cnt == n ? "good" : "wrong") << endl;
	}

	return 0;
}
