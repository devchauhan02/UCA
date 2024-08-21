#include<stdio.h>



void swap(int arr[], int a, int b){
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void sort(int* arr, int size,int(*compare)(int,int)){
	for(int i = 0; i<size; i++){
		for(int j = 0; j<size-i-1; j++){
			if(compare(arr[j],arr[j+1])){
				swap(arr,j,j+1);
			}
		}
	}
}

int asc(int a, int b){
	return a>b;
}
int desc(int a, int b){
	return b>a;
}

void print(int arr[], int size){
	for(int i = 0; i<size; i++){
		printf("%d ",arr[i]);
	}
}

int main(){
	int arr[5] = {1,2,3,4,5};
	sort(arr,5,desc);
	print(arr,5);
}
