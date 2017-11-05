
/**********************************************************
*    > File Name: get_sem.c
*    > Author: Monkey
*    > Mail: 1379573644@qq.com 
*    > Created Time: Fri 03 Nov 2017 07:37:13 AM EDT
**********************************************************/
#include"ipc.h"

// ./set_sem mysem 0xff 5

int main(int argc,char *argv[])
{
    if(argc != 3)
    {
        printf("<Waring Usage>: %s pathname proj_id sem_val\n",argv[0]);
        return -1;
    }
    key_t sem_key = Ftok(argv[1],atoi(argv[2]));
    int sem_id = Semget(sem_key,0,0);

    int sem_val = semctl(sem_id,0,GETVAL);
    if(ret == -1)
        printf("Get Sem Fail.\n");
    else
        printf("Set Sem = %d\n",sem_val);
    return 0;
}

