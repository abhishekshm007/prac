#include<stdio.h>

int main(){
	int *ap, a = 4;
	float *bp, b = 5.0;
	long *cp, c = 12;
	
	ap = &a;
	bp = &b;
	cp = &c;

	printf("a = %d, b= %f, c = %d\n",*ap, *bp, *cp);

	 ap = &b;
         bp = &a;
         cp = &a;
         printf("a = %d, b= %f, c = %d\n",*ap, *bp, *cp);

}
