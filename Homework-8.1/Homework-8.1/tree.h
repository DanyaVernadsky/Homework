#include <string>
using namespace std;


namespace tree
{
	struct node;
	node* insert(node* p, int key, string data);//��������� �������
	node* remove(node* p, int k); // �������� ����� k �� ������ p
	bool check(node* p, int key);//��������� ��-�
	string writeData(node* p, int key);//������ � �����. ������
	node* createNode();
	
}