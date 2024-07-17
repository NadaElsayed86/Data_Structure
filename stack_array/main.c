#include <stdio.h>
#include "stack_Array.h"


void Display(stackEntry e) {
    printf("Element is:%d\n",e);
}
int main() {

    stack s;
    createStack(&s);

    if(!is_Full(&s)) {
        push(5,&s);
        push(6,&s);
        push(7,&s);
        push(4,&s);
        push(8,&s);
    }

    int e=7;
    if(!is_Empty(&s)) {
        pop(&e,&s);
    }
    Traverse(&s,&Display);

    int sz=size(&s);

    printf("Size of Stack is :%d",sz);

    return 0;
}
