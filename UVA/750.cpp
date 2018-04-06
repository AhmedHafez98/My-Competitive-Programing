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
set<vector<int>>st[8][8];
int col[8];
int d1[18], d2[18];
bool vis[8][8];
vector<int>v;
void gen(int i)
{
	if (i == 8)
	{
		for (int j = 0; j < 8; j++)
		{
			st[v[j]-1][j].insert(v);
		}
		return;
	}
	for (int j = 0; j < 8; j++)
	{
		if ( !col[j] && !d1[j - i + 8] && !d2[i + j])
		{
			vis[i][j] = 1;
			col[j] = 1;
			d1[j - i + 8] = 1;
			d2[i + j] = 1;
			v.push_back(j+1);
			gen(i + 1);
			v.pop_back();
			vis[i][j] = 0;
			col[j] = 0;
			d1[j - i + 8] = 0;
			d2[i + j] = 0;
			
		}
	}
}
int main()
{
	//cout << setprecision(7) << fixed;
	// negative MOD (a%x+x)%x;

	//	freopen("friday.in", "r", stdin);
	///////////

	file();
	fast
		gen(0);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		if (t != 1)
			cout << endl;
		int x, y;
		cin >> x >> y;
		auto i = st[x - 1][y - 1].begin(); 
		cout << "SOLN       COLUMN" << endl;
		cout << " #      1 2 3 4 5 6 7 8" << endl << endl;
		int idx = 1;
		while (i != st[x - 1][y - 1].end())
		{
			cout << setw(2) << idx++;
			cout<< "      ";
			for (int j = 0; j < sz(*i)-1; j++)
			{
				cout << (*i)[j] << ' ';
			}
			cout << (*i)[sz(*i) - 1] << endl;
			i++;
		}

	}



}