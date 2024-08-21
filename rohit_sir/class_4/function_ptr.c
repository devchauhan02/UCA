#include<stdio.h>

int add(int a,int b){
	return a+b;
}

int minus(int a,int b){
	return a-b;
}

int mul(int a,int b){
	return a*b;
}

int divide(int a,int b){
	return a/b;
}

void performance(int (*operation)(int ,int),int a,int b){
	printf("%d\n",operation(a,b));
}


int main(){
	performance(add,10,5);
}
