#include<stdio.h>
int main(){
	int a = 5;
	int *b = &a;
	*b =3 ;
	printf("a = %d, b = %d\n",a,*b);
	return 0;
}
/*
output
a = 3, b = 3
*/
