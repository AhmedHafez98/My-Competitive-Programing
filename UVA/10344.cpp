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
int a[5];
bool ok = 0;
string s;

void f(int sum, int idx)
{
	if (idx == 5)
	{
		if (sum == 23)
		{
			ok = 1;
		}
		return;
	}
	f(sum + a[idx], idx + 1);
	f(sum - a[idx], idx + 1);
	f(sum*a[idx], idx + 1);
	
}
int main()
{
	//cout << setprecision(7) << fixed;
	// negative MOD (a%x+x)%x;

	//	freopen("friday.in", "r", stdin);
	///////////

	file();
	fast
	
	while (cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4])
	{
		if (a[0] + a[1] + a[2] + a[3] + a[4] == 0)
			break;
		ok = 0;
		sort(a, a + 5);
		do{


			f(a[0], 1);
		
		} while (next_permutation(a, a + 5));
		cout << (ok ? "Possible" : "Impossible") << endl;
	}

}