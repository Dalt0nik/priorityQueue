#include <stdio.h>
#include <stdlib.h>
#include "priorityQueue.h"


void printQ(priorityQueue* pq);
void printIndex(priorityQueue* pqList[]);
int chooseQ(priorityQueue* pqList[], int pqListSize);

int main()
{
    int loop = 1, command, pqChoice, pqListSize = 0;
    priorityQueue* pqList[100] = {NULL};
    printf("Priority Queue\n\n");

    while(loop == 1)
    {
        printf("\n[1] - Create\n[2] - isEmpty\n[3] - isFull\n[4] - Insert\n[5] - Pop\n[6] - Peek\n[7] - Delete\n[8] - Exit\n\n");

        printf("Iveskite komanda ir paspauskite Enter: ");
        scanf("%d", &command);
        int i = 0;
        switch (command)
        {
        case 1:
            i = 0;

            while(pqList[i] != NULL)
                i++;

            pqList[i] = createQ();
            pqListSize++;

            printf("Prideta nauja prioritetine eile su indeksu #%d\n", i);
            break;
        case 2:
            pqChoice = chooseQ(pqList, pqListSize);
            if(pqChoice == -1)
                break;

            if(isEmpty(pqList[pqChoice]) == 1)
                printf("Eile yra tuscia\n");
            else
                printf("Eile nera tuscia\n");

            break;
        case 3:
            pqChoice = chooseQ(pqList, pqListSize);
            if(pqChoice == -1)
                break;

            if(isFull(pqList[pqChoice]) == 1)
                printf("Eile yra pilna\n");
            else
                printf("Eile nera pilna\n");

            break;
        case 4:
            
            break;
        case 5:
            
            break;
        case 6:
            
            break;
        case 7:
            
            break;
        case 8:
            
            break;
        
        default:
            break;
        }
    }

    

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

void printIndex(priorityQueue* pqList[])
{
    for(int i = 0; i < 100; i++)
    {
        if(pqList[i] != NULL)
            printf("%d ",i);
    }
}

int chooseQ(priorityQueue* pqList[], int pqListSize)
{
    int pqChoice;
    if(pqListSize == 0)
    {
        printf("Nesukurta jokiu prioritetiniu eiliu\n");
        return -1;
    }
    printf("Galimos eiles: ");
    printIndex(pqList);
    printf("\nIveskite norimos eiles indeksa ir paspauskite Enter:\n");
    scanf("%d", &pqChoice);

    return pqChoice;
}