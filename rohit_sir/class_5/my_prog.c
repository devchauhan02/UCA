#include<stdio.h>
#include "list.h"

int main(){
	int arr[10];
	push(arr,-1,11);
	push(arr,0,12);
	push(arr,1,13);
	printf("%d %d %d",arr[0],arr[1],arr[2]);	
}
