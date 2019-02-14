#include<stdio.h>
#include<stdlib.h>
struct my_node
{
	int data;
	struct my_node *next;
};

struct my_stack
{
	struct my_node *top;
};

typedef struct my_stack stack;
typedef struct my_node node;

void initialize(stack *s){
	s->top = NULL;
}

void push(stack *s, int item){
	node *n1 = (node*)malloc(sizeof(node));
	n1->data = item;
	n1->next = s->top;
	s->top = n1;
}

void pop(stack *s){
	if(s->top!=NULL){
		node *temp = s->top;
		s->top = s->top->next;
		free(temp);
	}
}

void printStack(stack *s){
	node *temp = s->top;
	while(temp!=NULL){
		printf("%d\n",temp->data );
		temp = temp->next;
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	stack s;
	int data = 100;
	initialize(&s);
	for (int i = 0; i < 10; i++)
	{
		push(&s, data);
		data = data + 100;
	}
	printStack(&s);
	pop(&s);
	printStack(&s);
	return 0;
}