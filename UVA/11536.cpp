#define _CRT_SECURE_NO_WARNINGS

#include<bits/stdc++.h>

using namespace std;

#define all(v) ((v).begin()),((v).end())
#define allr(v)	     ((v).rbegin()), ((v).rend())
#define sz(v) ((int)(v).size())
#define clr(arr, val)        memset(arr, val, sizeof(arr))
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

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
struct node{
	int x, r;
	bool ch;
};
int a[int(1e6)+3];
int main()
{
	//cout << setprecision(20) << fixed;
	// negative MOD (a%x+x)%x;
	
	//	freopen("friday.in", "r", stdin);
	///////////
	file();
	
	fast
		int t;
	cin >> t;
	int T = 1;
	while (t--)
	{
		ll n, m, k;
		cin >> n >> m >> k;
		a[0] = 1%m;
		a[1] = 2%m;
		a[2] = 3%m;
		for (int i = 3; i < 1e6 + 3; i++)
		{
			a[i] = (a[i - 1] + a[i - 2] + a[i - 3]) % m + 1;
		}
		set<int>st;
		int l = 0, r = 0, mn = INT_MAX;
		map<int, int>mp;
		while (l < n)
		{
			while (r < n&&sz(st)<k)
			{
				if (a[r] <= k&&a[r] != 0)
					st.insert(a[r]);
				mp[a[r]]++;
				r++;
			}
			if (sz(st)==k)
			mn = min(mn, r - l);
			if (mp[a[l]]>1)
				mp[a[l]]--;
			else
			{
				mp[a[l]]--; st.erase(a[l]);
			}
			l++;
		}
		if (mn == INT_MAX)
			cout << "Case "<<T++<<": sequence nai" << endl;
		else 
			cout << "Case " << T++ << ": "<<mn << endl;


	}



	return 0;
}