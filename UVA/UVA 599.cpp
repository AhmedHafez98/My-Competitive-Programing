#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#define all(v) ((v).begin()),((v).end())
#define allr(v)	     ((v).rbegin()), ((v).rend())
#define sz(v) ((int)(v).size())
#define clr(v, d)        memset(v, d, sizeof(v))
#define JSE ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MP(i,j) make_pair(int i,int j);
typedef long long ll;
typedef unsigned long long ull;
typedef  double ld;
const ll OO = (ll)1e18;
const ll mod = (1e9) + 7;
const double PI = acos(-1.0);
int dx[]{-1, -1, -1, 0, 0, 1, 1, 1};
int dy[]{-1, 0, 1, -1, 1, -1, 0, 1};
ld dis(pair<ld, ld>a, pair<ld, ld>b) { return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2)); }
ll pd(ll x) { if (x == 0)	return 1; if (x == 1) return 1; ull ans = 1; for (int i = 2; i <= x; i++) ans *= i; return ans; }
void file(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);  
#endif
}
vector<bool>vis;
bool cycle;
void dfs(vector<vector<int>>&adj,int u, int p) {
	if (vis[u]) {
		cycle = true;
		return;
	}
	vis[u] = true;
	for (int i = 0; i < adj[u].size(); i++) {
		int ch = adj[u][i];
		if (ch != p)
			dfs(adj,ch, u);
	}
}
bool istree(vector<vector<int>>&adj, int x)
{
	cycle = 0;
	dfs(adj, x, -1);
	return !cycle;
}
int main()
{
	//cout << setprecision(20) << fixed;
	JSE
		file();
	//	freopen("friday.in", "r", stdin);
	///////////
	int t;
	cin >> t;
	while (t--)
	{
		
		string s;
		vector<vector<int>>adj(26);
		while (cin >> s)
		{
			if (s[0] == '*')
				break;
			adj[s[1] - 'A'].push_back(s[3] - 'A');
			adj[s[3] - 'A'].push_back(s[1] - 'A');
		}
		vector<int>nodes;
		{
			string temp;
		cin >> temp;
		for (int i = 0; i < sz(temp); i++)
		{
			if (temp[i] != ',')
				nodes.push_back(temp[i] - 'A');
		}
		}
		vis = vector<bool>(27,0);
		int tree = 0, acorn = 0;
		for (int i = 0; i < sz(nodes); i++)
		{
			if (sz(adj[nodes[i]]) == 0)
				acorn++;
			else
			{
				tree += istree(adj, nodes[i]);
			}
		}
		cout << "There are "<<tree<<" tree(s) and "<< acorn<<" acorn(s)." << endl;
	}
}