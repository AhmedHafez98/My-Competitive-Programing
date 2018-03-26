#define _CRT_SECURE_NO_WARNINGS

#include<bits/stdc++.h>

using namespace std;

#define all(v) ((v).begin()),((v).end())
#define allr(v)	     ((v).rbegin()), ((v).rend())
#define sz(v) ((int)(v).size())
#define clr(arr, val)        memset(arr, val, sizeof(arr))
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

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
	freopen("input.txt", "r", stdin);

	//freopen("output.txt", "w", stdout);

#endif
}
int temp[10000001];
ll cnt = 0;
void merge(int a[], int s, int m, int e)
{
	for (int i = s; i <= e; i++)
		temp[i] = a[i];
	int i = s, j = m + 1, k = s;
	while (i <= m&&j <= e)
	{

		if (temp[i] <= temp[j])
			a[k++] = temp[i++];
		else
			a[k++] = temp[j++], cnt += j - k;
	}
	while (i <= m)
		a[k++] = temp[i++];
}

void merge_sort(int a[], int s, int e)
{
	if (s >= e)
		return;
	int m = (s + e) / 2;
	merge_sort(a, s, m);
	merge_sort(a, m + 1, e);
	merge(a, s, m, e);

}
int a[1000001];
int main()
{
	//cout << setprecision(20) << fixed;
	// negative MOD (a%x+x)%x;

	//	freopen("friday.in", "r", stdin);
	///////////
	file();

	fast
		int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cnt = 0;
		merge_sort(a, 0, n - 1);
		cout << cnt << endl;
	}
	return 0;
}