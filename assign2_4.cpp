#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void generateNumbers(int *arr){
	srand(time(NULL));
	for (int j = 0; j <= 100; j++)
		arr[j] = rand() % 100;
}

int main()
{
	int arr[100], l[100], r[100];
	int m = 0, n = 0;
	int key, i;
	generateNumbers(arr);
	int size = sizeof(arr)/sizeof(arr[0]);
	for(int i = 0; i < size; i++){
		if(arr[i] % 2 == 0){
			l[m] = arr[i];
			m++;
		}
		else{
			r[n] = arr[i];
			n++;
		}
	}
	
	for (int j = 1; j <m ; j++){
		key = l[j];
		i = j - 1;
		while(i >= 0 && l[i] > key){
			l[i+1] = l[i];
			i-=1;
		}
		l[i+1] = key;
	}
	for (int j = 1; j <n ; j++){
		key = r[j];
		i = j - 1;
		while(i >= 0 && r[i] > key){
			r[i+1] = r[i];
			i-=1;
		}
		r[i+1] = key;
	}

	for (int i = 0; i < m; i++)
		arr[i] = l[i];
	for (int i = 0; i <n ; i++)
		arr[m++] = r[i];

	cout<<"My Sorted Array : "<<endl;
	for(int j = 0; j < size; j++)
		cout<<arr[j]<<"\t";
	cout<<endl;

	return 0;
}