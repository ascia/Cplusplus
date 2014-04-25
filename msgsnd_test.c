#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "msg.h"

unsigned char send_msg[MSGS_LEN] = {0};
unsigned char* some_array[1024] = {0};

int main(int argc, char** argv)
{
    int msqid = open_queue();
    if (msqid == -1)
    {
        printf("error when opened the queue!\n");
        return -1;
    }

    int i = 0;
    while (1)
    {
        ptestmsg p = (ptestmsg)send_msg;
        p->type = MSG_TYPE;
        memset(p->msgbody, 0, BODY_LEN);
        int ret = msgsnd(msqid, send_msg, MSGS_LEN, 0);

        if (-1 == ret)
        {
            printf("error when sent the msg\n");
            return -1;
        }
        printf("sent %d msges.\n", ++i);
        usleep(500000);
    }

    return 0;
}
