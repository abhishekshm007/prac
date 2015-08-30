#include<stdio.h>
#include<string.h>
int main(){
	int cnt,i;
	char exp[100];
	printf("Enter the expression ");
	scanf("%[^\n]%*c", exp);
	cnt=strlen(exp);
	for(i=0;i<cnt;i++)
	{
	printf("%c \n",exp[i]);
	}
	return 0;
}
