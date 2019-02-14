#include<stdio.h>
#define MAX 20
struct my_queue
{
	int front, rear, data[MAX];
};
typedef struct my_queue queue;
void initialize(queue *q){
	q->front = MAX-1;
	q->rear = MAX-1;
}
int isEmpty(queue *q){
	if(q->front==q->rear)
		return 1;
	else
		return 0;
}
int isFuLL(queue *q){
	int temp;
	if(q->rear==MAX-1)
		temp = 0;
	else
		temp = q->rear + 1;
	if(q->front==temp)
		return 1;
	else
		return 0;
}
void insert(queue *q, int item){
	if(!isFuLL(q)){
		if(q->rear==MAX-1)
			q->rear = 0;
		else
		{	
			q->rear++;
		}
		q->data[q->rear] = item;
	}
}

int delete(queue *q){
	if(!isEmpty(q)){
		if(q->front==MAX-1)
			q->front = 0;
		else
			q->front++;
		return(q->data[q->front]);
	}
}
void display(queue *q){
	int temp;
	if(q->front==MAX-1)
		temp = 0;
	else
		temp = q->front+1;
	for (int i = temp; i <=q->rear; i++)
	{
		printf("%d\n",q->data[i] );
	}
	printf("\n");
}
int main(int argc, char const *argv[])
{
	queue q;
	initialize(&q);
	for (int i = 0; i <=10; i++)
	{
		insert(&q, i);
	}
	display(&q);
	for (int i = 0; i < 5; ++i)
	{
		delete(&q);
	}
	display(&q);
	return 0;
}