#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include <map>
#include <set>
#include <list>
#include<fstream>
#include<stdio.h>
#include<iomanip>
#include<climits>
#include<list>
#define all(v) ((v).begin()),((v).end())
#define sz(v) ((int)(v).size())
#define PI 3.14159265
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
void file()
{
	//freopen("coaches.in", "r", stdin);
	//freopen("waves.out", "w", stdout);
}
int mx(vector<int>v)
{
	int m = 0;
	for (int i = 0; i < sz(v); i++)
	{
		m = max(m, v[i]);
	}
	return m;
}
int main(){
	fast();
	file();
	///////////////////////
	ll n, x, cnt = 0;
	while (cin >> n >> x){
		for (int i = 1; i*i <= x; i++)
		{
			if (i*i == x&&i*n >= x)
				cnt++;
			else if (x%i == 0 && x <= i*n)
			{
				cnt++; if (x <= (x / i)* n)cnt++;
			}
		}
		cout << cnt << endl; cnt = 0;
	}
	return 0;
}