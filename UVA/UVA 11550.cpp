#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#define all(v) ((v).begin()),((v).end())
#define allr(v)	     ((v).rbegin()), ((v).rend())
#define sz(v) ((int)(v).size())
#define clr(v, d)        memset(v, d, sizeof(v))
#define JSE ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MP(i,j) make_pair(int i,int j);
typedef long long ll;
typedef unsigned long long ull;
typedef  double ld;
const ll OO = (ll)1e18;
const ll mod = (1e9) + 7;
const double PI = acos(-1.0);
int dx[]{-1, -1, -1, 0, 0, 1, 1, 1};
int dy[]{-1, 0, 1, -1, 1, -1, 0, 1};
ld dis(pair<ld, ld>a, pair<ld, ld>b) { return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2)); }
ll pd(ll x) { if (x == 0)	return 1; if (x == 1) return 1; ull ans = 1; for (int i = 2; i <= x; i++) ans *= i; return ans; }
void file(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
}
int main()
{
	//cout << setprecision(20) << fixed;
	JSE
		//file();
		//	freopen("friday.in", "r", stdin);
		///////////
int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		vector<vector<int>>v(n,vector<int>(m));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
			cin>>v[i][j];
			}
		}
		bool f=1;
		map<pair<int,int>,int>mp;
		for(int i=0;i<m;i++)
		{
			int cnt=0;
			int x=0,a[100];
			for(int j=0;j<n;j++)
			{
				if(v[j][i])
					{cnt++;
					a[x++]=j;
					}
			}
			if(cnt!=2)
			{
				f=0;break;
			}
			else
			{
				if(mp[{a[0],a[1]}]==0)
					mp[{a[0],a[1]}]=1;
				else
					{f=0;break;}

			}
		}
		cout<<(f?"Yes":"No")<<endl;
	}

}
