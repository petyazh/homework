#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#include <queue>


using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node *right;
};

//Height of a Binary Tree
int height(Node* root) 
{
	
	if (!root)
	{
		return -1;
	}

	else
	{
		return  max(height(root->left)+1, height(root->right)+1);
	}

}

//Level Order Traversal
void levelOrder(node * root) 
{

	vector<node*> buffer_1;
	vector<node*> buffer_2;
	vector<node*>* pBuff1 = &buffer_1;
	vector<node*>* pBuff2 = &buffer_2;
	
	buffer_1.push_back(root);
	
	while (true)
	{
		vector<node*>& upper_side = *pBuff1;
		vector<node*>& next_side = *pBuff2;
		
		if (upper_side.size() == 0)
		{
			break;
		}

		for (int i = 0; i <upper_side.size(); i++)
		{
			node* prev = upper_side[i];
			cout << prev->data << " ";
		
			if (prev->left != nullptr)
			{
				next_side.push_back(prev->left);
			}
		
			if (prev->right != nullptr)
			{
				next_side.push_back(prev->right);
			}
		}
		
		upper_side.clear();
		swap(pBuff1, pBuff2);
	}
}

//Binary Search Tree : Lowest Common 
node *lca(node *root, int v1, int v2)
{
	if (root == nullptr)
	{
		return NULL;
	}

	if (root->data > v1 && root->data > v2)
	{
		return lca(root->left, v1, v2);
	}

	if (root->data < v1 && root->data < v2)
	{
		return lca(root->right, v1, v2);
	}

	return root;

}


//Swap Nodes [Algo]


struct node
{
	int data;
	struct node *left;
	struct node *right;

	node(int n)
	{
		data = n;
		left = NULL;
		right = NULL;
	}
};

void InOrder(struct node *root)
{
	if (!root)
		return;

	InOrder(root->left);
	cout << root->data << ' ';
	InOrder(root->right);
}

void swapSubtreesOfLevel(node *root, int k)
{
	if (!root)
		return;

	queue<node *> Q;
	Q.push(root);
	Q.push(NULL);
	int level = 1;

	while (!Q.empty())
	{
		node *tmp = Q.front();
		Q.pop();

		if (tmp == NULL)
		{
			if (!Q.empty())
			{
				Q.push(NULL);
			}
			level++;
		}
		else
		{
			if (level == k)
			{
				node *sw = tmp->left;
				tmp->left = tmp->right;
				tmp->right = sw;
			}

			if (tmp->left)
				Q.push(tmp->left);

			if (tmp->right)
				Q.push(tmp->right);
		}
	}
}



int main()
{
	int N;
	cin >> N;

	node *root = NULL;
	queue<node *> Q;
	int level = 1;

	if (N > 0)
	{
		root = new node(1);
		Q.push(root);
		Q.push(NULL);
	}

	while ((N > 0) && (!Q.empty()))
	{
		node *tmp = Q.front();
		Q.pop();

		if (tmp == NULL)
		{
			if (!Q.empty())
				Q.push(NULL);
			level++;
		}
		else
		{
			int a, b;
			cin >> a >> b;

			if (a != -1)
			{
				tmp->left = new node(a);
				Q.push(tmp->left);
			}

			if (b != -1)
			{
				tmp->right = new node(b);
				Q.push(tmp->right);
			}
			N--;
		}
	}

	int T;
	cin >> T;

	while (T > 0)
	{
		int k;
		cin >> k;
		int itr = 2;
		int lvl = k;
		while (lvl <= level)
		{
			swapSubtreesOfLevel(root, lvl);
			lvl = itr * k;
			itr++;
		}
		InOrder(root);
		cout << endl;
		T--;






	return 0;
}