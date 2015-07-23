#include<stdio.h>

int main(void){
	float f = 10.9;
	float *c  = &f;
	printf("&c %u  *c %f   \n",c,*c);
	return 0;
}
