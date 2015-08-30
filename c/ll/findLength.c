#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int findLen(struct node *head);

int main(void){
	clock_t begin, end;
	struct node {
		int data;
		struct node * next;
	} *head, *temp;
	int i, n= 10;
	for(i=0; i<n; i++){
		nn
	}
}

int findLen(struct node *head){
	int count =0;
	while(head != NULL){
	count++;
	head = head->next;
	}
	return count;
}
