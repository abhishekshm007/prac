#include<stdio.h>

int len = 0;
int getleft(int i){
	return i*2;
}
int getright(int i){
	return (i*2)+1;
}
int size(int a[]){
	return len;
}
void heapify(int a[], int index){
	int left, right, largest;
	left = getleft(index);
	right = getright(index);
	if(left < size(a) && a[left] > a[index]){
		largest = left;
	}else{
		largest = index;
	}
	if(right < size(a) && a[right] > a[largest]){
		largest = right;
	}
	if(largest != index){
		int temp;
		temp = a[largest];
		a[largest] = a[index];
		a[index] = temp;
		heapify(a,largest);
	}
	return;
}

int main(){
	int a[] = {1,5,2,4,8,3,6,7,9};
	len = 9;
	int i = 0;
	for(i=0; i< len; i++){
		printf("%d\t",a[i]);
	}
	heapify(a,0);
	printf("\n\n");
	for(i=0; i< len; i++){
			printf("%d\t",a[i]);
	}
	return 0;
}
