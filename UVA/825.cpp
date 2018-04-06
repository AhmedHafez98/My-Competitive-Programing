#define _CRT_SECURE_NO_WARNINGS

#include<bits/stdc++.h>

using namespace std;

#define all(v) ((v).begin()),((v).end())
#define allr(v)	     ((v).rbegin()), ((v).rend())
#define sz(v) ((int)(v).size())
#define clr(arr, val)        memset(arr, val, sizeof(arr))
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

typedef long long ll;
typedef unsigned long long ull;
typedef  double ld;
const ll OO = (ll)1e18;
const ll mod = (1e9) + 7;
const ld PI = acos(-1.0);
const ld EPS = 1e-8;

int dx[]{-1, -1, -1, 0, 0, 1, 1, 1}; // Dir array
int dy[]{-1, 0, 1, -1, 1, -1, 0, 1}; // Dir array

void file(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

#endif
}
int w, n;
int grid[1000][1000];
int cnt = 0;
void check(int i, int j)
{
	if (grid[i][j] == 2 || i > w || j > n)
		return;
	if (i == w - 1 && j == n - 1)
		cnt++;
	check(i, j + 1);
	check(i + 1, j);
}
int main()
{
	//cout << setprecision(7) << fixed;
	// negative MOD (a%x+x)%x;

	//	freopen("friday.in", "r", stdin);
	///////////

	file();
	fast
		int T;
	cin >> T;
	bool f = 0;
	while (T--)
	{
		
		cin >> w >> n;
		if (!f)
			f = 1;
		else
			cout << endl;
		clr(grid, 0);
		cin.ignore();
		for (int i = 0; i < w; i++)
		{
			string s;
			getline(cin, s);
			vector<int>v;
			ll num = 0;
			for (int j = 0; j < sz(s); j++)
			{
				if (s[j] == ' ')
				{
					v.push_back(num);
					num = 0;
				}
				else
				{
					num *= 10;
					num += s[j] - '0';
				}
			}
			v.push_back(num);
			for (int j = 1; j < sz(v); j++)
			{
				grid[v[0]-1][v[j]-1] = 2;
			}
		}
		check(0, 0);
		cout << cnt << endl;
		cnt = 0;
	}




}