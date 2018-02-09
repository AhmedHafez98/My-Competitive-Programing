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
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
}

int main()
{
	//cout << setprecision(7) << fixed;
	JSE
		//file();
		// freopen("A-large-practice.in", "r", stdin);
		int w, h, n;
	while (cin >> w >> h >> n)
	{
		if (w + h + n == 0)
			break;
		vector<vector<int>>v(w, vector<int>(h, 0));
		pair<int, int >a, b;
		for (int i = 0; i < n; i++)
		{
			cin >> a.first >> a.second >> b.first >> b.second;
			for (int i = min(a.first, b.first) - 1; i < max(a.first, b.first); i++)
			{
				for (int j = min(a.second, b.second) - 1; j < max(a.second, b.second); j++)
					v[i][j] = 1;
			}
		}
		int cnt = 0;
		for (int i = 0; i < w; i++)
		{
			for (int j = 0; j < h; j++)
			{
				if (v[i][j] == 0)
					cnt++;
			}
		}

		if (cnt == 0)
			cout << "There is no empty spots." << endl;
		else if (cnt == 1)
			cout << "There is one empty spot." << endl;
		else
			cout << "There are " << cnt << " empty spots." << endl;
	}
}