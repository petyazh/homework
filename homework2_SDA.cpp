// homework2_SDA.cpp : Defines the entry point for the console application.
// Petya Zhelyazkova

#include "stdafx.h"
#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include<vector>

using namespace std;

struct Node
{
	int data;
	Node *next;
};

struct Queue
{
	Node *s1;
	Node *s2;
};

void push(Node**topNode, int new_data)
{
	Node* new_node = new Node;

	if (new_node == NULL)
	{
		cout << "Mistake" << endl;
		return;
	}

	new_node->data = new_data;
	new_node->next = (*topNode);
	(*topNode) = new_node;
}

int pop(struct Node** top_node)

{
	int res;
	 Node *top;

	if (*top_node == NULL)
	{
		cout << "The stack is empty" << endl;
		return 0;
	}
	else
	{
		top = *top_node;
		res = top->data;
		*top_node = top->next;
		free(top);
		return res;
	}

}


void enqueue(Queue *q, int x)
{
	push(&q->s1, x);
}

int dequeue(Queue *q)
{
	int x;

	if (q->s1 == NULL && q->s2 == NULL)
	{
		cout << "The queue is empty" << endl;
		return 0;
	}

	if (q->s2 == NULL)
	{
		while (q->s1 != NULL)
		{
			x = pop(&q->s1);
			push(&q->s2, x);
		}
	}
	x = pop(&q->s2);
	return x;
}

void print(const vector<int>v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[0] << endl;
	}
}

int main()
{

	Queue *q = new Queue;
	q->s1 = NULL;
	q->s2 = NULL;
	
	vector<int> vecToPrint;

	int n = 0;
	cout << "input number of instructions" << endl;
	cin >> n;

	int instruction = 0;
	int number = 0;
	int x = 0;

	for (int i = 0; i < n; i++)
	{
		cout << "choose instruction 1/2/3" << endl;
		cin >> instruction;


		if (instruction == 1)
		{
			cout << "Number to put in the queue" << endl;
			cin >> number;
			enqueue(q, number);
		}
		else if (instruction == 2)
		{
			dequeue(q);
		}
		else if (instruction == 3)
		{
			vecToPrint.push_back(number);
		}
	}
 print(vecToPrint);









    return 0;
}

