#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stack>
#include <string>
#include <iostream>
using namespace std;


bool check(string line)
{
	stack <int> stack;
	for (char& i : line)
	{
		switch (i)
		{
		case '(':
			stack.push(i);
			break;
		case '[':
			stack.push(i);
			break;
		case '{':
			stack.push(i);
			break;
		case ')':
			if (stack.top() == i)
			{
				stack.pop();
			}
			else
			{
				return false;
			}
			break;
		case ']':
			if (stack.top() == i)
			{
				stack.pop();
			}
			else
			{
				return false;
			}
			break;
		case '}':
			if (stack.top() == i)
			{
				stack.pop();
			}
			else
			{
				return false;
			}
			break;
		}
	}
	if (stack.size != 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int main()
{
	cout << "Enter a line: ";
	string line = "";
	cin >> line;
	if (check(line) == false)
	{
		cout << "Line is incorrect" << endl;
	} 
	else
	{
		cout << "Line correct! You are not hopeless :) " << endl;
	}
	cin >> line;

	return 0;
}