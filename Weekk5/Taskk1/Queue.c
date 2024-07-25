//
// Created by nada8 on 23/07/2024.
//
#include "Queue.h"
#include <stdlib.h>
#if LIMITED_MEMORY==1

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

int is_full(Queue *pq) {
    return (pq->size== MAXSIZE);
}

int is_empty(Queue *pq) {
    return !(pq->size);
}

int Size(Queue *pq) {
    return pq->size;
}

void traverse(Queue *pq,void(*pf)(QueueEntry)) {
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



#else

void create(Queue *pq) {
    pq->front=NULL;
    pq->rear=NULL;
    pq->size=0;
}

void append(Queue *pq,QueueEntry item) {
    QueueNode *pn=(QueueNode*)malloc(sizeof(QueueNode));
    pn->entry=item;
    pn->next=NULL;
    if(!(pq->rear)) {
        pq->rear=pn;
    }
    else {
        pq->rear->next=pn;
    }
    pq->rear=pn;
    pq->size++;
}

void serve(Queue *pq,QueueEntry *pe) {
    QueueNode *pn=pq->front;
    *pe=pn->entry;
    pq->front=pn->next;
    if(!pq->front) {
        pq->rear=NULL;
    }
    free(pn);
    pq->size--;
}

int is_empty(Queue *pq) {
    return !(pq->front);
}

int is_Full(Queue *pq) {
    return 0;
}

void clear(Queue *pq) {
    QueueNode *pn=pq->front;
    while(pn) {
        pq->rear=pn->next;
        free(pn);
        pn=pq->rear;
    }
    pq->size=0;
}

void Traverse(Queue *pq,void(*pf)(QueueEntry)) {

    for(QueueNode *pn=pq->front;pn;pn=pn->next) {
        (*pf)(pn->entry);
    }
}

int size(Queue *pq) {
    return pq->size;
}



#endif
