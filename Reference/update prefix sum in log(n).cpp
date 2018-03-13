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
template<class Int> Int gcd(Int a, Int b) {return b == 0 ? abs(a) : gcd(b, a % b);}
ll tree[10001];
void add(int idx, int val)
{
	idx++;
	while (idx <= 10000)
	{
		tree[idx - 1] += val;
		idx += (idx&-idx);
	}
}
ll get(int idx)
{
	idx++;
	ll ret = 0;
	while (idx)
	{
		ret += tree[idx - 1];
		idx -= (idx&-idx);
	}
	return ret;
}
int main()
{
	//cout << setprecision(20) << fixed;
	// negative MOD (a%x+x)%x;
	//file();
	//	freopen("friday.in", "r", stdin);
	///////////
	JSE
		////////// define
		int n,q;

	cin >> n>>q;
	vector<int>v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		add(i, v[i]);
	}
	while (q--)
	{
		int bol;
		cin >> bol;
		if (bol == 1)
		{
			int idx, val;
			cin >> idx >> val;
			add(idx, val - v[idx]);
			v[idx] = val;
		}
		else
		{
			int l, r;
			cin >> l >> r;
			cout << get(r) - get(l - 1) << endl;
		}
	}
	return 0;

}