//
// Created by nada8 on 23/07/2024.
//

#ifndef GLOBAL_H
#define GLOBAL_H

#define LIMITED_MEMORY ARRAY
#define ARRAY 1
#define LINKED 2
typedef int stackEntry;
typedef int QueueEntry;

#if LIMITED_MEMORY == 1
#define MAXSIZE 100
typedef int stackEntry;
typedef struct Stack {
    int top;
    stackEntry entry[MAXSIZE];
}stack;

#define MAXSIZE 100


typedef struct queue {
    int rear;
    int front;
    int size;
    QueueEntry entry[MAXSIZE];
}Queue;


#else
typedef  struct stackNode {
    stackEntry entry;
    struct stackNode *next;
}stacknode;

typedef struct Stack{
    stacknode *top;
    int size;
}stack;



typedef struct queuenode {
    QueueEntry entry;
    struct queuenode *next;
}QueueNode;

typedef struct queue {
    QueueNode *front;
    QueueNode *rear;
    int size;
}Queue;

#endif

#endif //GLOBAL_H
