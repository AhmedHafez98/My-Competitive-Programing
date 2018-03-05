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

int main()
{
	//cout << setprecision(20) << fixed;
	// negative MOD (a%x+x)%x;
	file();
	//	freopen("friday.in", "r", stdin);
	///////////
	JSE
		////////// define 
		int n;
	while (cin >> n)
	{
		if (!n)
			break;
		bitset<32>a(n), b, c;
	//	cout << a.to_string() << endl;
		int idx = 0;
		for (int i = 0; i < sz(a); i++)
		{
			if (a[i] == 1)
			{
				idx++;
				if (idx & 1)
				{
					b[i] = 1;
					c[i] = 0;
				}
				else
				{
					c[i] = 1;
					b[i] = 0;
				}
			}
			else
			{
				b[i] = 0;
				c[i] = 0;
			}
			
		}
		cout << b.to_ullong()<< ' ' << c.to_ullong() << endl;
	}
	return 0;
}