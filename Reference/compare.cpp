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
bool cmp(int a, int b)
{
	if ((a & 1) && (b & 1))
		return a<b;
	if ((a & 1) == 0 && (b & 1))
		return 0;
	if ((a & 1) && (b & 1) == 0)
		return 1;
}
int main()
{
	//cout << setprecision(20) << fixed;
	// negative MOD (a%x+x)%x;
	//file();
	//	freopen("friday.in", "r", stdin);
	///////////
	JSE
		////////// define 
		priority_queue<int,vector<int>,function<bool(int,int)>>pq(cmp);
	set<int,bool(*)(int,int)>st(cmp);
	map<int, int>mp;
	vector<int>v;
	deque<int>dq;
	///////////////////// in
	for (int i = 0; i < 10; i++)
	{
		st.insert(i);
		v.push_back(i);
		pq.push(i);
		dq.push_back(i);
		mp[i] = i + 10;
	}
	/////////////////////////////
	sort(all(v), cmp);
	cout << "vector     ->> ";
	for (int i = 0; i < 10; i++)
		cout << v[i] << ' ';
	cout << endl << endl;
	///////////////////////////////
	sort(all(dq), cmp);
	cout << "deque      ->> ";
	for (int i = 0; i < 10; i++)
		cout << dq[i] << ' ';
	cout << endl << endl;
	/////////////////////////////
	cout << "priority   ->> ";
	while (!pq.empty())
	{
		cout << pq.top() << ' ';
		pq.pop();
	}
	cout << endl << endl;
	///////////////////////////
	set<int>::iterator it= st.begin();
	cout << "set        ->> ";
	while (it != st.end())
	{
		cout << *it << ' ';
		it++;
	}
	cout << endl << endl;
    /////////////////////////
	map<int, int>::iterator is = mp.begin();
	cout << "map first  ->> ";
	while (is != mp.end())
	{
		cout << is->first << ' ';
		is++;
	}
	cout << endl << endl;
	//////////////////////////
	cout << "map second ->> ";
	is = mp.begin();
	while (is != mp.end())
	{
		cout << is->second << ' ';
		is++;
	}
	cout << endl<<endl;
	return 0;
}
