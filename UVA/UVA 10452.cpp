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
#define JSE ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MP(i,j) make_pair(int i,int j);
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vi vector<int>
typedef long long ll;
typedef unsigned long long ull;
typedef  double ld;
const double PI = acos(-1.0);
int dx[]{-1, -1, -1, 0, 0, 1, 1, 1};
int dy[]{-1, 0, 1, -1, 1, -1, 0, 1};
void file(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);  
#endif
}
map<char, bool>mp;
int n, m;
bool valid(pair<int,int>u)
{
	return u.first >= 0 && u.second >= 0 && u.first < n&&u.second < m;
}
struct node
{
	int i, j;
	char dir;
};
int main()
{
	//cout << setprecision(20) << fixed;
	JSE
			file();
		//	freopen("friday.in", "r", stdin);
		///////////
	int t;
	cin >> t;

	mp['I'] = 1;
	mp['E'] = 1;
	mp['H'] = 1;
	mp['O'] = 1;
	mp['V'] = 1;
	mp['A'] = 1;
	mp['#'] = 1;
	while (t--)
	{
		
		cin >> n >> m;
		vector<vector<char>>adj(n, vector<char>(m));
		vector<vector<int>>vis(n, vector<int>(m));
		map<pair<int,int>, node>per;
		pair<int, int>s, e;
		queue<pair<int, int>>q;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> adj[i][j];
				if (adj[i][j] == '@')
				{
					q.push({ i, j }); s = { i, j };
				}
				if (adj[i][j] == '#')
					e = { i, j };
			}
		}
		while (sz(q))
		{
			pair<int, int>u = q.front();
			int i = u.first, j = u.second;
			q.pop();
			if (valid({ i - 1, j }) && mp[adj[i - 1][j]] && !vis[i - 1][j])
			{
				vis[i - 1][j] = 1;
				q.push({ i - 1, j });
				per[{i - 1, j}] = { i, j,'f' };
			}
			if (valid({ i, j - 1 }) && mp[adj[i][j - 1]] && !vis[i][j - 1])
			{
				vis[i][j-1]=1;
				q.push({ i, j-1 });
				per[{i, j-1}] = { i, j,'l' };
			}
			if (valid({ i, j + 1 }) && mp[adj[i][j + 1]] && !vis[i][j + 1])
			{
				vis[i][j+1]=1;
				q.push({ i, j+1 });
				per[{i, j+1}] = { i, j,'r' };
			}
			if (adj[i][j] == '#')
				break;
		}
		map<char, string >dir;
		dir['f'] = "forth";
		dir['r'] = "right";
		dir['l'] = "left";
		vector<string> ans;
		node dis = per[e];
		while (1)
		{
			ans.push_back(dir[dis.dir]);
			if (dis.i == s.first&&dis.j==s.second)
				break;
			dis = per[{dis.i, dis.j}];
			
		}
		reverse(all(ans));
		for (int i = 0; i < sz(ans)-1; i++)
			cout << ans[i] << ' ';
		cout <<ans[sz(ans)-1]<< endl;
		
	}
}

