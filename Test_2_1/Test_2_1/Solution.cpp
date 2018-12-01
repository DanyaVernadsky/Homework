#include <iostream>
#include <string>
#include <fstream> 
#include <list>

using namespace std; 

int main() {
	ifstream file("/demo/Homework/Test_2_1/numbers.txt");
	list <int> list{};
	if (file.is_open())
	{
		while (!file.eof())
		{
			int tmp = 0;
			file >> tmp;
			list.push_back(tmp);
		}
	} 
	else
	{
		cout << "Error with file" << endl;
	}

	while (!list.empty())
	{
		if (list.front() == list.back())
		{
			if (list.size() != 1)
			{
				list.pop_back();
				list.pop_front();
			}
			else
			{
				list.pop_back();
			}
		}
		else
		{
			cout << "False" << endl;
			return 0;
		}
	}

	/*for (const auto &element : list)
	{
		cout << element << endl;
	}*/
	file.close();
	cout << "True" << endl;
	return 1;
}