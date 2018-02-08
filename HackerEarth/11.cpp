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
int c[26];
int main()
{
	//cout << setprecision(7) << fixed;
	JSE
		file();
	//  freopen("friday.in", "r", stdin);
	int t;
	cin >> t;
	cin.ignore();
	while (t--)
	{
		clr(c, 0);
		string a, b;
		getline(cin, a);
		getline(cin, b);
		//cout << a << endl;
		//cout << b << endl;
		for (int i = 0; i < sz(a); i++)
		{
			if (a[i] != ' ')
				c[a[i] - 'a']++;
		}
		int cnt = 0;
		for (int i = 0; i < sz(b); i++)
		{
			if (b[i] != ' ')
			{
				if (c[b[i] - 'a'])
					c[b[i] - 'a']--;
				else cnt++;
			}
		}
		int ca = 0;
		for (int i = 0; i < 26; i++)
		{
			if (c[i])
				ca += c[i];
		}
		if (ca&&!cnt)
			cout << "You win some." << endl;
		else if (!ca&&cnt)
			cout << "You lose some." << endl;
		else
			cout << "You draw some." << endl;

	}
}