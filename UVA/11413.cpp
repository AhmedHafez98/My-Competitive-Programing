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

	freopen("output.txt", "w", stdout);

#endif
}
bool f(vector<int>&v, int m,int ans)
{
	int idx = 0;
	int sum = 0;
	while (idx < sz(v)&&m)
	{
		sum += v[idx];
		if (sum>ans)
		{
			m--;
			sum = 0;
			idx--;
		}
		idx++;
	}
	return idx == sz(v);
}
int main()
{
	//cout << setprecision(20) << fixed;
	// negative MOD (a%x+x)%x;

	//	freopen("friday.in", "r", stdin);
	///////////
	file();

	fast
		int n, m;
	while (cin >> n >> m)
	{
		if (!n)
			break;
		vector<int>v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		int lo = 0, hi = 1e9+1, mn = INT_MAX;
		while (lo <= hi)
		{
			int mid = (lo + hi) / 2;
			if (f(v, m, mid))
			{
				mn = min(mn, mid);
				hi = mid - 1;
			}
			else
			{
				lo = mid + 1;
			}
		}
		cout << mn << endl;
	}
	return 0;
}