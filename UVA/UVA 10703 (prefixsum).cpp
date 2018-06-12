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
int mark[int(1e6 + 1)];
int block[int(1e6 + 1)];
int main()
{
	//cout << setprecision(20) << fixed;
	JSE
		file();
	//	freopen("friday.in", "r", stdin);
	///////////
	int w, h, n;
	while (cin >> w >> h >> n)
	{
		if (w + h + n == 0)
			break;
		vector<vector<int>>adj(w + 2, vector<int>(h + 2,0));
		for (int i = 0; i < n; i++)
		{
			int x1, x2, y1, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			if (x1>x2)
				swap(x1, x2);
			if (y1 > y2)
				swap(y1, y2);
			adj[x1][y1] += 1;
			adj[x1][y2 + 1] += -1;
			adj[x2 + 1][y1] += -1;
			adj[x2 + 1][y2 + 1] += 1;
		}
		for (int i = 1; i <= w; i++)
		{
			for (int j = 1; j <= h; j++)
			{
				adj[i][j] += adj[i][j - 1];
			}
		}
		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= w; j++)
			{
				adj[j][i] += adj[j - 1][i];
			}
		}
		int cnt = 0;
		for (int i = 1; i <= w; i++)
		{
			for (int j = 1; j <= h; j++)
				cnt += adj[i][j] == 0;
		}
		if (cnt == 0)
			cout << "There is no empty spots." << endl;
		else if (cnt == 1)
			cout << "There is one empty spot." << endl;
		else
			cout << "There are " << cnt << " empty spots." << endl;
	}

	return 0;
}