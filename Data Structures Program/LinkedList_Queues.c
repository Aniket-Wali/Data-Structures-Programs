#include<stdio.h>
#include<stdlib.h>
struct my_node 
{
	 int data;
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

void enqueue(queue *q, int item){
	node *n1 = (node*)malloc(sizeof(node));
	n1->data = item;
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
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	queue q;
	int data;
	initialize(&q);
	for (int i = 1; i <= 10; i++)
	{
		printf("Enter Element : ");
		scanf("%d", &data);
		enqueue(&q, i);
	}
	printQueue(&q);
	printf("Dequeued Element is %d\n",dequeue(&q));
	printf("Dequeued Element is %d\n",dequeue(&q));
	printQueue(&q);
	return 0;
}