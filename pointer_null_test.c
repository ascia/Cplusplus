#include<stdio.h>
void function(int **lf){
//	printf("function **ptr = %d",**ptr);
	printf("function *lf = %p\n",*lf);
	printf("function lf = %p\n",lf);
}
int main(){
	int *ptr = NULL;
	if(!ptr){
		printf("ptr NULL\n");
	} else {
		printf("ptr not NULL\n");
	}
	printf("ptr = %p\n",ptr);
	printf("&ptr = %p\n",&ptr);
	function(&ptr);
	return 0;
}
/*
output:

ptr NULL
ptr = (nil)
&ptr = 0xbffa00ec
function *lf = (nil)
function lf = 0xbffa00ec
*/
