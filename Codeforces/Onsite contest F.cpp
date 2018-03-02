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
int a[26];
int main()
{
	//cout << setprecision(20) << fixed;
	// negative MOD (a%x+x)%x;
	//file();
	//	freopen("friday.in", "r", stdin);
	///////////
	JSE
		////////// define 
		string s;
	cin >> s;

	for (int i = 0; i < 26; i++)
		cin >> a[i];
	for (int i = 0; i < sz(s); i++)
	{
		if (s[i] == '?')
		{
			int first = i;
			while (i < sz(s) && s[i] == '?')
				i++;

			int last = i - 1;
			i--;
			if (first == 0 && last == sz(s) - 1)
			{
				//cout << "here" << endl;
				int ans = 0;
				int mn = INT_MAX;
				for (int k = 0; k < 26; k++)
				{
					if (a[k] < mn)
					{
						mn = a[k];
						ans = k;
					}
				}
				//cout << ans << endl;
				if (first == last)
				{
					s[0] = char(ans + 'a');
				}
				else
				{
					for (int k = 0; k < sz(s); k++)
						s[k] = char('a');
				}
			}
			else if (first == 0)
			{
				int ans = 0, mn = INT_MAX;
				for (int k = 0; k < 26; k++)
				{
					if (abs(a[s[last + 1] - 'a'] - a[k]) < mn)
					{
						ans = k;
						mn = abs(a[s[last + 1] - 'a'] - a[k]);
					}
				}
				for (int k = 0; k <= last; k++)
					s[k] = char(ans + 'a');

			}
			else if (last == sz(s) - 1)
			{
				int ans = 0, mn = INT_MAX;
				for (int k = 0; k < 26; k++)
				{
					if (abs(a[s[first - 1] - 'a'] - a[k]) < mn)
					{
						ans = k;
						mn = abs(a[s[first - 1] - 'a'] - a[k]);
					}
				}
				for (int k = first; k < sz(s); k++)
					s[k] = char(ans + 'a');

			}
			else
			{

				int ans = 0, mn = INT_MAX;
				//cout << mn << endl;
				for (int k = 0; k < 26; k++)
				{
					int x = abs(a[s[first - 1] - 'a'] - a[k]) + abs(a[s[last + 1] - 'a'] - a[k]);
					if (x < mn)
					{
						mn = x;
						ans = k;

					}
				}
				for (int k = first; k <= last; k++)
					s[k] = char(ans + 'a');
				//cout << first<<' '<<last<< endl;
			}
		}
	}
	ll cost = 0;
	for (int i = 0; i < sz(s) - 1; i++)
		cost += abs(a[s[i] - 'a'] - a[s[i + 1] - 'a']);
	cout << cost << endl;
	cout << s << endl;
}
