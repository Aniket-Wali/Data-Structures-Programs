#include<stdio.h>
struct mystack{
	int top;
	int data[100];
};
typedef struct mystack mystack;
void initialise(mystack *s){
	s->top = -1;
}

int isEmpty(mystack *s){
	if(s->top==-1)
		return 1;
	else
		return 0;
}

int isFull(mystack *s){
	if(s->top==99)
		return 1;
	else
		return 0;
}

void push(mystack *s, int item){
	if(isFull(s))
		printf("Stack is Full\n");
	else{
		int i = ++s->top;
		s->data[i]=item;
	}
}
int pop(mystack *s){
	if(isEmpty(s)){
		return 0;
	}
	else
	{
		int item = s->data[s->top];
		s->top--;
		return item;
	}
}
/*void printStack(mystack *s){
	for (int i = 0; i < s->top; ++i)
	{
		printf("%d\n",s->data[i] );
	}
}*/
int main()
{
	mystack s;
	initialise(&s);
	//printf("%d\n",s.top );
	for (int i = 1; i < 20; i++)
	{
		push(&s,i);
	}
	//printStack(&s);
	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n",pop(&s) );
	}
	return 0;
}
