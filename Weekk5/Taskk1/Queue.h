//
// Created by nada8 on 23/07/2024.
//

#ifndef QUEUE_H
#define QUEUE_H

#include "global.h"

void createQueue(Queue *pq) ;

void append(Queue *pq,QueueEntry e) ;

void serve(Queue *pq,QueueEntry *pe) ;

int is_full(Queue *pq) ;

int is_empty(Queue *pq);

int Size(Queue *pq) ;

void traverse(Queue *pq,void(*pf)(QueueEntry)) ;

void clear(Queue *pq) ;

#endif //QUEUE_H
