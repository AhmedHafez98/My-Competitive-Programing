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
template<class Int> Int gcd(Int a, Int b) { return b == 0 ? abs(a) : gcd(b, a % b); }

bool cmp(string s, string t){
	if (s.size() < t.size())
		return true;
	else if (s.size()>t.size())
		return false;
	else
		return s < t;
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
		string cur = "";
	vector<string>v;

	for (int i = 0; i < 26; i++)
	{
		cur += char('a' + i);
		v.push_back(cur);
		for (int j = i + 1; j < 26; j++)
		{
			cur += char('a' + j);
			v.push_back(cur);
			for (int k = j + 1; k < 26; k++)
			{
				cur += char('a' + k);
				v.push_back(cur);
				for (int s = k + 1; s < 26; s++)
				{
					cur += char('a' + s);
					v.push_back(cur);
					for (int t = s + 1; t < 26; t++)
					{
						cur += char('a' + t);
						v.push_back(cur);
						cur.pop_back();
					}
					cur.pop_back();
				}
				cur.pop_back();
			}
			cur.pop_back();
		}
		cur.pop_back();
	}
	sort(v.begin(), v.end(), cmp);
	map<string, int>mp;
	for (int i = 0; i < sz(v); i++)
	{
		mp[v[i]] = i + 1;
	}
	string s;
	while (cin >> s){

		cout << mp[s] << endl;
	}
	return 0;

}