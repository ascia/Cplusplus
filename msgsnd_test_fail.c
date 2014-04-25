#include <stdio.h>
#include <stdlib.h>
#include <linux/ipc.h>
#include <linux/msg.h>
/*
int send_message(int qid,struct mymsgbuf *qbuf){
	
	int result, length;
	
	length =sizeof(struct mymsgbuf)-sizeof(long);
	
	if((result = msgsnd( qid, qbuf, length, 0)) == -1 ){
		return (-1);
	}
	
	return (result);
}*/
struct mymsgbuf{
	long mtype;
	int request;
	double salary;
};
int open_queue(int msgkey){
	return msgget( msgkey, IPC_CREAT);
}
int main(){
	int qid;
	key_t msgkey;
/*
	struct mymsgbuf{
		long mtype;
		int request;
		double salary;
	}msg;
*/
	struct mymsgbuf msg;
	msgkey = ftok(".",'m');

	if(( qid = open_queue(msgkey)) == -1){
		perror("open_queue");
		exit(-1);
	}
	msg.mtype = 1;
	msg.request = 1;
	msg.salary = 1000.00;
	if((send_message( qid,&msg)) == -1){
		perror("send_message");
		exit(-1);
	}
}
int send_message( int qid, struct mymsgbuf *qbuf){
	int result, length;
	length = sizeof(struct mymsgbuf)-sizeof(long);
	if( ( result = msgsnd( qid, qbuf, length, 0)) == -1){
		return -1;
	}  
	return result;
}
