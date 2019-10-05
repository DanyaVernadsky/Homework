#include <string>
#include <iostream>
#include "tree.h"

using namespace tree;

bool testing()
{
	node* p = NULL;
	if (check(p, 3))
	{
		return false;
	}
	insert(p, 3, "test");
	if (!check(p, 3))
	{
		return false;
	}
	if (!("test" == writeData(p, 3)))
	{
		return false;
	}
	remove(p, 3);
	if (check(p, 3))
	{
		return false;
	}
	return true;
}


int main()
{
	if (testing)
	{
		cout << "Testing is positive" << endl;
	}
	else
	{
		cout << "Testing is negative" << endl;
	}
	cout << "" << endl;
	cout << "Hello! Choose action" << endl;
	cout << "0 - work is over" << endl;
	cout << "1 - insert element in AVL tree" << endl;
	cout << "2 - remove element in AVL tree" << endl;
	cout << "3 - check element in AVL tree" << endl;
	cout << "4 - find data of element in AVL tree throw key" << endl;

	node* p = NULL;
	int reaction = -2;
	
	while (reaction != -1)
	{
		cout << "Enter command ";
		cin >> reaction;
		switch (reaction)
		{
		case 0:
		{
			reaction = -1;
			cout << "Goodbye";
			break;
		}
		case 1:
		{
			cout << "Enter the key and data: ";
			string data = "";
			int key = 0;
			cin >> key;
			cin >> data;
			p = insert(p, key, data);
			cout << "Added successfully!" << endl;
			break;
		}
		case 2:
		{
			cout << "Enter the key: ";
			int key = 0;
			cin >> key;
			remove(p, key);
			cout << "Removed successfully!" << endl;
			break;
		}
		case 3:
		{
			cout << "Enter the key: ";
			int key = 0;
			cin >> key;
			if (check(p, key))
			{
				cout << "The node there is :)" << endl;
			}
			else
			{
				cout << "The node there is not :(" << endl;
			}
			break;
		}
		case 4:
		{
			cout << "Enter the key: ";
			int key = 0;
			cin >> key;
			string tmp = writeData(p, key);
			if (tmp == "") 
			{
				cout << "There is not this node! :(" << endl;
			}
			else
			{
				cout << tmp << endl;
			}
			break;
		}
		default:
		{
			cout << "Write another number" << endl;
			break;
		}

		}
		
	}
}
