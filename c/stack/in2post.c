#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
#define MAX 500

int isOp(int i){
	return (i == '+' || i== '-' || i == '*' || i == '/');
}

int prec(int i){
	switch(i){
		case '+' :
		case '-' :
			return 1;
		case '*' : 
		case '/' :
			return 2;
		default :
			return -1;
	}
}

int main(){
	Stack *stack = createStack(MAX);
	char exp[MAX];
	int i =0, k = 0;
	printf("Enter the expression to be converted into postfix : \n");
	scanf("%s",exp);

	for(i=0, k=0; exp[i] != '\0'; i++){
		if(exp[i] == ' ')
			continue;

		else if(exp[i] == '('){
				push(stack, exp[i]);
				continue;
			}
		else if(exp[i] == ')'){
			while(getTop(stack) != '('){
				if(isEmpty(stack)){
					printf("\n\n*** Invalid expression ***\n");
					return -1;
				}
				exp[k++] = pop(stack);
			}
		}
		else if(isOp(exp[i])){
			while(!isEmpty(stack) && prec(exp[i]) <= prec(getTop(stack))){
				exp[k++] = pop(stack);
			}
			push(stack, exp[i]);
		}
		else exp[k++] = exp[i];
	}
	while(!isEmpty(stack)){
		exp[k++] = pop(stack);
	}
	exp[k++] = '\0';
	printf("\n postfix is as : %s\n",exp);
	return 0;
}
