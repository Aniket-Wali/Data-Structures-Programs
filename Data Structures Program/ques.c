#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct my_node 
{
	 char data[20];
	 struct my_node *next;
};

struct my_queue
{
	struct my_node *front;
	struct my_node *rear;
};

typedef struct my_queue queue;
typedef struct my_node node;

void initialize(queue *q){
	q->rear = NULL;
	q->front = NULL;
}

int isEmpty(queue *q){
	if(q->front == q->rear)
		return 1;
	else
		return 0;
}

void enqueue(queue *q, char item[]){
	node *n1 = (node*)malloc(sizeof(node));
	strcpy(n1->data, item);
	n1->next = NULL;
	if(q->rear==NULL){
		q->front = q->rear = n1;
	}
	else{
		q->rear->next = n1;
		q->rear = n1;
	}
}

void dequeue(queue *q){
	
		node *n1 = q->front;
		q->front = q->front->next;
		free(n1);
	
}

void printQueue(queue *q){
	node *temp = q->front;
	while(temp!=NULL){
		printf("%s \n",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	queue q1;  int i=0,l;
	char s[80], *pch;

	initialize(&q1);
	printf("enter your string\n");
	scanf("%s",s);
	pch = strtok (s," ");
  	while (pch != NULL)
  	{
    	enqueue(&q1, pch);
    	pch = strtok (NULL, " ");
  	}
	printQueue(&q1);
	return 0;
}