﻿#define _CRT_SECURE_NO_WARNINGS
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
		//		file();
		//  freopen("friday.in", "r", stdin);
		///////////
		int n;
	cin >> n;
	int cnt = 0;

	for (int i = n; i > 0; i--)
	{
		for (int j = i - 1; j > 0; j--)
		{
			for (int k = i - j + 1; k < j; k++)
			{

				if (k != i&&k != j)
				{
					int a = i, b = j, c = k;
					a = a^b;
					a = a^c;

					if (a == 0)
					{
						cnt++;
					}
				}
			}
		}
	}
	cout << cnt << endl;
}