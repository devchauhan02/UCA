#include<stdio.h>


// set the bit in any number using bitwise operator 

void set_bit(){
	int n = 101;
	int pos = 3;
	// set the bit of the question
	
	printf("%d",n);
	n |= 1<<pos;
	printf("%d",n);
}

// check if nth bit is set or not 

void bit_se_check(){
	int n = 8;
	int pos = 3; //check this pos bit set or not 
	
	printf("%d",n);
	if(n && (1<<pos)){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
}

// toogle the bit 

void toggle(){
	int n = 8;
	int pos = 1;
	printf("%d\n",n);
	n^=(1<<pos);
	printf("%d\n",n);
}

// write a programme to reverse a bit 

// count set bit 

void count_set_bit(){
	int n = 12;
	int ans = 0;
	while(n){
		ans+=(n&1); // count the set bit of the n if last bit is one the 1 & 1 is 1 then answer ++
		n = n>>1;
	}
	printf("%d\n",ans);
}

// find the min and max btw two number using bitwise

void min(){
	int a = 2;
	int b = 4;
	int res = (b^(a^b) & -(a<b));
	printf("min is :- >  %d\n",res);
}

// max

void max(){
	int a = 2;
	int b = 4;
	int res = (a^(a^b) & -(a<b));
	printf("max is : ->  %d\n",res);
}

// In 1 byte swap the first 4 bit and the last 4 bit 

void swap_bit(){
	
	unsigned char n  = 0b11010101;
	unsigned char lower_mask = ~(-1 << 4); // last four bit are set other wise zero 
	unsigned char lower_nibble = (n & lower_mask)<<4;
	unsigned char uper_nibble = (n & (lower_mask << 4)) >> 4;

	char ans = lower_nibble | uper_nibble;
	

	 for (int i = 7; i >= 0; i--) {
        	printf("%c", (ans & (1 << i)) ? '1' : '0');
   	 }
    	printf("\n");


}

// print -1 if number is negative and +1 is number is positive  and 0 if no is zero 

void print_negative_positive_zero(){
	int n;
	printf("enter your number\n");
	scanf("%d",&n);
	int sign = (n>>31);
	int mask = ((n | ~n + 1)>>31) & 1;
	int ans = mask | sign;

	printf("%d\n",ans);
}
	
int main(){	

	// bit_se_check();
       // toggle();
       // count_set_bit();
      print_negative_positive_zero();
}
