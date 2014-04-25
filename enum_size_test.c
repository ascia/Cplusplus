#include <stdio.h>
int main(){
	enum{ MAX = 9999999999};
	printf("sizeof(MAX) = %d\n",sizeof(MAX));
	printf("MAX = %ll",MAX);
	return 0;
}
/* OUTPUT:
sizeof(MAX) = 4 if MAX = 100
sizeof(MAX) = 8 if Max = 9999999999
*/
