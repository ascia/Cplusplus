#ifndef _MSG__H__
#define _MSG__H__
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define BODY_LEN 1024

typedef struct _testmsg
{
    long type;
    char msgbody[1];
} testmsg, *ptestmsg;

#define MSG_TYPE 0xFF
#define MSGS_LEN (sizeof(struct _testmsg) - sizeof(long) )

// 一般使用ftok函數獲取key_t，這裡簡單起見，直接定義一個鍵值。
#define MSG_KEY (key_t)0x320310F2   

int open_queue()
{
    // 獲取queue的ID，如果不存在則創建queue。
    return msgget(MSG_KEY, IPC_CREAT);
}
#endif
