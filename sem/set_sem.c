
/**********************************************************
*    > File Name: set_sem.c
*    > Author: Monkey
*    > Mail: 1379573644@qq.com 
*    > Created Time: Fri 03 Nov 2017 07:37:13 AM EDT
**********************************************************/
#include"ipc.h"

// ./set_sem mysem 0xff 5

int main(int argc,char *argv[])
{
    if(argc != 4)
    {
        printf("<Waring Usage>: %s pathname proj_id sem_val\n",argv[0]);
        return -1;
    }
    key_t sem_key = Ftok(argv[1],atoi(argv[2]));
    int sem_id = Semget(sem_key,0,0);

    union semun sem_val;
    sem_val.val = atoi(argv[3]);
    int ret = semctl(sem_id,0,SETVAL,sem_val);
    if(ret == -1)
        printf("Set Sem Fail.\n");
    else
        printf("Set Sem Succeed.\n");
    return 0;
}

