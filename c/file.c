/*
 * file.c
 *
 *  Created on: 08-Aug-2015
 *      Author: abhishek
 */


#include<stdio.h>

void p(char a[], char b[]){
	int i=0,f=1;
	char ch = a[0];
	while(ch != 'F')
		printf("%d",ch);
	if(f){
		ch = b[i];
		f=0;
	}
	else {
		i++;
		ch = a[i];
		f=1;
	}
	printf("%c",'|');
	if(b[i] == 'F')
		i++;

	while(ch != 'F')
		printf("%d",ch);
	if(f){
		i++;
		ch = b[i];
	}
	else {
		i++;
		ch = a[i];
	}
}

int main()
{
	FILE *ptr;
	ptr=fopen("file1.txt","r");
	char c,a[30],b[30];
	while((c=(char)fgetc(ptr))!=EOF)
	{puts("a");
		int i=0;
		while((c=fgetc(ptr))!='F')
		{
			puts("ab");
			a[i] = c;
			i++;
		}
		i=0;
		while((c=fgetc(ptr))!='\n')
		{puts("ac");
			b[i]=c;
			i++;
		}

		//p(a,b);
	}

	return 0;
}
