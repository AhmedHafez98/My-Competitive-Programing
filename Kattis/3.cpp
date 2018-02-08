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
int arr[3];
int main()
{
	//cout << setprecision(7) << fixed;
	JSE
		//      file();
		//  freopen("friday.in", "r", stdin);
		///////////
		int n;
	cin >> n;
	string s, a, b, c;
	a = "ABC";
	b = "BABC";
	c = "CCAABB";
	cin >> s;

	for (int i = 0; i < n; i++)
	{
		if (s[i] == a[i % 3])
			arr[0]++;
		if (s[i] == b[i % 4])
			arr[1]++;
		if (s[i] == c[i % 6])
			arr[2]++;
	}
	int mx = *max_element(arr, arr + 3);
	cout << mx << endl;
	if (arr[0] == mx)
		cout << "Adrian" << endl;
	if (arr[1] == mx)
		cout << "Bruno" << endl;
	if (arr[2] == mx)
		cout << "Goran" << endl;
}