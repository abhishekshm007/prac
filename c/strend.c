#include<stdio.h>
#include<string.h>

int strend(char *, char *);

int main(int argc, char *argv){
	char a[] = "iwyriwrjhshfjka", b[] = "jhshfjka";
	printf("\n%d\n",strend(a,b));
	return 0;
}

int strend(char *a, char *b){
	while(*a++)
	;
	while(*b++)
	;
	int len =  strlen(b);
	while(len > 0 && (*a-- == *b--)){
		len--;
	}
	if(len == 0)
	return 1;
	else
	return 0;
}
