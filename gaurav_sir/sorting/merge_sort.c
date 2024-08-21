// selection sort -> selection sort is sorting algorithim were we solved using 
// pivot index take a minimum and the set in left 

#include<stdio.h>
#include<assert.h>

void exch(int arr[], int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}


void merge(int arr[], int aux[], int left, int mid, int right){

	for(int i = left; i<=right; i++){
		aux[i] = arr[i];
	}
	int i = left;
	int j = mid+1;
	for(int k = left; k <= right; k++){
		if(i>mid) arr[k] = aux[j++];
		else if(j>right) arr[k] = aux[i++];
		else if(aux[i]<=ux[j])arr[k] = arr[i++];
		else arr[k] = aux[j++];
	}

	
}

void merge_sort_recursive(int arr[], int aux[], int left, int right){
	if(left>=right){
		int mid = (left+right)/2;
		merge_sort_recursive(arr,aux,left,mid);
		merge_sort_recursive(arr,aux,mid+1,right);
		merge(arr,aux,left,mid,right);
	}

}

void merge_sort(int arr[], int n){
	int *aux = (int *)malloc(n* sizeof(int));
	merge_sort_recursive(arr,aux,0,n-1);
	free(aux);
}
void selection_sort(int arr[],int n) // time complexity every input in O(n^2):
{
	for(int i = 0; i < n; i++)
	{
		int min = i;
		for(int j = i+1; j < n; j++)
		{
			if(arr[min]>arr[j]) min = j;
		}
		exch(arr,i,min);
	}
}

void test_simple_input()
{
	int n = 5;
	int arr[] = {3,1,5,2,4};
	int expected_output[] = {1,2,3,4,5};
	merge_sort(arr,n);
	for(int i = 0; i<n; i++){
		printf("%d",arr[i]);
	}
	printf("\n");
	for(int i = 0; i < n; i++)
	{
		assert(arr[i]==expected_output[i]);
	}
}

int main(){
	test_simple_input();
}


