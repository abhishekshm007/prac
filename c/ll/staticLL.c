#include<stdio.h>
#include<stdlib.h>

int main( void ){
	
	struct node {
		int data;
		int next;
	} ll[5];
	int i =5;
	while(i){
	
		ll[5-i].data = i+5;
		ll[5-i].next = 6-i;
		i--;
	}
	ll[4].next = -2; // -2 denotes end of linked list

	i=0;

	struct node *temp = ll;
	printf("Your array is here: \n");
	while(temp->next != -2){
		printf("%d\t",temp->data);
		temp = &(ll[temp->next]);
	}
	printf("%d\n",temp->data);
	return 0;
}
