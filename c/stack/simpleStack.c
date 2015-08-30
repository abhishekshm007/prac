#include<stdio.h>
#include<stdlib.h>
#include"stack.h"


int main(){
	Stack *s = createStack(30);
	push(s,3);
	push(s,4);
	push(s,7);	
	push(s,892);
	push(s,345);	
	push(s,102);
	printf("poped element is %d\n",pop(s));
	printf("poped element is %d\n",pop(s));
	printf("poped element is %d\n",pop(s));
	printf("poped element is %d\n",pop(s));
	printf("poped element is %d\n",pop(s));
	printf("poped element is %d\n",pop(s));
	printf("poped element is %d\n",pop(s));



	return;
}
