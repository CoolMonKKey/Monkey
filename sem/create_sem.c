
/**********************************************************
*    > File Name: sem.c
*    > Author: Monkey
*    > Mail: 1379573644@qq.com 
*    > Created Time: Thu 02 Nov 2017 10:31:35 AM EDT
**********************************************************/
#include"ipc.h"

int main(int argc,char *argv[])
{
    if(argc != 4)
    {
        printf("<Warning,Usage>:%s pathname proj_id sem_ini_val\n",argv[0]);
        return -1;
    }
    key_t sem_key = Ftok(argv[1],atoi(argv[2]));
    int sem_id = Semget(sem_key,1,IPC_CREAT|IPC_EXCL|0755);

    union semun init;
    init.val = atoi(argv[3]);

    semctl(sem_id,0,SETVAL,init);
    printf("Create Sem OK.\n");
    return 0;
}
