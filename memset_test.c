/*
This program use to understand the memset
void * memset ( void * ptr, int value, size_t num );
*/
#include <stdio.h>
#include <string.h>
int main(){

	char str[] ="abcdefghijklmnopqrstuvwxyz";
	memset(str,'_',6);
	puts(str);
	return 0;
}
// output : ______ghijklmnopqrstuvwxyz
