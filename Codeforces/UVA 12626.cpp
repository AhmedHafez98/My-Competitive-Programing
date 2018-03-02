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
bool cmp(int a, int b)
{
	if ((a & 1) && (b & 1))
		return a<b;
	if ((a & 1) == 0 && (b & 1))
		return 0;
	if ((a & 1) && (b & 1) == 0)
		return 1;
}
int main()
{
	//cout << setprecision(20) << fixed;
	// negative MOD (a%x+x)%x;
	//file();
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
		string t = "MARGARITA";
		map<char, int>mp;
		for (int i = 0; i < sz(s); i++)
			mp[s[i]]++;
		mp['A'] /= 3;
		mp['R'] /= 2;
		int mn = 1e8;
		for (int i = 0; i < sz(t); i++)
		{
			mn = min(mn, mp[t[i]]);
		}
		cout << mn << endl;
	}
	return 0;
}
