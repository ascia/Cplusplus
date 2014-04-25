/*mutex.c*/
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <errno.h>
/*全局變量*/
int gnum = 0;
/*互斥量 */
pthread_mutex_t mutex;
/*聲明線程運行服務程序*/
static void pthread_func_1 (void);
static void pthread_func_2 (void);

int main (void)
{
 /*線程的標識符*/
  pthread_t pt_1 = 0;
  pthread_t pt_2 = 0;
  int ret = 0;
  /*互斥初始化*/
  pthread_mutex_init (&mutex, NULL);
  /*分別創建線程1、2*/
  ret = pthread_create( &pt_1,                  //線程標識符指針
                                     NULL,                  //默認屬性
                                     (void *)pthread_func_1,//運行函數
                                     NULL);                  //無參數
  if (ret != 0)
  {
     printf ("pthread_1_create\n");
  }

  ret = pthread_create( &pt_2,                  //線程標識符指針
                                     NULL,                   //默認屬性
                                     (void *)pthread_func_2, //運行函數
                                     NULL);                  //無參數
  if (ret != 0)
  {
     printf ("pthread_2_create\n");
  }
  /*等待線程1、2的結束*/
  pthread_join (pt_1, NULL);
  pthread_join (pt_2, NULL);

  printf ("main programme exit!\n");
  return 0;
}
/*線程1的服務程序*/
static void pthread_func_1 (void)
{
  int i = 0;

  for( i=0; i<3; i++ ){
    printf ("This is pthread_1!\n");
    pthread_mutex_lock(&mutex); /*獲取互斥鎖*/
        /*注意，這裡以防線程的搶佔，以造成一個線程在另一個線程sleep時多次訪問互斥資源，所以sleep要在得到互斥鎖後調用*/
    sleep (1);
    /*臨界資源*/
    gnum++;
    printf ("Thread_1 add one to num:%d\n",gnum);
    pthread_mutex_unlock(&mutex); /*釋放互斥鎖*/
  }

  pthread_exit ( NULL );
}
/*線程2的服務程序*/
static void pthread_func_2 (void)
{
  int i = 0;

  for( i=0; i<5; i++ )  {
    printf ("This is pthread_2!\n");
    pthread_mutex_lock(&mutex); /*獲取互斥鎖*/
        /*注意，這裡以防線程的搶佔，以造成一個線程在另一個線程sleep時多次訪問互斥資源，所以sleep要在得到互斥鎖後調用*/
    sleep (1);
    /*臨界資源*/
    gnum++;
    printf ("Thread_2 add one to num:%d\n",gnum);
    pthread_mutex_unlock(&mutex); /*釋放互斥鎖*/

  }

  pthread_exit ( NULL );
} 
