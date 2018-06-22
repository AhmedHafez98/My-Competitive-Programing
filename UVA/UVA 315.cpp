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
vector<int>adj[10000];
vector<int>idx, low,art;
vector<pair<int, int>>brid;
int tim,ch;
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
				brid.push_back({ u,v });
			if (low[v] >= idx[u])
				art[u] = 1;
		}
		else if (v != p)
			low[u] = min(low[u], idx[v]);
	}
}
int main()
{
	fast();
	file();
	///////////////////
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < 1000; i++)
			adj[i].clear();
		idx.clear();
		low.clear();
		art.clear();
		brid.clear();
		ch = 0;
		tim = 0;
		idx.resize(n + 1);
		low.resize(n + 1);
		art = vector<int>(n + 1, 0);
		if (!n)
			break;
	
	
		
		string s;
		cin.ignore();
		while (getline(cin, s))
		{
			if (s == "0")
				break;
			s += ' ';
			int x = 0;
			bool f = 0;
			int u;
			for (int i = 0; i < sz(s); i++)
			{
				if (s[i] == ' ')
				{
					if (!f)
					{
						f = 1;
						u = x;
					}
					else
					adj[u].push_back(x),adj[x].push_back(u);
					x = 0;
				}
				else
				{
					x *= 10;
					x += (s[i] - '0');
				}

			}
		}
	
		dfs(1, -1);
		art[1] = ch > 1;
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			cnt += art[i];
		cout << cnt << endl;
	}

	return 0;
}