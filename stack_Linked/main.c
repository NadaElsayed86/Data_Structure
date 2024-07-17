#include <stdio.h>
#include "Stack_Linked.h"

void Display(stackEntry e) {
    printf("Element is:%d\n",e);
}
int main(void) {
    stack s;
    createStack(&s);

    if(!is_Full(&s)) {
        push(10,&s);
        push(20,&s);
        push(33,&s);
        push(84,&s);
        push(4,&s);
        push(46,&s);
    }

    int e=46;
    pop(&e,&s);

    Traverse(&s,&Display);
    return 0;
}
