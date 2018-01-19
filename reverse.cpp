#include "iostream"

using namespace std;

struct Node
{
	int data;
	Node* next;
	Node* prev;
};

void reverse(Node** head)
{
	Node* temp = NULL;
	Node* current = *head;

	while (current != NULL)
	{
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->next;
	}

	if (temp != NULL)
	{
		*head = temp->prev;
	}
}

void push(Node** head, int new_data)
{
	Node* new_node = new Node;
	new_node->data = new_data;
	new_node->prev = NULL;
	new_node->next = (*head);

	if ((*head) != NULL)
	{
		(*head)->prev = new_node;
	}

	(*head) = new_node;
}


int main()
{

	Node* head = new Node;

	push(&head, 2);
	push(&head, 4);
	push(&head, 6);

	reverse(&head);

	return 0;
}

