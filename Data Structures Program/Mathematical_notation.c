#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
	int a=0;
	char ch[30];
	scanf("%s",ch);
	for (int i = 0; i < strlen(ch); i++)
	{
		if(ch[i]=='(')
			a++;
		if(ch[i]==')'){
			a--;
			if(a==-1){
				printf("Expression is invalid.\n");
				exit(0);
			}
		}
	}
	if(a!=0)
		printf("Expression is invalid.\n");
	else
		printf("Expression is valid.\n");
	return 0;
}