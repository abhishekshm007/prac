#include<stdio.h>
#include<stdlib.h>
#include"stack.h"



Stack *createStack(unsigned capacity){
	Stack *s = (Stack *)malloc(sizeof(Stack));
	s->top = -1;
	s->capacity = capacity;
	s->array = (int *)malloc(s->capacity * sizeof(int));
	return s;
}

int isEmpty(Stack *s){
	return (s->top == -1) ? 1 : 0;
}

int isFull(Stack *s){
	return (s->top == s->capacity - 1) ? 1 : 0;
}

void push(Stack *s, int data){
	if(isFull(s)){
		printf("\n**OVERFLOW OCCURED : Stack is already full**\n");
		return;
	}
	(s->array)[++(s->top)] =  data;
	return;
}

int pop(Stack *s){
	if(isEmpty(s)){
		printf("\n**UNDERFLOW OCCURED : Stack is empty**\n");
		return -1;
	}
	return (s->array)[(s->top)--];
}

int getTop(Stack *s){
	return (isEmpty(s)) ? -1 : s->array[s->top];
}
