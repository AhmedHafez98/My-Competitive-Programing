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
		string s;
	while (cin >> s)
	{
		deque<char>de;
		queue<char>q;
		stack<char>st;
		bool f = 0;
		int idx = 0;
		while (idx < sz(s))
		{
			if (s[idx] == '[')
			{
				f = 1, idx++;
				while (!st.empty())
				{
					de.push_front(st.top());
					st.pop();
				}
				while (!q.empty())
				{
					de.push_back(q.front());
					q.pop();
				}

				continue;
			}
			if (s[idx] == ']')
			{
				f = 0, idx++;
				while (!st.empty())
				{
					de.push_front(st.top());
					st.pop();
				}
				while (!q.empty())
				{
					de.push_back(q.front());
					q.pop();
				}

				continue;
			}
			if (f == 0)
			{
				q.push(s[idx++]);
			}
			if (f)
			{
				st.push(s[idx++]); 
			}
		}
		while (!st.empty())
		{
			de.push_front(st.top());
			st.pop();
		}
		while (!q.empty())
		{
			de.push_back(q.front());
			q.pop();
		}
		for (int i = 0; i < sz(de); i++)
			cout << de[i];
		cout << endl;
	}





	return 0;
}