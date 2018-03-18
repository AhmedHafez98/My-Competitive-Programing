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
	freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#endif
}

int main()
{
	//cout << setprecision(20) << fixed;
	// negative MOD (a%x+x)%x;
		file();
	//	freopen("friday.in", "r", stdin);
	///////////
		JSE
			////////// define
			int m, n;
		while (cin >> m >> n)
		{
			map<string, ll>mp;
			string s;
			ll x;
			for (int i = 0; i < m; i++)
			{
				cin >> s >> x;
				mp[s] = x;
			}
			cin.ignore();
		
			while (n--)
			{
				string c;
				s.clear();
				while (getline(cin, c))
				{
					if (c == ".")
						break;
					s.push_back(' ');
					s += c;
				}
				ll val = 0;
				string t;
				for (int i = 0; i < sz(s); i++)
				{
					if (s[i] == ' ')
					{
						val += mp[t];
						t = "";
					}
					else
						t += s[i];
				}
				val += mp[t];
				cout << val << endl;
			}
		}
	return 0;

}