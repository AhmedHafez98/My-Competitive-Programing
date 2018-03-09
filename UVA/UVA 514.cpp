#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<stack>
using namespace std;
#define all(v) ((v).begin()),((v).end())
#define allr(v)      ((v).rbegin()), ((v).rend())
#define sz(v) ((int)(v).size())
#define clr(v, d)        memset(v, d, sizeof(v))
#define JSE ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl  "\n"
typedef long long ll;
typedef unsigned long long ull;
int MOD = 1000003;
typedef  double ld;
ld dis(pair<ld, ld>a, pair<ld, ld>b) { return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2)); }
void file(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
}


int main()
{
	//cout << setprecision(7) << fixed;
	JSE
		file();
		// freopen("A-large-practice.in", "r", stdin);
		int n;
	while (cin >> n)
	{
		if (!n)
			break;
		int x;
		vector<int>v(n);
		while (cin >> x)
		{
			if (!x)
			{
				cout << endl; break;
			}
			v[0] = x;
			for (int i = 1; i < n; i++)
				cin >> v[i];
			vector<int>ans(n);
			for (int i = 0; i < n; i++)
				ans[i] = v[v[i] - 1];
			int idx = 0;
			bool f = 1;
			stack<int>st;
			for (int i = 0; i < n; i++)
			{
				if (v[i] == ans[idx])
					idx++;
				else if (!st.empty() && st.top() == ans[idx])
				{
					st.pop(); idx++; i--;
				}
				else
					st.push(v[i]);
			}
			while (!st.empty()&&ans[idx] == st.top())
			{
				st.pop(); idx++;
			}
			if (st.empty())
				cout << "Yes" << endl;
			else
				cout << "No" <<endl;

		}
	}
}
