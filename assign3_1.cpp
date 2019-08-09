#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void generateNumbers(int *arr){
	srand(time(NULL));
	for (int j = 0; j <= 100; j++)
		arr[j] = rand() % 100;
}

void merge(int* arr, int p, int q, int r){
	int n1 = q - p + 1;
	int n2 = r - q;
	int ll[n1+1], rr[n2+1];
	for (int i = 0; i < n1; i++)
		ll[i] = arr[p+i];
	for(int i = 0; i < n2; i++)
		rr[i] = arr[q+i+1];
	ll[n1] = INT_MAX;
	rr[n2] = INT_MAX;
	int i = 0;
	int j = 0;
	for(int k = p; k <= r; k++){
		if(ll[i] <= rr[j])
			arr[k] = ll[i++];
		else
			arr[k] = rr[j++];
	}
}

void asc_merge_sort(int *arr, int p, int r){

	if(p<r){
		int q = (p+r)/2;
		asc_merge_sort(arr, p, q);
		asc_merge_sort(arr, q+1, r);
		merge(arr ,p, q, r);
	}
}

int main()
{	
	int arr[100];
	int p = 0;
	int r = sizeof(arr)/sizeof(arr[0]);
	generateNumbers(arr);
	asc_merge_sort(arr, p, r);
	cout<<"Ascending order in merge sort "<<endl;
	for(int j = 0; j < r; j++)
		cout<<arr[j]<<"\t";
	cout<<endl;
	return 0;
}