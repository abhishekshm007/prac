#include<stdio.h>

int *change(){
	int a =10;
	return &a;
}

int main(void) {
int *b = change();
printf("%d",*b);
return 0;
}gjhgj
