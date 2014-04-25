#include<stdio.h>
#include<string.h>
int main(){
	char str[]="abcde";
	int strlen_result = strlen(str),
	    sizeof_result = sizeof(str);
	printf("strlen_result = %d\n",strlen_result);
	printf("sizeof_result = %d\n",sizeof_result);
	return 0;
}
/* output
 strlen_result = 5
 sizeof_result = 6
*/
