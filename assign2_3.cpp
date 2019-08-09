#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void generateNumbers(int *arr){
	srand(time(NULL));
	for (int j = 0; j <= 100; j++)
		arr[j] = rand() % 1000;
}

void asc_desc_insertion_sort(int *arr, int size){
	int key, i;
	for (int j = 1; j <size ; j++){
		key = arr[j];
		i = j - 1;
		if(i<=50){
			while(i >= 0 && arr[i] > key){
			arr[i+1] = arr[i];
			i-=1;
			}
			arr[i+1] = key;
		}
		else{
			while(i >= 0 && arr[i] < key){
			arr[i+1] = arr[i];
			i-=1;
			}
			arr[i+1] = key;
		}
		
	}
	cout<<"Ascending Descending Order"<<endl;
	for(int j = 0; j < size; j++)
		cout<<arr[j]<<"\t";
	cout<<endl;
}


int main()
{
	
	int arr[100];
	generateNumbers(arr);
	int size = sizeof(arr)/sizeof(arr[0]);	
	asc_desc_insertion_sort(arr, size);
	return 0;
}