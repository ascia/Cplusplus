#include <stdio.h>
int main(){
	char dash1[]="12";
	char dash2[]="\n";
      char dash3[]="\t";
	printf("sizeof(\"12\")  = %d\n strlen(\"12\")  = %d \n",sizeof(dash1),strlen(dash1));
	printf("sizeof(\"\\n\") = %d\n strlen(\"\\n\") = %d \n",sizeof(dash2),strlen(dash2));
	printf("sizeof(\"\\t\") = %d\n strlen(\"\\t\") = %d \n",sizeof(dash3),strlen(dash3));
	return 0;
}
/* output:
sizeof("12")  = 3
 strlen("12")  = 2 
sizeof("\n") = 2
 strlen("\n") = 1 
sizeof("\t") = 2
 strlen("\t") = 1
*/ 
