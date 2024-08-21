
void push(int *arr,int n, int val){
	arr[n+1] = val;
};

int pop(int *arr, int n){
	int val = arr[n];
	arr[n] = 0;
	return val;
}
