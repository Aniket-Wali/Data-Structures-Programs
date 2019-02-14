#include<stdio.h>
#include<string.h>

int binarySearch(int arr[], int key, int low, int high){
	int p;
	p = (low + high)/2;
	if(low<=high){
		if(key==arr[p])
			return 1;
		if(key<arr[p]){
			high = p-1;
			return binarySearch(arr, key, low, high);
		}
		else if(key>arr[p]){
			low = p+1;
			return binarySearch(arr, key, low, high);
		}
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	int arr[100], key, low = 0, high = 9;
	for (int i = 0; i < 10; i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter number to be search : ");
	scanf("%d", &key);
	int k = binarySearch(arr, key, low, high);
	if(k)
		printf("Element found\n");
	else
		printf("Not found\n");
	return 0;
}