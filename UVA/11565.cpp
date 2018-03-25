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


int main()
{
	//cout << setprecision(20) << fixed;
	// negative MOD (a%x+x)%x;
	file();
	//	freopen("friday.in", "r", stdin);
	///////////
	fast
		int n;
	cin >> n;
	while (n--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int ans[3] = { -101 };
		for (int i = -100; i <= 100; i++)
		{
			for (int j = -100; j <= 100; j++)
			{
				if (i != j)
				{
					int z = a - (i + j);
					if (z != i&&z != j&&i*j*z==b&&(i*i+j*j+z*z==c))
					{
						ans[0] = i;
						ans[1] = j;
						ans[2] = z;
					}
				}
			}
		}
		sort(ans, ans + 3);
		if (ans[0] == -101)
			cout << "No solution." << endl;
		else 
		cout << ans[0] << ' ' << ans[1] << ' '<<ans[2] << endl;
	}



	return 0;
}