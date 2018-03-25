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
struct node{
	int x, r;
	bool ch;
};
int a[int(1e6)+3];
int main()
{
	//cout << setprecision(20) << fixed;
	// negative MOD (a%x+x)%x;
	
	//	freopen("friday.in", "r", stdin);
	///////////
	file();
	
	fast
		int n;
	while (cin >> n)
	{
		vector<int>v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		int q;
		cin >> q;
		while (q--)
		{
			int x;
			cin >> x;
			int first = lower_bound(all(v), x) - v.begin();
			first--;
			if (first < 0)
				cout << "X ";
			else
				cout << v[first] << ' ';
			int last = upper_bound(all(v), x) - v.begin();
			if (last == n)
				cout << "X" << endl;
			else
				cout << v[last] << endl;
		}

	}

	return 0;
}