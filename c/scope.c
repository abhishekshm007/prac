#include<stdio.h>
int *fun(void);

int main(void){
	int* p;
	p=fun();
	printf("add is %u\n",p);
	printf("value is %d\n",*p);
}

int *fun(){
 static	int i = 10;
	return &i;
}
