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
#define print(v,n) for (int i = 0; i < n; i++)cout << v[i] << ' ';
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

int main(){
	fast();
	file();
	///////////////////////
	string x; int cnt = 0;
	cin >> x;
	sort(x.begin(), x.end());
	for (int i = 0; i < x.length() ; i++)
	{
		if (x[i] == x[i + 1])
			continue;
		cnt++;
	}
		if (cnt % 2 != 0)
			cout << "IGNORE HIM!" << endl;
		else
			cout << "CHAT WITH HER!" << endl;
	}