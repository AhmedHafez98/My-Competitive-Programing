#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#define all(v) ((v).begin()),((v).end())
#define allr(v)      ((v).rbegin()), ((v).rend())
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
	freopen("input.txt", "r", stdin);// freopen("out.txt", "w", stdout);
#endif
}
map<string, pair<bool, ll>>mp;
int main()
{
	//cout << setprecision(4) << fixed;
	JSE
		//file();
		//  freopen("friday.in", "r", stdin);
		///////////
		map<string, ll>mp;
	map<ll, string >check;
	string s;
	while (cin >> s)
	{
		if (s == "def")
		{
			string x;
			int val;
			cin >> x >> val;
			if (mp.find(x) != mp.end())
				check.erase(mp[x]);
			mp[x] = val;
			check[val] = x;
		}
		else if (s == "calc")
		{
			string x;
			cin.ignore();
			getline(cin, x);
			string a;
			x += ' ';
			ll ans = 0;

			int po = 1;
			string res;
			for (int i = 0; i < sz(x); i++)
			{
				if (x[i] == ' ')
				{
					if (a != "-" && a != "+"&&a != "=")
					{
						if (mp.find(a) != mp.end())
							ans += po*mp[a];
						else
						{
							res = "unknown";
							break;
						}
					}
					else if (a == "-")
						po = -1;
					else if (a == "+")
						po = 1;
					else {
						if (check.find(ans) != check.end())
							res = check[ans];
						else
							res = "unknown";
					}
					a.clear();
				}
				else
					a += x[i];
			}
			cout << x << res << endl;
		}
		else if (s == "clear")
		{
			check.clear();
			mp.clear();
		}
	}
	return 0;
}