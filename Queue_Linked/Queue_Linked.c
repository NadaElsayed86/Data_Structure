//
// Created by nada8 on 18/07/2024.
//
#include "Queue_Linked.h"
#include<stdlib.h>

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