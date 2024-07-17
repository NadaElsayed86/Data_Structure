//
// Created by nada8 on 18/07/2024.
//

#ifndef STACK_LINKED_H
#define STACK_LINKED_H

typedef int stackEntry;
typedef  struct stackNode {
    stackEntry entry;
    struct stackNode *next;
}stacknode;

typedef struct Stack{
    stacknode *top;
    int size;
}stack;


void createStack(stack *ps) ;
void push(stackEntry item,stack *ps) ;
void pop(stackEntry *pe,stack *ps) ;
int is_Full(stack *ps) ;
int is_Empty(stack *ps) ;
void clearStack(stack *ps) ;
int size(stack *ps) ;
void Traverse(stack *ps,void(*pf)(stackEntry)) ;

#endif //STACK_LINKED_H
