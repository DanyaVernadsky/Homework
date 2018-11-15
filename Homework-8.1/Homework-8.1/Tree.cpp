#include <string>
#include "tree.h"


	using namespace std;
	

		struct tree::node // ��������� ��� ����� ������
		{
			int key;
			string data;
			unsigned char height;
			node* left;
			node* right;
			node(int k, string data)
			{
				key = k;
				this->data = data;
				left = right = 0;
				height = 1;
			}
		};

		//tree::node* tree::createNode()
		//{
		//	return new node;
		//}

		unsigned char height(tree::node* p)
		{
			if (p != nullptr)
			{
				return p->height;
			}
			else
			{
				return 0;
			}
		}

		int balanceFactor(tree::node* p)
		{
			return height(p->right) - height(p->left);
		}

		void fixheight(tree::node* p)//��������������� ���������� �������� ���� height ��������� ����
		{
			unsigned char hl = height(p->left);
			unsigned char hr = height(p->right);
			p->height = (hl > hr ? hl : hr) + 1;
		}

		tree::node* rotateright(tree::node* p) // ������ ������� ������ p
		{
			tree::node* q = p->left;
			p->left = q->right;
			q->right = p;
			fixheight(p);
			fixheight(q);
			return q;
		}

		tree::node* rotateleft(tree::node* q) // ����� ������� ������ q
		{
			tree::node* p = q->right;
			q->right = p->left;
			p->left = q;
			fixheight(q);
			fixheight(p);
			return p;
		}

		tree::node* balance(tree::node* p) // ������������ ���� p
		{
			fixheight(p);
			if (balanceFactor(p) == 2)
			{
				if (balanceFactor(p->right) < 0)
				{
					p->right = rotateright(p->right);
				}
				return rotateleft(p);
			}
			if (balanceFactor(p) == -2)
			{
				if (balanceFactor(p->left) > 0)
				{
					p->left = rotateleft(p->left);
				}
				return rotateright(p);
			}
			return p; // ������������ �� �����
		}

		tree::node* tree::insert(tree::node* p, int key, string data) // ������� ����� k � ������ � ������ p
		{
			if (!p)
			{
				return new tree::node(key, data);
			}
			if (key < (p->key))
			{
				p->left = tree::insert(p->left, key, data);
			}
			else
			{
				p->right = tree::insert(p->right, key, data);
			}
			return balance(p);
		}

		tree::node* findmin(tree::node* p) // ����� ���� � ����������� ������ � ������ p 
		{
			return p->left ? findmin(p->left) : p;
		}

		tree::node* removemin(tree::node* p) // �������� ���� � ����������� ������ �� ������ p
		{
			if (p->left == 0)
				return p->right;
			p->left = removemin(p->left);
			return balance(p);
		}

		tree::node* tree::remove(tree::node* p, int k) // �������� ����� k �� ������ p
		{
			if (!p)
			{
				return 0;
			}
			if (k < p->key)
			{
				p->left = tree::remove(p->left, k);
			}
			else
			{
				if (k > p->key)
				{
					p->right = tree::remove(p->right, k);
				}
				else //  k == p->key 
				{
					tree::node* q = p->left;
					tree::node* r = p->right;
					delete p;
					if (!r) return q;
					tree::node* min = findmin(r);
					min->right = removemin(r);
					min->left = q;
					return balance(min);
				}
				return balance(p);
			}
		}

		bool tree::check(tree::node* p, int key) //��������� ������� ��������
		{
			if (!p)
			{
				return false;
			}

			if (p->key == key)
			{
				return true;
			}
			else
			{
				if (p->key < key)
				{
					return tree::check(p->right, key);
				}
				else
				{
					return tree::check(p->left, key);
				}
			}
		}

		string tree::writeData(tree::node* p, int key)
		{
			if (!p)
			{
				return "";
			}

			if (p->key == key)
			{
				return p->data;
			}
			else
			{
				if (p->key < key)
				{
					return writeData(p->right, key);
				}
				else
				{
					return writeData(p->left, key);
				}
			}
		}