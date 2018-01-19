#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

void moveNode(Node** destination, Node** source)
{
	Node* newNode = *source;
	if (newNode == NULL)
	{
		cout << "Mistake" << endl;
		return ;
	}
	*source = newNode->next;
	newNode->next = *destination;
	*destination = newNode;
}

 Node*MergeSort( Node* a,  Node* b)
{
	 Node* result = NULL;
	if (a == NULL)
		return(b);
	else if (b == NULL)
		return(a);

	if (a->data <= b->data)
	{
		result = a;
		result->next = MergeSort(a->next, b);
	}
	else
	{
		result = b;
		result->next = MergeSort(a, b->next);
	}
	return(result);
}

void push(Node**head, int new_data)
{
	Node* new_node = new Node;
	new_node->data = new_data;
	new_node->next = (*head);
	(*head) = new_node;
}

void print(Node* node)
{
	while (node != NULL)
	{
		cout << node->data << " ";
		node = node->next;
	}
}

int main()
{

	Node * res = NULL;
	Node *a = NULL;
	Node* b = NULL;

	push(&a, 1);
	push(&a, 3);
	push(&a, 5);
	push(&a, 6);
	push(&a, NULL);
	push(&b, 2);
	push(&b, 4);
	push(&b, 7);
	push(&b, NULL);

	res = MergeSort(a, b);
	print(res);
	cout << endl;

	Node *c = NULL;
	Node* d = NULL;
	push(&c, 15);
	push(&c, NULL);
	push(&d, 12);
	push(&d, NULL);
	
	res = MergeSort(c, d);
	print(res);
	cout << endl;

	Node *e = NULL;
	Node* f = NULL;

	push(&e, 1);
	push(&e, NULL);
	push(&f, 2);
	push(&f, NULL);

	res = MergeSort(e, f);
	print(res);






	return 0;

}