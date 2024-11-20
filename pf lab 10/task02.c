#include<stdio.h>

int percentagecalculator(int num){
	float percent;
	int i;
	for(i=1;i<=100;i++){
		percent = num*(i/100.0);
		printf("%d percent = %.3f\n",i,percent);
	}
}

int main(){
	int num;
	printf("Enter a value to split in percentage:");
	scanf("%d",&num);
	
	percentagecalculator(num);
	return 0;
}

