#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#define all(v) ((v).begin()),((v).end())
#define allr(v)	     ((v).rbegin()), ((v).rend())
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
int main()
{
	//cout << setprecision(4) << fixed;
	JSE
		//file();
		//	freopen("friday.in", "r", stdin);
		///////////
		int t;
	cin >> t;
	while (t--)
	{
		char a[8];
		int b[8];
		for (int i = 0; i < 8; i++)
		{
			cin >> a[i] >> b[i];
		}
		bool f = 1;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (i != j)
				{
					if (abs(a[i] - a[j]) == abs(b[i] - b[j]))
						f = 0, j = 9, i = 9;
					else if (a[i] == a[j] || b[i] == b[j])
						f = 0, i = 9, j = 0;
				}
			}
		}
		cout << (f ? "Valid" : "Invalid") << endl;
	}
	return 0;
}