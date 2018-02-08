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
int a[26];
int b[26];
int ans[26];
int main()
{
	//cout << setprecision(7) << fixed;
	JSE
		//	file();
		//  freopen("friday.in", "r", stdin);
		string s, t;
	cin >> s >> t;
	int qus = 0;
	for (int i = 0; i < sz(s); i++)
	{
		if (s[i] == '?')
			qus++;
		else
			a[s[i] - 'a']++;
	}
	for (int i = 0; i < sz(t); i++)
		b[t[i] - 'a']++;
	int num = 1;

	while (qus>0)
	{
		for (int i = 0; i < 26; i++)
		{
			if (a[i] < b[i] * num)
			{

				if (qus > b[i] * num - a[i])
				{
					qus -= b[i] * num - a[i];
					ans[i] += b[i] * num - a[i];
					a[i] = b[i] * num;

				}
				else
				{
					ans[i] += qus;
					qus = 0;
					break;
				}
			}
		}
		//cout << num << endl;
		num++;
	}
	int idx = 0;
	for (int i = 0; i < sz(s); i++)
	{
		if (s[i] == '?')
		{
			while (ans[idx] == 0 && idx<26)
				idx++;
			ans[idx]--;
			s[i] = char(idx + 'a');
		}
	}
	cout << s << endl;
}