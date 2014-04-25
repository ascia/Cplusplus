#include<stdio.h>
int main(){
		
	int a = 3 ;//0011
	int b = 15;//1111
	int c = a >> 3;//0
        int d = a << 3;//0011000 24
	int e = 0x01<<15;//  32768
	printf("c = %d, d = %d\n",c,d);
	printf("e = %d\n",e);  
	return 0;
}
