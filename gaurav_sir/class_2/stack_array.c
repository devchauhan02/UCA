#include<stdio.h>
#include<assert.h>
#include<limits.h>


int *array = NULL;
int N = 0;
int max_size = 1;

void resize_array(int new_size){
	int *new_array = (int*) malloc(sizeof(int));
	for(int i=0; i<N; i++){
		new_array[i] = array[i];
	}
	int *temp = array;
	array = new_array;
	free(temp);

}

void push(int item){
	if(N==0){
		resize_array(max_size);
	}
	else if(N==max_size){
		resize_array(2*max_size);
		max_size*=2;
	}
	array[N++] = item;
}
int pop(){

	if(size()==0){
		printf("stack underflow \n");
		exit(1);
	}

	int item = array[--N];
	if(size()>0 && size()==max_size/4){
		max_size/=2;
		resize_array(max_size);
	}
	return item;
}

int peek(){
	if(size()==0){
		printf("stack is underflow\n");
		exit(1);
	}

	return array[N-1];
}
void print(){
	int i;
	
	if(size()==0){
		printf("stack underflow\n");
		exit(1);
	}
	for(i = size()-1; i>=0; i--){
		printf("%d ",array[i]);
	}
	printf("\n");
}



int size(){
	return N;
}



int isEmpty(){
	return N==size();
}


void loop(){
	int choices,data;
	while(1){
		printf("1. for push the value\n");
		printf("2. for pop the value\n");
		printf("3. for top value \n");
		printf("4. for prtint the stack \n");
		printf("5. for exit the loop\n");
		scanf("%d",&choices);
		
		switch(choices){
			
		
			case 1:
				printf("enter your elemet\n");
				scanf("%d",&data);
				push(data);
				break;
			case 2: 
				printf("popping element are : %d \n",pop());
				break;
			case 3:
				printf("the top value are : %d\n",peek());
				break;
			case 4:
				printf("stack element are : \n");
				print();
				break;
			case 5:
				exit(1);
			default :
				printf("enter your valid choices\n");
				break;
		}
	}
}

int main(){

	loop();
}


