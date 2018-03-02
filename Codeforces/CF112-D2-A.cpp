// HaaaaFeZ(- -) ;
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
#define all(v) ((v).begin()),((v).end())
#define sz(v) ((int)(v).size())
#define PI 3.14159265
#define print(v,n) for (int i = 1; i < n; i++)cout << v[i] << ' ';
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
void lower(string &s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (isupper(s[i]))
			s[i] = tolower(s[i]);
	}

}
int main(){
	fast();
	file();
	///////////////////////
	string s, ss;
	cin >> s;
	cin >> ss;
	lower(s), lower(ss);

	
		if (s>ss)
		{
			cout << 1 << endl;
		}
		else if (s < ss)
		{
			cout << -1 << endl;
		}
		else
	cout << 0 << endl;

	return 0;
}