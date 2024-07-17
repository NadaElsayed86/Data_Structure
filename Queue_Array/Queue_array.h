
//
// Created by nada8 on 17/07/2024.
//

#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H
#define MAXSIZE 100
typedef int QueueEntry;

typedef struct queue {
    int rear;
    int front;
    int size;
    QueueEntry entry[MAXSIZE];
}Queue;


void createQueue(Queue *pq) ;

void append(Queue *pq,QueueEntry e) ;

void serve(Queue *pq,QueueEntry *pe) ;

int is_Full(Queue *pq) ;

int is_Empty(Queue *pq);

int Size(Queue *pq) ;

void Traverse(Queue *pq,void(*pf)(QueueEntry)) ;

void clear(Queue *pq) ;

#endif //QUEUE_ARRAY_H
