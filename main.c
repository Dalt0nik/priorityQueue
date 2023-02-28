#include <stdio.h>
#include <stdlib.h>
#include "priorityQueue.h"


void printQ(priorityQueue* pq);

int main()
{
    priorityQueue* pqList[10] = {NULL};

    pqList[0] = createQ();
    int value, topValue, topPr;

    insert(pqList[0], 4, 3);
    insert(pqList[0], 5, 4);
    insert(pqList[0], 3, 2);
    printQ(pqList[0]);
    
    pop(pqList[0], &value);

    printQ(pqList[0]);

    peek(pqList[0], &topValue, &topPr);
    printf("top v = %d, top pr = %d\n",topValue, topPr);

    deleteQ(pqList[0]);
    printQ(pqList[0]);

    return 0;
}

void printQ(priorityQueue *pq)
{
    node* nextNode = pq->front;
    printf("front ->");
    while(nextNode != NULL)
    {
        printf(" %d(%d) ",nextNode->value, nextNode->priority);
        nextNode = nextNode->next;
    }
    printf("\n");
}