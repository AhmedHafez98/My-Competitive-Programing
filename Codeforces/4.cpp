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
	freopen("input.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
}
map<string, pair<bool, ll>>mp;
int main()
{
	//cout << setprecision(4) << fixed;
	JSE
		file();
	//  freopen("friday.in", "r", stdin);
	///////////
	string s;
	cin >> s;
	if (s == "a1" || s == "h1" || s == "a8" || s == "h8")
		cout << 3 << endl;
	else if (s[0] == 'a' || s[0] == 'h' || s[1] == '1' || s[1] == '8')
		cout << 5 << endl;
	else
		cout << 8 << endl;

	return 0;
}