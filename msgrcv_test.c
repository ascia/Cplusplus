#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include "msg.h"

void do_statistic(void);
unsigned char rcvbuf[MSGS_LEN] = {0};

int main(int argc, char** argv)
{
    int msqid = open_queue();
    if (msqid == -1)
    {
        printf("error when opened the queue!\n");
        return -1;
    }

    while (1)
    {
        int ret = msgrcv(msqid, rcvbuf, MSGS_LEN, MSG_TYPE, IPC_NOWAIT);
        do_statistic();
        if (ENOMSG == errno || EAGAIN == errno)
        {
            usleep(12000);
            continue;
        }

        if (ret == -1)
        {
//            printf("msgrcv failed!\n");
        } else{
	    //do_ststistic();
	    printf("msgrcv success!!!\n");
	}
        usleep(12030*10);
    }

    return 0;
}

void do_statistic(void)
{
    static int msgcount = 0;
    msgcount++;
   // printf("do recived msg %d times.\n", msgcount);
}
