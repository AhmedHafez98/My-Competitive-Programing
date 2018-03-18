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
			string s;
		string t;
		while (getline(cin, t))
		{
			if (sz(s))
			{
				if (s[sz(s) - 1] == '-')
					s.pop_back();
				else
					s.push_back(' ');
			}
			s += t;
		}
		set<string>st;
		t = "";
		for (int i = 0; i < sz(s); i++)
		{
			if (!isalpha(s[i])&&s[i]!='-')
			{
				for (int j = 0; j < sz(t); j++)
				{
					if (isalpha(t[j]))
						t[j] = tolower(t[j]);
				}
				if (t != "")
				st.insert(t);
				t = "";
			}
			else
				t += s[i];
		}
		vector<string>v(all(st));
		for (int i = 0; i < sz(v); i++)
			cout << v[i] << endl;
	return 0;

}