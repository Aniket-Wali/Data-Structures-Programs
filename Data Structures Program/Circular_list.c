#include<stdio.h>
#include<stdlib.h>
struct my_node
{
	int data;
	struct my_node *next; 
};
struct list
{
	struct my_node *start;
};
typedef struct my_node node;

void initialise(node *start){
	start = NULL;
}

void insert(node *start, int data){
	node *n1 = (node*)malloc(sizeof(node));
	n1->data = data;
	if(start==NULL){
		start = n1;
		n1->next = n1;
	}
	else{
		n1->next = start->next;
		start->next = n1;
		start = n1;
	}
}

void printList(node *start){
	node *temp = start->next;
	do{
		printf("%d\n",temp->data );
		temp = temp->next;
	}while(temp!=start);
}

int main(int argc, char const *argv[])
{
	node start;
	initialise(&start);
	for (int i = 1; i <=10; i++)
	{
		insert(&start, i);
	}
	printList(&start);
	return 0;
}