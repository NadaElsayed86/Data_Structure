//
// Created by nada8 on 18/07/2024.
//
#include "Stack_Linked.h"
#include<stdlib.h>

#include <stdio.h>

void createStack(stack *ps) {
    ps->top=NULL;
    ps->size=0;
}

void push(stackEntry item,stack *ps) {
    stacknode *pn=(stacknode*)malloc(sizeof(stacknode));
    pn->entry=item;
    pn->next=ps->top;
    ps->top=pn;
    ps->size++;
}

void pop(stackEntry *pe,stack *ps) {
    stacknode *pn=ps->top;
    *pe=ps->top->entry;
    ps->top=ps->top->next;
    free(pn);
    ps->size--;
}

int is_Full(stack *ps) {
    return 0;
}

int is_Empty(stack *ps) {
    return !ps->size;
}

void clearStack(stack *ps) {
    stacknode *pn=ps->top;
    stacknode *qn=ps->top;

    while(pn) {
        pn=pn->next;
        free(qn);
       qn=pn;
    }
    ps->size=0;
}

int size(stack *ps) {
    return ps->size;
}

void Traverse(stack *ps,void(*pf)(stackEntry)) {
    stacknode *pn=ps->top;
    while(pn) {
        (*pf)(pn->entry);
        pn=pn->next;
    }
}
