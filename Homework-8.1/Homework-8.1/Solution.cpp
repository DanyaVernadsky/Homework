#include <string>
#include <iostream>
#include "tree.h"

using namespace tree;

int main()
{
	cout << "Hello! Choose action" << endl;
	cout << "0 - work is over" << endl;
	cout << "1 - insert element in AVL tree" << endl;
	cout << "2 - remove element in AVL tree" << endl;
	cout << "3 - check element in AVL tree" << endl;
	cout << "4 - find data of element in AVL tree throw key" << endl;

	node* p;
	int reaction = -1;
	cin >> reaction;
	while (reaction != 0)
	{
		switch (reaction)
		{
		case '0':
			reaction = -1;
			break;
		case '1':
			cout << "Enter the key and data";
			string data = "";
			int key = 0;
			cin >> key;
			cin >> data;
			insert(p, key, data);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		default:
			break;
		}
	}
