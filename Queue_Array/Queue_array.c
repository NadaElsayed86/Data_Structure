//
// Created by nada8 on 18/07/2024.
//
#include "Queue_array.h"

void createQueue(Queue *pq) {
    pq->front=0;
    pq->rear=-1;
    pq->size=0;
}

void append(Queue *pq,QueueEntry e) {
    pq->rear=(pq->rear+1)%MAXSIZE;
    pq->entry[pq->rear]=e;
    pq->size++;
}

void serve(Queue *pq,QueueEntry *pe) {
    *pe=pq->entry[pq->front];
    pq->front=(pq->front+1)%MAXSIZE;
    pq->size--;
}

int is_Full(Queue *pq) {
    return (pq->size== MAXSIZE);
}

int is_Empty(Queue *pq) {
    return !(pq->size);
}

int Size(Queue *pq) {
    return pq->size;
}

void Traverse(Queue *pq,void(*pf)(QueueEntry)) {
    int pos,s;
    for(pos=pq->front,s=0;s<pq->size;s++) {
        (*pf)(pq->entry[pos]);
        pos=(pos+1)%MAXSIZE;
    }
}

void clear(Queue *pq) {
    pq->front=0;
    pq->rear=-1;
    pq->size=0;
}
