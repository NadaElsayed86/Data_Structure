#include <stdio.h>
#include"stack.h"
#include "Queue.h"
int main(void) {

    stack s;
    createStack((&s));

        push(5,&s);
        push(6,&s);
        push(7,&s);
        push(8,&s);


    printf("Size =%d",size(&s));
    return 0;
}
