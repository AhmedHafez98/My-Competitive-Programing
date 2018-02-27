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
class List
{
private:
	int mx;
	int length;
	int *list;
public :
	List(int x = 100)
	{
		mx = x;
		list = new int[mx];
		length = 0;
	}
	bool add(int item)
	{
		if (length == mx)
		{
			cout << "              List is Full" << endl;
			return 0;
		}
		list[length] = item;
		length++;
		return 1;
	}
	int search(int item)
	{
		for (int i = 0; i < length; i++)
		{
			if (list[i] == item)
				return i;
		}
		return -1;
	}
	int size()
	{
		return length;
	}
	bool remove(int item)
	{
		int idx = search(item);
		if (length == 0)
		{
			cout << "              Empty" << endl;
			return 0;
		}
		if (idx == -1)
		{
			cout << "              NOT Found" << endl;
			return 0;
		}
		for (int i = idx; i < length - 1; i++)
			list[i] = list[i + 1];
		length--;
		return 1;
	}
	void Sort()
	{
		for (int i = 0; i < length; i++)
		{
			for (int j = i + 1; j < length; j++)
			{
				if (list[i] >= list[j])
					swap(list[i], list[j]);
			}
		}
	}
	void print()
	{
		for (int i = 0; i < length; i++)
			cout << list[i] << ' ';
		cout << endl;
	}
};
int main()
{
	//cout << setprecision(7) << fixed;
	JSE
		//	file();
		// freopen("A-large-practice.in", "r", stdin);
		int ch;
	List a(1000);
	do {
		system("CLS");
		cout << "\n\n\n\n              Options : \n" <<
			"              1 - add\n" <<
			"              2 - remove\n" <<
			"              3 - sort\n" <<
			"              4 - get the size\n" <<
			"              5 - print \n" <<
			"              6 - Search\n" << "                                         0 - exit\n";
		cout << "                        choose option  : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "                        Enter elemnt : ";
			int item;
			cin >> item;
			a.add(item);
			system("pause");
			break;
		case 2:
			cout << "                        Enter elemnt : ";
			item;
			cin >> item;
			a.remove(item);
			system("pause");
			break;
		case 3:
			a.Sort();
			cout << "done";
			system("pause");
			break;
		case 4:
			cout << "                        the size is "<<a.size() << endl;
			system("pause");
			break;
		case 5:
			if (a.size() == 0)
				cout << "                        the list is empty";
			else
			{
				cout << "                        list elements is ->>  ";
				a.print();
				system("pause");
			}
			break;
		case 6:
			cout << "                        Enter elemnt : ";
			 item;
			cin >> item;
			if (a.search(item) == -1)
				cout << "                        Not found" << endl;
			cout <<"                        the index is"<< a.search(item) << endl;
			break;
		default:
			break;
		}

	} while (ch);

}
