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
int a[100];
int n;
int dp[100][100];
int lis(int i, int pre)
{
	if (i == n)
		return 0;
	if (dp[i][pre] != -1)
		return dp[i][pre];
	int ch1 = lis(i + 1, pre);
	int ch2 = 0;
	if (a[pre] < a[i])
		ch2 = lis(i + 1, i)+1;
	return dp[i][pre]=max(ch1, ch2);
}
int main()
{
	//cout << setprecision(7) << fixed;
	// negative MOD (a%x+x)%x;

	//	freopen("friday.in", "r", stdin);
	///////////

	//file();
	fast
		cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	clr(dp, -1);
	cout << lis(0, n) << endl;



}