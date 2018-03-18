#define _CRT_SECURE_NO_WARNINGS

#include<bits/stdc++.h>

using namespace std;

#define all(v) ((v).begin()),((v).end())
#define allr(v)	     ((v).rbegin()), ((v).rend())
#define sz(v) ((int)(v).size())
#define clr(arr, val)        memset(arr, val, sizeof(arr))
#define JSE ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

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
	freopen("input.txt", "r", stdin);//freopen("output.txt", "w", stdout);
#endif
}
map<string, int>mp;
int main()
{
	//cout << setprecision(20) << fixed;
	// negative MOD (a%x+x)%x;
	file();
	//	freopen("friday.in", "r", stdin);
	///////////
	JSE
		////////// define
		int n;

	while (cin >> n)
	{
		if (n == 0)
			break;
		mp.clear();
		int mx = 0;
		for (int j = 0; j < n; j++)
		{
			string a[5];
			cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
			sort(a, a + 5);
			string s;
			for (int i = 0; i < 5; i++)
				s += a[i];
			mp[s]++;
			mx = max(mx, mp[s]);
		}
		int cn = 0;
		for (auto i = mp.begin(); i != mp.end(); i++)
		{
			if (i->second == mx)
				cn+=mx;
		}
		cout << cn << endl;
	}
	return 0;

}