//
// Created by nada8 on 23/07/2024.
//

#ifndef STACK_H
#define STACK_H

#include "global.h"


void createStack(stack *) ;
void push(stackEntry item,stack *) ;
void pop(stackEntry *pe,stack *) ;
void stackTop(stackEntry *, stack *) ;
int is_Full(stack *) ;
int is_Empty(stack *) ;
void Traverse(stack *,void(*pf)(stackEntry)) ;
int size(stack *) ;
void clearStack(stack *) ;

#endif //STACK_H
