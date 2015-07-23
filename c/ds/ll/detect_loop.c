#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node {
	int data;
	struct node * next;
};
double time_used;
clock_t begin, end;

int floyd_check(struct node *head);

int main(){
	struct node *head, *prev = (struct node *)malloc(sizeof(struct node));

	struct node *temp = (struct node *)malloc(sizeof(struct node));
	head = temp;
	int i,n=10;
	for(i=0; i<n; i++){
		prev->next = temp;
		temp->data = i+1;
		temp->next = NULL;
		prev= temp;
		temp = (struct node *) malloc(sizeof(struct node));
	}
	
	prev->next = head->next->next->next;

	int x;
	puts("dsf");
	x = floyd_check(head);
	printf("\ndetected loop is %d\n",x);
	return 0;
}

int floyd_check(struct node *head){
	struct node *a = head, *b = head;
	while(b != NULL && b->next != NULL && b->next->next != NULL){
		a = a->next;
		b = b->next->next;
		if(a == b){
			return 1;
		}
	}
	return 0;
}
