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

template <class ItemType>
struct node
{
	ItemType data;
	node<ItemType>* next;
};

template <class ItemType>
class LinkedList
{
private:
	node<ItemType>* Head;
public:
	LinkedList()
	{
		Head = NULL;
	}

	void InsertItem(ItemType d)
	{
		node<ItemType>* n = new node<ItemType>;
		n->data = d;
		if (Head == NULL)
		{
			Head = n;
			n->next = NULL;
			return;
		}
		node<ItemType>* t = Head;
		while (t->next != NULL&&n->data>t->next->data)
		{
			t = t->next;
		}
		if (t->next == NULL)
		{
			if (t->data <= n->data)
			{
				t->next = n;
				n->next = NULL;
			}
			else
			{
				n->next = t;
				Head = n;
			}
		}
		else
		{
			n->next = t->next;
			t->next = n;
		}
	}

	void DeleteItem(ItemType d)
	{
		if (Head->data == d)
		{
			Head = Head->next;
			return;
		}
		node<ItemType>* c = Head;
		node<ItemType>* p=NULL;
		while (c != NULL)
		{
			if (c->data == d)
			{
				p->next = c->next;
				return;
			}
			p = c;
			c = c->next;
		}
	}

	void PrintList()
	{
		cout  << endl;
		cout << "       List Items: ";
		node<ItemType>* t = Head;
		while (t != NULL)
		{
			cout << t->data << "  ";
			t = t->next;
		}
		cout << "\n\n";
	}

	int getLength()
	{
		int c = 0;
		node<ItemType>* t = Head;
		while (t != NULL)
		{
			c++;
			t = t->next;
		}
		return c;
	}
};
int main()
{
	//cout << setprecision(20) << fixed;
	// negative MOD (a%x+x)%x;
	//file();
	//	freopen("friday.in", "r", stdin);
	///////////
	JSE
		////////// define 
		int option;
	LinkedList<int> ul;
	int i;
	int item;
	char ch;

	do
	{
		system("CLS");
		cout << "                    0: Exit" << endl
			<< "                    1: Insert" << endl
			<< "                    2: Delete" << endl
			<< "                    3: Print" << endl
			<< "                    4: Get Length" << endl
			<< "                                         otherwise Invalid\n" << endl;
		cout << "     Enter Option:";
		cin >> option;

		switch (option)
		{
		case 1:
			cout << "       Enter Elements:  " ;
			cin >> item;
			ul.InsertItem(item);
			system("pause"); cout << "\n";
			break;
		case 2:
			cout << "       Enter Element To delete:  ";
			cin >> item;
			ul.DeleteItem(item);
			system("pause"); cout << "\n";
			break;
		case 3:
			cout << "                      ------ List Elements -----" << endl;
			ul.PrintList();
			system("pause"); cout << "\n";
			break;
		case 4:
			cout << "       number of items =  " << ul.getLength() << endl;
			system("pause"); cout << "\n";
			break;
		default:
			cout << "                            Invalid option \n";
		}
	} while (option != 0);

	return 0;
}