/*
** Program FTIME.C
**
** Illustrates the use of ftime function to perform a task for a period
** of time.  Prints dots for 5000 msecs.
**
** H. Paul Roach, MSU, 5 August, '96
*/

#include <stdio.h>                                            /* 1 */
//#include <dos.h>                                            /* 2 */
#include <sys/timeb.h>                                        /* 3 */
                                                              /* 4 */
void main(void)                                               /* 5 */
{                                                             /* 6 */
   struct timeb t_start, t_current;                           /* 7 */
   int t_diff;                                                /* 8 */
   ftime(&t_start);                                           /* 9 */
   do                                                         /* 10 */
   {                                                          /* 11 */
      printf(".");                                            /* 12 */
      ftime(&t_current);                                      /* 13 */
      t_diff = (int) (1000.0 * (t_current.time - t_start.time)/* 14 */
        + (t_current.millitm - t_start.millitm));             /* 15 */
                                                    /* 16 */
      printf("t_diff = %d\n",t_diff);	                      /* 17 */
   } while(t_diff < 5000);                                    /* 18 */
}  
