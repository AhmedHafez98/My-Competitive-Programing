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
	freopen("input.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
}
int main()
{
	//cout << setprecision(7) << fixed;
	JSE
		//	file();
		//  freopen("friday.in", "r", stdin);
		///////////
		int n;
	cin >> n;
	vector<ll>v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	vector<ll>p(5);
	map<ll, ll>mp;
	map<ll, ll>::iterator it;
	for (int i = 0; i < 5; i++)
	{
		cin >> p[i];
		mp[p[i]] = 0;
	}
	ll cur = 0;
	mp[-1] = 0;
	for (int i = 0; i < sz(v); i++)
	{
		cur += v[i];
		it = mp.end();
		it--;
		while (it != mp.begin())
		{
			if (cur < it->first)
				it--;
			else
			{
				it->second += cur / it->first;
				cur -= cur / it->first*it->first;
			}
		}
	}
	for (int i = 0; i < 5; i++)
		cout << mp[p[i]] << ' ';
	cout << endl << cur << endl;

}