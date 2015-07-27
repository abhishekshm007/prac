#include<stdio.h>
int main(){
	printf("type string\n");
	char a[4] ;
	scanf("%4s",a);
	printf("size %d",sizeof(a));
	puts(a);
	puts("now using gets");
	gets(a);
	printf("size %d",sizeof(a));
	printf("%s",a);
	puts("done");
}
