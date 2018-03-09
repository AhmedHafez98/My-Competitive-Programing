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
		queue<int>dis;
		deque<int>order;
		for (int i = 1; i <= n; i++)
		{
			order.push_back(i);
		}
		while (sz(order) != 1)
		{
			dis.push(order.front());
			order.pop_front();
			int x = order.front();
			order.pop_front();
			order.push_back(x);
		}
		cout << "Discarded cards:";
		if (!dis.empty())
		{
			cout << ' '<<dis.front();
			dis.pop();
		}
		while (!dis.empty()){
			cout << ", " << dis.front();
			dis.pop();
		}
		cout << "\nRemaining card: " << order.back() << endl;

	}
	return 0;
}