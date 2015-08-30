#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int check(int a[], int n);
int main() {

    int n =0,i=0, a[100000],testCase = 0,flag = 0;
    scanf("%d",&testCase);
    while(testCase){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        flag = check(a,n);
        if(flag){
            printf("YES");
        }
        else {
            printf("NO");
        }
        testCase--;
    }
    return 0;
}

int check(int a[], int n){
    int i = 0 , f= n-1,flag = 0, sum1 =0 ,sum2 = 0;
    sum1 = sum1 + a[i];
    sum2 = sum2 + a[f];
    while(i+2 != f){
        
        if(sum1 == sum2 && (i+2) == f){
            flag = 1;
	    break;
        }
        else if(sum1 < sum2){
            i++;
            sum1 = sum1 + a[i];
        }
        else {
            f--;
            sum2 = sum2 + a[f];
        }
    }
    return flag;
}
