/*
 * example.c
 *
 *  Created on: 28-Jun-2015
 *      Author: abhishek
 */
#include<stdio.h>

int main(int argc, char **argv) {

	int i = 3;
	float f = 3.50, *prod;
	float *multiply(int , float);
	 prod = multiply(i,f);
	 printf("\nprod = %u value at address  = %f",prod,*prod);
	 return 0;
}


float *multiply(int ii,float ff){
	float product;

	product = ii*ff;
	printf("\nproduct = %f address of product = %u",product,&product);
	return (&product);
}

