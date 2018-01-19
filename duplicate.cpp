#include "iostream"

struct Node
{
	int data;
    Node* next;
};

void remove(Node* head)
{
	 Node* current = head;
	 Node* new_next;

	 if (current == NULL)
	 {
		 return;
	 }

	while (current->next != NULL)
	{
		if (current->data == current->next->data)
		{
			new_next = current->next->next;
			free(current->next);
			current->next = new_next;
		}
		else 
		{
			current = current->next;
		}
	}
}

void push(struct Node** head, int new_data)
{
	
	Node* new_node = new Node;
		
	new_node->data = new_data;
	new_node->next = (*head);

	(*head) = new_node;
}

int main()
{
	Node* head = NULL;

	push(&head, 1);
	push(&head, 1);
	push(&head, 3);
	push(&head, 3);
	push(&head, 5);
	push(&head, 6);

	remove(head);

	return 0;
}