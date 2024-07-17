//
// Created by nada8 on 18/07/2024.
//
#include <stdlib.h>
#include "Stack_Array.h"

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