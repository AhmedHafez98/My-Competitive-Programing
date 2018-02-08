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
		int n;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	int a = 0, b = 1;
	bool f = 0;
	sort(all(v));
	while (b<n)
	{
		for (int i = b + 1; i < n&&v[i] < v[a] + v[b]; i++)
		{
			if (v[i] < v[a] + v[b])
			{
				f = 1;
				break;
			}
		}
		if (f)
			break;
		a++, b++;
	}
	cout << (f ? "YES" : "NO") << endl;

}