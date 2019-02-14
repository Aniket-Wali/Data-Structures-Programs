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
void insert(node *start, int item){
	node *n1 = (node*)malloc(sizeof(node));
	n1->data = item;
	n1->next = NULL;
	start->next = n1;
	
}
void insertAtLast(node* start, int item){
	node* temp = start->next;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	node* n1 = (node*)malloc(sizeof(node));
	temp->next = n1;
	n1->data = item;
	n1->next = NULL;	
}
void insertAfteri(node *start, int item, int i){
	node *temp = start->next;
	while(temp->data!=i){
		temp = temp->next;
	}
	node *n1 = (node*)malloc(sizeof(node));
	n1->data = item;
	n1->next = temp->next;
	temp->next = n1;
}
void printList(node* start){
	node* temp = start->next;
	while(temp!=NULL){
		printf("%d->",temp->data);
		temp = temp->next;
		if(temp==NULL)
			printf("NULL");
	}
	printf("\n");
}
void DeleteFirstNode(node *start){
	if(start!=NULL){
		node *temp = start->next;
		start->next = start->next->next;
		free(temp); 
	}
}
void DeleteAti(node *start, int i){
	node *temp = start->next;
	while(temp->next->data!=i){
		temp = temp->next;
	}
	node *ref = temp->next;
	temp->next = temp->next->next;
	free(ref);
}

int main(int argc, char const *argv[])
{
	node start;
	initialize(&start);
	insert(&start, 11);
	for (int i = 2; i <=10; ++i)
	{
		insertAtLast(&start, i);
	}
	insertAfteri(&start, 12, 4);
	printList(&start);
	DeleteFirstNode(&start);
	DeleteAti(&start, 12);
	printList(&start);
	return 0;
}