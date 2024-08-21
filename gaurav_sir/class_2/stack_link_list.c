#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
	int data;
	struct node* link;
} *top = NULL;

void push(int data){
	struct node* newNode = malloc(sizeof(newNode));
	if(newNode==NULL){
		printf("stack overflow");
		exit(1);
	}
	newNode->data = data;
	newNode->link = NULL;
	
	newNode->link = top;
	top = newNode;
}

int pop(){
	
	if(isEmpty())
	{
		printf("stack is undeflow");
		exit(1);
	}

	struct node* temp;
	temp = top;
	int val = temp -> data;
	top = top -> link;
	free(temp);
	temp = NULL;
	return val;
}

int peek(){

	if(isEmpty()){
		printf("stack is underflow .");
		exit(1);
	}

	return top->data;
}


void print(){
	struct node* temp;
	temp = top;

	if(isEmpty())
	{
		printf("stack is underflow .");
		exit(1);

	}

	printf("The stack element are : ");
	while(temp){
		printf("%d ",temp->data);
		temp = temp->link;
	}
	printf("\n");
}

int  isEmpty(){
	if(top==NULL){
		return 1;
	}
	return 0;
}



void loop(){
	int choices,data;
	while(1){
		printf("1. for push the element\n");
		printf("2. for pop the element \n");
		printf("3. for peek element \n");
		printf("4. for print the element \n");
		printf("5. for exit the loop \n");
		printf("Enter your choices \n");
		scanf("%d",&choices);
		
		switch(choices){
		case 1:
			printf("Enter your element : \n");
			scanf("%d",&data);
			push(data);
			break;

		case 2: 
			printf("deleted element are : %d\n",pop());
			break;
		case 3:
			printf("top element are : %d\n",peek());


			break;
		case 4:
	       	       print();break;

		case 5: exit(1);

		default:
			printf("wrong input please enter valid choices\n");
			break;
		}


	}
}

int main(){
	loop();
}
