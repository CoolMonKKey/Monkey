#ifndef _IPC_H
#define _IPC_H
/**********************************************************
*    > File Name: ipc.h
*    > Author: Monkey
*    > Mail: 1379573644@qq.com 
*    > Created Time: Thu 02 Nov 2017 08:36:50 AM EDT
**********************************************************/
#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/sem.h>

union semun
{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
    struct seminfo *__buf;
};

key_t Ftok(const char *pathname,int proj_id)
{
    key_t key = ftok(pathname,proj_id);
    if(key == -1)
    {
        perror("ftok");
        exit(1);
    }
    return key;
}

//2 semget
int Semget(key_t key,int nsems,int semflg)
{
    int id = semget(key,nsems,semflg);
    if(id == -1)
    {
        perror("semget");
        exit(1);
    }

    return id;


}

//3 Shmget
int Shmget(key_t key,size_t size,int shmflg)
{
    int id = shmget(key,size,shmflg);
    if(id == -1)
    {
        perror("shmget");
        exit(1);
    }
    return id;
}



#endif // _IPC_H
