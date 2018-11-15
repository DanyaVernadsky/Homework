#include <string>
using namespace std;


namespace tree
{
	struct node;
	node* insert(node* p, int key, string data);//вставляем элемент
	node* remove(node* p, int k); // удаление ключа k из дерева p
	bool check(node* p, int key);//проверяем эл-т
	string writeData(node* p, int key);//Строка с соотв. ключом
	node* createNode();
	
}