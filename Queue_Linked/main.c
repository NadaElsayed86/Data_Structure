#include <stdio.h>
#include <stdlib.h>

#include "Queue_Linked.h"

void Display(QueueEntry e) {
    printf("Element is:%d",e);
}

int main(void) {

    Queue q;
    create(&q);

    append(&q,5);
    append(&q,6);
    append(&q,7);

    printf("Size=%d\n",size(&q));
   
    return 0;
}
