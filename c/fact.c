#include<stdio.h>

int main(){
	long min, max, fact = 1;
	int i;
	printf("Enter the min and max : \n");
	scanf("%ld %ld",&min, &max);
	
	int counter = 1, result = 0;

	while(fact <= max){
		fact = fact * counter++;
		if(fact <= max && fact >= min){
			result++;
		}
	}

	printf("\nNo of occurences is %d\n", result);
	return 0;
}
