
/**********************************************************
*    > File Name: p_sem.c
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
    
    struct sembuf op;
    op.sem_num = 0;
    op.sem_op = -1;
    op.sem_flg = 0;
    int ret = semop(sem_id,&op,1);
    if(ret == -1)
        printf("Operate Sem Fail.\n");
    else
        printf("Operate Sem Succeed.\n");
    return 0;
}

