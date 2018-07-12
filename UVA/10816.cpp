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
#define clr(v, d)        memset(v, d, sizeof(v))
#define MP(i,j) make_pair(int i,int j);
typedef long long ll;
typedef unsigned long long ull;
typedef  double ld;
const ll OO = (ll)1e18;
const ll mod = (1e9) + 7;
const double PI = acos(-1.0);
int dx[]{ 0,0,1,-1 ,-1,-1,1,1 };
int dy[]{ -1, 1,0,0,-1,1,1,-1 };
ll pd(ll x) { if (x == 0)	return 1; if (x == 1) return 1; ull ans = 1; for (int i = 2; i <= x; i++) ans *= i; return ans; }
void file() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);  
#endif
}
void JSE()
{
#ifndef ONLINE_JUDGE
	cout << "success coming from your own direction ,don't stop, stand up and try again ('_')" << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;
#endif
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

}
bool f;
struct edge
{
	int to;
	ld dis, tem;

		bool operator <(const edge&e)const {
			
				return tem > e.tem;
		}
};
struct ed
{
	int to;
	ld dis, tem;
	bool operator <(const ed &e)const {
		return dis > e.dis;
	}
};

int main()
{
	cout << setprecision(1) << fixed;
	JSE();
	file();
	//	freopen("friday.in", "r", stdin);
	///////////
	int n, m;
	while (cin >> n >> m)
	{
		int s, t;
		cin >> s >> t;
		vector<vector<edge>>adj(n + 1);
		for (int i = 0; i < m; i++)
		{
			int u;
			edge e;
			cin >> u >> e.to >> e.tem >> e.dis;
			adj[u].push_back(e);
			swap(u, e.to);
			adj[u].push_back(e);
		}
		priority_queue<edge>pq;
		edge test;
		test.to = s, test.dis = 0, test.tem = 0;
		pq.push(test);
		vector<int>vis(n + 1, 0);
		ld mxr = 0;
		while (sz(pq))
		{
			edge u = pq.top();
			pq.pop();
			if (vis[u.to])
				continue;
			vis[u.to] = 1;
			mxr = max(mxr, u.tem);
			if (u.to == t)
				break;
			for (edge v : adj[u.to])
				pq.push(v);
		}
		priority_queue<ed>q;
		ed tes;
		tes.to = s, tes.dis = 0, tes.tem = 0;
		q.push(tes);
		vector<ld>dist(n + 1, 1e18);
		vector<int>prev(n + 1, -1);
		dist[s] = 0;
		vis = vector<int>(n + 1, 0);
		while (sz(q))
		{
			ed u = q.top(); q.pop();
			ed v;
			vis[u.to] = 1;
			for (int i=0;i<sz(adj[u.to]);i++)
			{
				v.to = adj[u.to][i].to;
				v.dis = adj[u.to][i].dis;
				v.tem = adj[u.to][i].tem;
				if (vis[v.to])continue;
				if (dist[v.to] > dist[u.to] + v.dis&&v.tem<=mxr)
				{
					v.dis = dist[v.to] = dist[u.to] + v.dis;
					prev[v.to] = u.to;
					q.push(v);
				}
			}

		}
		ld mxd = dist[t];
		vector<int>path;
		while (prev[t] != -1)
		{
			path.push_back(t);
			t = prev[t];
		}
		path.push_back(s);
		reverse(all(path));
		for (int i = 0; i < sz(path); i++)
		{
			if (i != sz(path) - 1)
				cout << path[i] << ' ';
			else cout << path[i] << endl;
		}
		cout << mxd << ' ' << mxr << endl;
	}
		
	

	return 0;
}
