//
// Created by nada8 on 23/07/2024.
//
#include "stack.h"
#include <stdlib.h>

#if LIMITED_MEMORY == 1

void createStack(stack *ps) {
    ps->top=0;
}

void push(stackEntry item,stack *ps) {
    ps->entry[ps->top]=item;
    ps->top++;
}

void pop(stackEntry *pe,stack *ps) {
    *pe=ps->entry[ps->top--];
}

void stackTop(stackEntry *pe, stack *ps) {
    *pe=ps->entry[ps->top-1];
}

int is_Full(stack *ps) {
    return (ps->top==MAXSIZE);
}

int is_Empty(stack *ps) {
    return !ps->top;
}

void Traverse(stack *ps,void(*pf)(stackEntry)) {
    for(int i=ps->top;i>0;i--) {
        (*pf)(ps->entry[i-1]);
    }
}

int size(stack *ps) {
    return ps->top;
}

void clearStack(stack *ps) {
    ps->top=0;
}


#else

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




#endif