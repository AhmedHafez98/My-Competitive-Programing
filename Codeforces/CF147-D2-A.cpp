#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<stack>
using namespace std;
#define all(v) ((v).begin()),((v).end())
#define allr(v)      ((v).rbegin()), ((v).rend())
#define sz(v) ((int)(v).size())
#define clr(v, d)        memset(v, d, sizeof(v))
#define JSE ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl  "\n"
typedef long long ll;
typedef unsigned long long ull;
int MOD = 1000003;
typedef  double ld;
ld dis(pair<ld, ld>a, pair<ld, ld>b) { return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2)); }
void file(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);// freopen("output.txt", "w", stdout);
#endif
}
int a[50][50];
int  b[51][51];
bool vis[51];
int main()
{
	//cout << setprecision(7) << fixed;
	JSE
		//	file();
		// freopen("A-large-practice.in", "r", stdin);
		
		string s;
	getline(cin, s);
	vector<string>v;
	string t;
	int idx = 0;
	while (idx < sz(s))
	{
		while (idx<sz(s)&&s[idx] != ' ')
		{
			if (s[idx] == '.' ||s[idx] == ',' || s[idx] == '!' || s[idx] == '?')
			{
				t.push_back(s[idx]);
				break;
			}
			t.push_back(s[idx]);
			idx++;
		}
		if (t != "")
		v.push_back(t);
		t = "";
		idx++;
	}
	string ans;
	for (int i = 0; i < sz(v); i++)
	{
		if (v[i] == "," || v[i] == "." || v[i] == "!" || v[i] == "?"&&sz(ans))
			ans.pop_back();
		ans += v[i] + " ";

	}
	ans.pop_back();
	cout << ans << endl;

}