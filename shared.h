#ifndef SHARED_H
#define SHARED_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>	// Fork
#include <sys/shm.h>	// Shmget
#include <unistd.h>	// Windows stuff
#include <sys/wait.h>	// waitpid
#include <stdbool.h>	// Bool
#include <sys/msg.h>	// Shared Messaging
#include <sys/sem.h>	// Semaphores
#include <string.h>	// Bitmap
#include <sys/time.h>	// Timer
#include <time.h>
#include <signal.h>	// Signal handleing
#include <stdint.h>	// uint32_t

#define MAX_PROC 18

// Time
struct Clock{
	unsigned int sec;
	unsigned int nsec;
};

// Proccess Block
struct ProcBlock{	
	int simPID;
	pid_t pid;
	int startTimeSec;
	int startTimeNSec;
	bool inProg;
	int prio;
};

struct Msg{
	long mtype;
	char msgtxt[200];
};

struct QNode{
	int index;
	struct QNode *next;
};

struct Queue{
	struct QNode *front;
	struct QNode *rear;
};

struct Queue *createQueue(){
	struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
	q->front = NULL;
	q->rear = NULL;
	return q;
};

#endif
