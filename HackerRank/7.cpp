#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#define all(v) ((v).begin()),((v).end())
#define allr(v)	     ((v).rbegin()), ((v).rend())
#define sz(v) ((int)(v).size())
#define clr(v, d)        memset(v, d, sizeof(v))
#define JSE ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl  "\n"
typedef long long ll;
typedef unsigned long long ull;
ll mod = ll(1e9 + 7);
typedef  double ld;
void file(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
}
int main()
{
	//cout << setprecision(4) << fixed;
	JSE
		//file();
		//	freopen("friday.in", "r", stdin);
		///////////
		int n;
	cin >> n;
	vector<vector<int>>v(n, vector<int>(n));
	long long a = 0, b = 0;
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			cin >> v[i][j];
			if (i == j)
				a += v[i][j];
			if (j == n - i - 1)
				b += v[i][j];
		}
	}
	cout << abs(a - b) << endl;
	return 0;
}
