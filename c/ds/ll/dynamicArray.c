#include<stdio.h>
#include<stdlib.h>

int main( void ){
	
	int i, n;
	printf("Enter no of element to allocate the memory : ");
	scanf("%d",&n);
	int *arr = (int *)malloc(sizeof(int)*n);

	printf("Enter the element sequentially : \n");
	for(i=0; i<n; i++){
		scanf("%d",arr++);
	}

	printf("Your array is in reverse :\n");
	while(n){\
		printf("%d\t",*--arr);
		n--;
	}
	puts("");
	return 0;
}
