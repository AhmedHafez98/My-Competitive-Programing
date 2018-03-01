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

long long pw(long long base, long long power) {
	long long result = 1;
	while (power > 0) {

		if (power & 1) {
			result = (result*base) % MOD;
		}
		base = (base * base) % MOD;
		power >>= 1;
	}
	return result;
}
ll  div(ll x)
{
	for (ll i = 2; i*i <= x; i++)
	{
		if (x%i == 0)
			return i;
	}
	return x;
}
int main()
{
	//cout << setprecision(7) << fixed;
	JSE
		//	file();
		// freopen("A-large-practice.in", "r", stdin);
int n,m;
cin>>n>>m;
vector<int>v(n);
for(int i=0;i<n;i++)
cin>>v[i];
set<int>st;
reverse(all(v));
vector<int>ans(n);
for(int i=0;i<n;i++)
{
    st.insert(v[i]);
    ans[i]=sz(st);
}
reverse(all(ans));
while(m--)
{
    int x;
    cin>>x;
    cout<<ans[x-1]<<endl;
}
}