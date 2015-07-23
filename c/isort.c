#include<stdio.h>

#define MAX 50

void sort(int arr[], int n);
void insert(int arr[], int n);

int main(void)
{
	int arr[MAX],n,i;
	puts("\n\t\t::INSERTION SORT USING RECURSION::\n");
	puts("Enter the number of elements:\n");
	scanf("%d",&n);
	puts("Enter the elements:\n");
	for(i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}
	
	sort(arr, n-1);
	
	puts("Sorted array is as :\n");
	
	for(i = 0; i < n; i++)
	{
		printf("%d\t",arr[i]);
	}	
	return 0;
}


void sort(int arr[], int n)
{
	if(n>0)
	{
		sort(arr, n-1);
		insert(arr, n);
	}
}

void insert(int arr[], int n)
{
	int i;
	int key = arr[n];
	printf("\nkey : %d\n",key);
	for(i=n-1 ; i>=0 && key < arr[i]; i--)
	{
		arr[i+1] = arr[i]; 
	}
	arr[i+1] = key;
	printf("\t i %d arr at i %d\n",i,arr[i]);
	puts("subarray is :\n");
	for(i=0; i<=n;i++)
	{
		printf("%d\t",arr[i]);
	}
}
