#include<stdio.h>

#define MAX 350

int main(){
	int maze[MAX][MAX], rats[MAX], n, r, i,j;
	i=j=r=n=0;

	scanf("%d",&n);
	for(i=0; i<n ; i++){
		for(j=0; j<n; j++){
			scanf("%c",&ch);
			if(ch == 'X' || ch == 'x')
				maze[i][j] = 1;
			else 
				maze[i][j] = 0;
		}
	}

	scanf("%d", &r);
	for(i=0; i<r; i++){
		scanf("%d %d", &rat[i][0], &rat[i][1]);
	}

}
