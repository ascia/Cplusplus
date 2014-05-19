#include <stdio.h>
#include <omp.h>
#define OMP 11
void Test(int);
int main(int argc, char* argv[]){
	#pragma omp parallel num_threads(4)
	{
		Test(5);
	}
	fgetc(stdin);
//	return 0;
}
void Test(int n){
      printf("<T:%d> - %d\n", omp_get_thread_num(), n);
}
