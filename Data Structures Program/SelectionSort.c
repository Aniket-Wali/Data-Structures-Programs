#include<stdio.h>
#include<string.h>
int main(int argc, char const *argv[])
{
	int arr[10];
	int min, temp=0, flg;
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 0; arr[i]!='\0' ; i++)
	{
		for (int j = i+1; arr[j]!='\0'; j++)
		{
			if(arr[i]>arr[j]){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for (int i = 0; arr[i]!='\0'; i++)
	{
		printf("%d  ",arr[i] );
	}
	return 0;
}