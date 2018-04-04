#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next_node;
};

struct Node *top;

void initialize() 
{
	top = NULL;
}

int Stack_isEmpty() 
{
	return top == NULL; 
}

void Stack_push(int value)
{
	struct Node *new_node;
	new_node = malloc(sizeof(struct Node));
	new_node->data = value;
	new_node->next_node = top;
	top = new_node;
}


void Stack_pop() 
{
	struct Node *removed_node = top;
	top = top->next_node;
	free(removed_node);
}

void Stack_peek()
{
	if(top == NULL)
		printf("NULL\n");
	else
		printf("Take a peek: %d\n", top->data);
}

int main(int argc, char *argv[])
{
	initialize();
	Stack_push(10);
	Stack_peek();
	Stack_push(20);
	Stack_peek();
	Stack_push(30);
	Stack_peek();
	Stack_pop();
	Stack_peek();
	Stack_pop();
	Stack_peek();
	Stack_pop();
	Stack_peek();
	return 0;
}
