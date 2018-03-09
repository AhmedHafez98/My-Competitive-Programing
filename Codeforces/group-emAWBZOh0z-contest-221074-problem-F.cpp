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
	freopen("input.txt", "r", stdin);// freopen("output.txt", "w", stdout);
#endif
}


int main()
{
	//cout << setprecision(7) << fixed;
	JSE
			//file();
		// freopen("A-large-practice.in", "r", stdin);
	int t;
	cin >> t;
	while (t--)
	{
		string a, b;
		cin >> a >> b;
		set<string>st;
		for (int i = 0; i < (1 << (sz(a) + sz(b))); i++)
		{
			bitset<16>x(i);
			if (x.count() == sz(b))
			{
				string t;
				int  idx1 = sz(a) - 1, idx2 = sz(b) - 1; 
				for (int j = 0; j < sz(a) + sz(b); j++)
				{
					if (x[j])
						t+= b[idx2--];
					else
						t+= a[idx1--];
				}
				reverse(all(t));
				st.insert(t);

			}
		}
		for (auto i = st.begin(); i != st.end(); i++)
			cout << *i << endl;
		cout << endl;

	}
}
