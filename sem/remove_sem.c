
/**********************************************************
*    > File Name: remove_sem.c
*    > Author: Monkey
*    > Mail: 1379573644@qq.com 
*    > Created Time: Thu 02 Nov 2017 10:44:08 AM EDT
**********************************************************/
#include"ipc.h"

// ./remove_sem pathname proj_id
int main(int argc,char *argv[])
{
    if(argc != 3)
    {
        printf("<Warning Usage>: %s pathname proj_id \n",argv[0]);
        return -1;
    }
    key_t sem_key = Ftok(argv[1],atoi(argv[2]));

    int sem_id = Semget(sem_key,0,0);

    
    int ret = semctl(sem_id,0,IPC_RMID);
    if(ret == -1)
        printf("Remove Sem Fail.\n");
    else
        printf("Remove Sem Succeed.\n");
    
    return 0;
}
