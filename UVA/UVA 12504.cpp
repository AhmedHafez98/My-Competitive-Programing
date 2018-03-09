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

void file(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
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
		int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		string t;
		cin >> t;
		map<string, string>mp1,mp2;
		int idx = 0;
		while (idx<sz(s))
		{
			string x,y;
			if (s[idx] == '{' || s[idx] == ',')
			{
				idx++;
				if (s[idx] == '}')
					break;
				while (s[idx] != ':'&&s[idx]!='}')
					x += s[idx++];
				idx++;
				while (s[idx] != ',' && s[idx] != '}')
					y += s[idx++];
				mp1[x] = y;
			}
			else
				break;
		}
		idx = 0;
		while (idx<sz(t))
		{
			string x, y;
			if (t[idx] == '{' || t[idx] == ',')
			{
				idx++;
				if (t[idx] == '}')
					break;
				while (t[idx] != ':'&&t[idx] != '}')
					x += t[idx++];
				idx++;
				while (t[idx] != ',' && t[idx] != '}')
					y += t[idx++];
				mp2[x] = y;
			}
			else
				break;
		}
		//cout << "Here" << endl;
		vector<string> plus, min, mul;
		for (auto i = mp2.begin(); i != mp2.end(); i++)
		{
			if (mp1[i->first] == "")
				plus.push_back(i->first+",");
			else if (mp1[i->first] != i->second)
				mul.push_back(i->first + ",");
		}
		for (auto i = mp1.begin(); i != mp1.end(); i++)
		{
			if (mp2[i->first] == "")
				min.push_back(i->first + ",");
		}
		//cout << "here" << endl;
		if (sz(plus) == 0 && sz(min) == 0 && sz(mul) == 0)
			cout << "No changes" << endl;
		else
		{
			sort(all(plus));
			if (sz(plus))
			plus[sz(plus) - 1].pop_back();
			sort(all(min));
			if (sz(min))
			min[sz(min) - 1].pop_back();
			sort(all(mul));
			if (sz(mul))
			mul[sz(mul) - 1].pop_back();
			if (sz(plus))
			{
				cout << "+";
				for (int i = 0; i < sz(plus); i++)
					cout << plus[i];
				cout << endl;
			}
			if (sz(min))
			{
				cout << "-";
				for (int i = 0; i < sz(min); i++)
					cout << min[i];
				cout << endl;
			}
			if (sz(mul))
			{
				cout << "*";
				for (int i = 0; i < sz(mul); i++)
					cout << mul[i];
				cout << endl;
			}
		}

		cout << endl;
	}
	return 0;
}