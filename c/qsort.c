#include<stdio.h>
#define MAX 50
void swap(int *a, int *b)
{
        int temp = *a;
        *b = *a;
        *b = temp;
}

void quicksort(int arr[], int l, int h)
{
puts("hello");
        int mid;
        if(l<h)
        {
        mid = partition(arr,l , h);
        quicksort(arr, l, mid-1);
        quicksort(arr, mid+1, h);
        }
}

int partition(int arr[],int  l,int h)
{
puts("hdsjdfh");
        int pv = arr[h];
        int pi = h;
        int j = l;
        int i;
        int temp;
        
        for(i=l; i<h; i++)
        {
                if(arr[i] < pv)
                {
 			temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
			j++;
			
                }
        }
        temp = arr[j];
        arr[j] = arr[pi];
	arr[pi] = temp;
        return j;
}




int main(void)
{
	int i,n,arr[MAX];
	puts("\t\t\t::QUICKSORT::\n");
	printf("Enter the number of elements:\n");
	scanf("%d",&n);
	printf("Enter the elements");
	for(i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}
	quicksort(arr, 0, n-1);
	puts("Sprted array is :\n");
	for(i=0; i<n; i++)
	{
		printf("%d\t",arr[i]);
	}
}


