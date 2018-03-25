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


int main()
{
	//cout << setprecision(20) << fixed;
	// negative MOD (a%x+x)%x;
	file();
	//	freopen("friday.in", "r", stdin);
	///////////
	fast
		int t, n;
	while (cin >> t >> n)
	{
		if (!(t + n))
			break;
		vector<int>v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		set<vector<int>>ans;
		for (int i = 1; i < (1 << n); i++)
		{
			bitset<20>bt(i);
			int sum = 0;
			vector<int>temp;
			for (int j = 0; j < n; j++)
			{
				if (bt[j])
				{
					sum += v[j];
					temp.push_back(v[j]);
				}
			}
			if (sum == t)
			{
				sort(allr(temp));
				ans.insert(temp);
			}
		}
		cout << "Sums of " << t << ":" << endl;
		if (sz(ans))
		{
			for (auto i = ans.rbegin(); i != ans.rend(); i++)
			{
				for (int j = 0; j < sz(*i)-1; j++)
				{
					cout << (*i)[j] << '+';

				}
				cout << (*i)[sz(*i) - 1];
				cout << "\n";
			}
		}
		else
			cout << "NONE" << endl;

	}
	return 0;
}