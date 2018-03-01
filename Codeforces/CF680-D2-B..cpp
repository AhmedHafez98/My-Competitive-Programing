#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<sstream>
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
#include <functional>
#include <utility>
#include <numeric>
#define all(v) ((v).begin()),((v).end())
#define sz(v) ((int)(v).size())
#define PI 3.14159265
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, k;
	while (cin >> n >> k){
		vector<int >v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		k--;
		int i = 0; int cnt = 0;
		while (k + i < n || k - i >= 0)
		{
			int idx = k + i;
			int id = k - i;
			int x = 0,y=0;
			if (idx < n&&idx!=k)
			{
				if (v[idx] == 1)x = 2;
			}
			else x = 1;
			if (id >= 0)
			{
				if (v[id] == 1)y = 2;
			}
			else y = 1;
			if (x == 2 && y == 2)
				cnt += 2;
			else if ((x == 1 && y == 2) || (y == 1 && x == 2))
				cnt++;
			i++;
		}
		cout << cnt << endl;
	}
}