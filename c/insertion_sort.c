#include<stdio.h>
#include<time.h>
#define MAX 50
void sort(int *, int n);

int main()
{
	double t,s,e;
	int key[MAX];
	int i,n;
	s = clock();
	printf("Enter the number of element want to sort : \n");
	scanf("%d",&n);
	
	printf("Enter the elements : \n");
	for(i=0; i< n; i++)
	{
		scanf("%d",&key[i]);
	}
	
	sort(key,n);
	
	printf("Sorted array is :\n");
	for(i=0; i<n; i++)
	{
	printf("%d   ",key[i]);
	}
	e = clock();
	t = e-s;
	printf("\ntime taken is %f",t);
}

void sort(int *key, int n)
{
	int i,j,current;
	
	for(j=1; j<n; j++)
	{
		current = key[j];
		i=j-1;
		while(i >= 0 && key[i] > current)
		{
			key[i+1] = key[i];
			i--;
		}
		key[i+1] = current;
	}
}
