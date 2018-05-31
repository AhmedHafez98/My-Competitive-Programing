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
bool l(int x)
{
	while (x)
	{
		if (x % 10 != 4 && x % 10 != 7)
			return 0;
		x /= 10;
	}
	return 1;
}
int main()
{
	//cout << setprecision(20) << fixed;
	JSE
			file();
		//	freopen("friday.in", "r", stdin);
		///////////
		int n, m;
	while (cin >> n >> m)
	{
		vector<int>v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		map<int, int>mp;
		vector<int>ans(n);
		for (int i = 0; i < n; i++)
		{
			mp[v[i]]++;
			ans[i] = mp[v[i]];
		}
		map<pair<int, int>, int>mm;
		for (int i = 0; i < n; i++)
		{
			mm[{ans[i], v[i]}] = i + 1;
		}
		while (m--)
		{
			int x, y;
			cin >> x >> y;
			cout << mm[{x, y}] << endl;
		}
	}
}

