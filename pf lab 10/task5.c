#include<stdio.h>

int sum(int num){
   if(num == 0){
   	return 0;
   }else{
   	return num%10 + sum(num/10);
	  
   }
   
}

int main(){
	int num,result;
	printf("Enter a number:");
	scanf("%d", &num);
	result= sum(num);
	printf("The sum of digits is: %d\n", result);
}
