#include<stdio.h>
#include<stdlib.h>
struct my_node
{
	int data;
	struct my_node *next;
};

typedef struct my_node node;

void initialize(node *start){
	start = NULL;
}

void push(node *start, int item){
	node *n1 = (node*)malloc(sizeof(node));
	n1->data = item;
	n1->next = start->next;
	start->next = n1;
	
}

void printList(node* start){
	node* temp = start->next;
	while(temp!=NULL){
		printf("%d\n",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void pop(node *start){
	if(start!=NULL){
		node *temp = start->next;
		start->next = start->next->next;
		free(temp); 
	}
}

int main(int argc, char const *argv[])
{
	node start;
	initialize(&start);
	for (int i = 0; i < 10; ++i)
	{
		push(&start, i);
	}
	printList(&start);
	pop(&start);
	printList(&start);
	return 0;
}