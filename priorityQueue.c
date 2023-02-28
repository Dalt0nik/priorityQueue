#include <stdio.h>
#include <stdlib.h>
#include "priorityQueue.h"

priorityQueue* createQ()
{
    priorityQueue* newPQ;
    newPQ = malloc(sizeof(priorityQueue));
    newPQ->front = NULL;
    return newPQ;
}

int isEmpty(priorityQueue* pq)
{
    if(pq->front == NULL)
        return 1;
    else
        return 0;
}

int isFull(priorityQueue* pq)
{
    priorityQueue* temp = NULL;
    temp = malloc(sizeof(priorityQueue));
    
    if(temp != NULL)
    {
        free(temp);
        return 0;
    }  
    else
        return 1;  
}

int insert(priorityQueue* pq, int newValue, int newPriority)
{
    if(isFull(pq) == 1)
        return 0;


    if(pq->front == NULL || pq->front->priority > newPriority)
    {
        node* temp = pq->front;
        pq->front = (node*)malloc(sizeof(node));
        pq->front->next = temp;
        pq->front->priority = newPriority;
        pq->front->value = newValue;
        return 1;
    }

    node* current;
    current = pq->front;

    while(current->next != NULL && current->next->priority <= newPriority)
    {
        current = current->next;
    }

    node *newNode = malloc(sizeof(node));
    newNode->next = current->next;
    newNode->priority = newPriority;
    newNode->value = newValue;

    current->next = newNode;
    return 1;
}

int pop(priorityQueue* pq, int* poppedValue)
{
    if(isEmpty(pq) == 1)
        return 0;

    node* temp;
    *poppedValue = pq->front->value;
    temp = pq->front;
    pq->front = pq->front->next;
    free(temp);
    return 1;
}

int peek(priorityQueue* pq, int* topValue, int* topPriority)
{
    if(isEmpty(pq) == 1)
        return 0;
    
    *topValue = pq->front->value;
    *topPriority = pq->front->priority;
}

int deleteQ(priorityQueue* pq)
{
    if(isEmpty(pq) == 1)
        return 0;

    node* current, *prev;
    
    current = pq->front;

    while(current != NULL)
    {
        prev = current;
        current = current->next;
        free(prev);
    }
    pq->front = NULL;

    return 1;
}
