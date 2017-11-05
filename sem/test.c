
/**********************************************************
*    > File Name: test.c
*    > Author: Monkey
*    > Mail: 1379573644@qq.com 
*    > Created Time: Thu 02 Nov 2017 08:31:03 AM EDT
**********************************************************/
#include "ipc.h"


int main()
{
    key_t key = Ftok("myset",0xff);
    printf("sem key = %d\n",key);
    int sem_id = (semget(key,1,IPC_CREAT|IPC_EXCL|0755));
    if(sem_id == -1)
    {
        perror("semget");
        exit(1);
    }
    else
        printf("sem_id = %d\n",sem_id);
    union semun init;
    init.val = 2;
    semctl(sem_id,0,SETVAL,init);

    int sem_val = semctl(sem_id,0,GETVAL);
    printf("sem_value = %d\n",sem_val);

    int ret = semctl(sem_id,0,IPC_RMID);
    if(ret == -1)
        printf("Remove sem Fail.\n");
    else
        printf("Remove sem Succeed.\n");
    return 0;
}
