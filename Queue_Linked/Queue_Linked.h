//
// Created by nada8 on 17/07/2024.
//

typedef int QueueEntry;

typedef struct queuenode {
    QueueEntry entry;
    struct queuenode *next;
}QueueNode;

typedef struct queue {
    QueueNode *front;
    QueueNode *rear;
    int size;
}Queue;


void create(Queue *pq) ;

void append(Queue *pq,QueueEntry item) ;

void serve(Queue *pq,QueueEntry *pe) ;

int is_empty(Queue *pq) ;

int is_Full(Queue *pq) ;
void clear(Queue *pq) ;

void Traverse(Queue *pq,void(*pf)(QueueEntry)) ;

int size(Queue *pq) ;
#ifndef QUEUE_LINKED_H
#define QUEUE_LINKED_H

#endif //QUEUE_LINKED_H
