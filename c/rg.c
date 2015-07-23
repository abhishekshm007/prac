#include<stdio.h>

int main(){
	int arr[100];
	int i;
	for( i = 0; i< 100; i++){
		arr[i] = 100+i;
	}
	int *(a)[5] = (int (*)[5]) arr;
	for(i = 0; i< 5; i++)
	{
		printf("\n%d",*a[i]);
	}
}
