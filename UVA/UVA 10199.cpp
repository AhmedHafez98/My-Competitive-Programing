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
map<string, vector<string>>adj;
map<string, int>idx, low;
int tim,ch;
set<string>art;
void dfs(string u,string p)
{
	low[u] = idx[u] = ++tim;
	for (auto &v: adj[u])
	{
		if (idx[v] == 0)
		{
			if (p == "-1")
				++ch;
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] >= idx[u])
				art.insert(u);
		}
		else if (p != v)
			low[u] = min(low[u], idx[v]);
	}

}
int main()
{
	fast();
	file();
	///////////////////
	int n;
	int T = 0;
	while (cin >> n)
	{
		if (!n)
			break;
		if(T!=0)
			cout << endl;
		adj.clear();
		vector<string>nod(n);
		
		idx.clear();
		low.clear();
		art.clear();
		for (int i = 0; i < n; i++)
			cin >> nod[i];
		int m;
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			string u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for (int i = 0; i < n; i++)
		{
			tim = ch = 0;
			if (idx[nod[i]] == 0)
			{
				dfs(nod[i], "-1");
				if (ch <= 1)
				{
					if (art.find(nod[i]) != art.end())
						art.erase(art.find(nod[i]));
				}
			}
		}
		
		cout << "City map #" << ++T << ": " << sz(art) << " camera(s) found" << endl;
		for (auto i=art.begin();i!=art.end();i++)
		{
			cout << *i << endl;
		}
		

	}
	return 0;
}