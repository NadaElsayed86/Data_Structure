#include <stdio.h>
#include "Queue_array.h"

void Display(QueueEntry e) {
    printf("Element is:%d\n",e);
}

int main(void) {

    Queue q;
    createQueue(&q);

    if(!is_Full(&q)) {
        append(&q,5);
        append(&q,6);
        append(&q,7);
        append(&q,8);
    }

    int e;
    serve(&q,&e);
    Traverse(&q,&Display);
    return 0;
}
