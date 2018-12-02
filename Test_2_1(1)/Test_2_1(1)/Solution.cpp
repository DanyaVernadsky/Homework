#include <list>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{

	cout << "Enter a and b" << endl;
	int a = 0;
	int b = 0;
	cin >> a;
	cin >> b;
	list <int> list1a{};
	list <int> list2ab{};
	list <int> list3b{};
	ifstream f("numbers.txt");
	if (f.is_open())
	{
		while (!f.eof())
		{
			int tmp = 0;
			f >> tmp;
			if (tmp < a)
			{
				list1a.push_back(tmp);
			} 
			else
			{
				if (tmp >= a && tmp <= b)
				{
					list2ab.push_back(tmp);
				}
				else
				{
					list3b.push_back(tmp);
				}
			} 

			
		}
	}
	else
	{
		cout << "Error with file" << endl;
	}

	ofstream g;// поток для записи
	g.open("result.txt");
	if (g.is_open())
	{
		g << a << " " << b << endl;
		for (auto element : list1a)
		{
			g << element << " ";
		}
		for (auto element : list2ab)
		{
			g << element << " ";
		}
		for (auto element : list3b)
		{
			g << element << " ";
		}
	}
	else
	{
		cout << "Error with outfile" << endl;
	}
	

	f.close();
}