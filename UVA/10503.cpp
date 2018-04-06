#define _CRT_SECURE_NO_WARNINGS

#include<bits/stdc++.h>

using namespace std;

#define all(v) ((v).begin()),((v).end())
#define allr(v)	     ((v).rbegin()), ((v).rend())
#define sz(v) ((int)(v).size())
#define clr(arr, val)        memset(arr, val, sizeof(arr))
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

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
pair<int, int>last;
vector<pair<int, int>>v1,v2;
int n;
bool ok;
int m;
bool vis[100];
void check(int i,int d)
{
	if (i == n)
	{
		if (d == last.first )
		{
			
			ok = 1;
		}
		return;
	}
	for (int j = 0; j < m; j++)
	{
		if (!vis[j] && (d == v1[j].first || d == v1[j].second))
		{
			vis[j] = 1;
			if (d == v1[j].first)
			{
				//v2.push_back(v1[j]);
				check(i + 1, v1[j].second);
			}
			else
			{
				//v2.push_back({ v1[j].second, v1[j].first });
				check(i + 1, v1[j].first);
			}
			vis[j] = 0;
		}
	}

}
int main()
{
	//cout << setprecision(7) << fixed;
	// negative MOD (a%x+x)%x;

	//	freopen("friday.in", "r", stdin);
	///////////

	file();
	fast
	
	while (cin >> n)
	{
		if (!n)
			break;
		
		cin >> m;
		ok = 0;
		pair<int, int>first;
		cin >> first.first >> first.second;
		cin >> last.first >> last.second;
		v1.clear();
		for (int i = 0; i < m; i++)
		{
			pair<int, int>temp;
			cin >> temp.first >> temp.second;
			v1.push_back(temp);
		}

		check(0, first.second);
		if (ok)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}




}