//
// Created by nada8 on 18/07/2024.
//

#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H
#define MAXSIZE 100

typedef char stackEntry;

typedef struct Stack {
    int top;
    stackEntry entry[MAXSIZE];
}stack;



void createStack(stack *) ;
void push(stackEntry item,stack *) ;
void pop(stackEntry *pe,stack *) ;
void stackTop(stackEntry *, stack *) ;
int is_Full(stack *) ;
int is_Empty(stack *) ;
void Traverse(stack *,void(*pf)(stackEntry)) ;
int size(stack *) ;
void clearStack(stack *) ;
#endif //STACK_ARRAY_H
