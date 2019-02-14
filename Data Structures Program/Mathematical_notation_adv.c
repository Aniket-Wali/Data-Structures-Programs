#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
	int a = 0, b = 0, c = 0;
	char ch[50];
	scanf("%s",ch);
	for (int i = 0; i < strlen(ch); i++)
	{
		if(ch[i]=='['){
			a++;
		}
		else if(ch[i]==']'){
			a--;
			if(a==-1 || a<b || a<c ){
				printf("Expression is invalid.\n");
				exit(0);
			}
		}
		else if(ch[i]=='{'){
			b++;
		}
		else if(ch[i]=='}'){
			b--;
			if(b==-1 || b<c){
				printf("Expression is invalid.\n");
				exit(0);
			}
		}
		else if(ch[i]=='('){
			c++;
		}
		else if(ch[i]==')'){
			c--;
			if(c==-1){
				printf("Expression is invalid.\n");
				exit(0);
			}
		}
	}
	if(a!=0 || b!=0 || c!=0)
		printf("Expression is invalid\n");
	else 
		printf("Expression is valid\n");
	return 0;
}