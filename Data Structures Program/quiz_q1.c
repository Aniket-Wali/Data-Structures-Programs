#include<stdio.h>
#include<string.h>
struct Table
{
	int l,w;
	char m[20];
};
struct mystack{
	int top;
	struct Table data[100];
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

void push(mystack *s, int l, int w, char m[]){
	if(isFull(s))
		printf("Stack is Full\n");
	else{
		(s->top)++;
		s->data[s->top].l = l;
		s->data[s->top].w = w;
		strcpy(s->data[s->top].m,m) ;
	}
}
struct Table pop(mystack *s){
	if(!isEmpty(s))
	{
		return (s->data[s->top--]);
	}
}

int main(int argc, char const *argv[])
{
	mystack s;
	initialise(&s);
	push(&s, 20,30,"ABC");
	push(&s, 10,40,"PQR");
	push(&s, 340,560,"ABCD");
	push(&s, 30,770,"PQRS");
	push(&s, 20,30,"LMN");
	push(&s, 40,50,"SDFG");
	push(&s, 70,60,"WDWND");
	push(&s, 80,90,"DSDE");
	while(s.top>=0){
	struct Table item1 =pop(&s);
	printf("%d\t%d\t%s\n",item1.l,item1.w,item1.m );
	}
	return 0;
}
