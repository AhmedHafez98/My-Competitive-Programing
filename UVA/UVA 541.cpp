#define _CRT_SECURE_NO_WARNINGS

#include<bits/stdc++.h>

using namespace std;

#define all(v) ((v).begin()),((v).end())
#define allr(v)	     ((v).rbegin()), ((v).rend())
#define sz(v) ((int)(v).size())
#define clr(arr, val)        memset(arr, val, sizeof(arr))
#define JSE ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MP(i,j) make_pair(int i,int j);


typedef long long ll;
typedef unsigned long long ull;
typedef  double ld;

const ll OO = (ll)1e18;
const ll mod = (1e9) + 7;
const ld PI = acos(-1.0);
const ld EPS = 1e-8;

int dx[]{-1, -1, -1, 0, 0, 1, 1, 1}; // Dir array
int dy[]{-1, 0, 1, -1, 1, -1, 0, 1}; // Dir array


int main()
{
	//cout << setprecision(20) << fixed;
	// negative MOD (a%x+x)%x;
	//file();
	//	freopen("friday.in", "r", stdin);
	///////////
	JSE
		////////// define 
		int n;
	while (cin >> n)
	{
		if (!n)
			break;
		vector<vector<int>>v(n, vector<int>(n));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cin >> v[i][j];
		}
		int row = 0, col = 0, sum = 0, sum2 = 0; pair<int, int>ans;
		for (int i = 0; i < n; i++)
		{
			sum = 0;
			sum2 = 0;
			for (int j = 0; j < n; j++)
			{
				sum += v[i][j];
				sum2 += v[j][i];
			}
			if (sum & 1)
			{
				row++; ans.first = i;
			}
			if (sum2 & 1)
			{
				col++; ans.second = i;
			}
		}
		if (row == 0 && col == 0)
			cout << "OK\n";
		else if (row == 1 && col == 1)
		{
			cout << "Change bit (" << ans.first+1 << "," << ans.second+1 << ")\n";
		}
		else
			cout << "Corrupt" << endl;
	}
	return 0;
}