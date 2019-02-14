#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	char data[20];
	struct node *next;
};
typedef struct node node;

struct queue
{
	node *front;
	node *rear;
};
typedef struct queue queue;

void initialize(queue *q)
{
	q->front=NULL;
	q->rear=NULL;
}

void insert(queue *q,char item[])
{
	node *n1;
	n1=(node*)malloc(sizeof(node));
	//n1->data=item;
	strcpy(n1->data, item);
	n1->next=NULL;
	
	if(q->rear==NULL)
	{
		q->front=q->rear=n1;
	}
	else
		{
		 q->rear->next=n1;
		 q->rear=n1;
		}
}

void display(queue *q)
{
	node *temp=q->front;
	while(temp!=q->rear)
	{
		printf("%s\n",temp->data);
		temp=temp->next;
	}
	printf("%s",temp->data);
}

int main()
{
	queue q1;
	char s[80], *ptr;
	initialize(&q1);
	printf("enter your string\n");
	fgets(s, 80, stdin);
	ptr = strtok (s," .,-");
  	while (ptr != NULL)
  	{
    	insert(&q1, ptr);
    	ptr = strtok (NULL, " .,-");
  	}
  	printf("Splitted String stored in queue :\n");
	display(&q1);
}