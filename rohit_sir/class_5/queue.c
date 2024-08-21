#include<stdio.h>
#include "list.h"

int queue[n+1];
void push(int *arr,int n, int val){
	for(int i = 1; i<=n; i++){
		queue[i] = arr[i-1];
	}
	queue[0] = val;
}


