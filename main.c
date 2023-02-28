#include <stdio.h>
#include <stdlib.h>


typedef struct node node;
typedef struct priorityQueue priorityQueue;
struct node
{
    int value;
    int priority;
    node* next;
};

struct priorityQueue
{
    node* front;
};

priorityQueue* create();
int delete(priorityQueue* pq);
int isEmpty(priorityQueue* pq);
int isFull(priorityQueue* pq);
int insert(priorityQueue* pq, int newValue, int newPriority);
int pop(priorityQueue* pq, int* poppedValue);
int peek(priorityQueue* pq, int* topValue, int* topPriority);

void printQ(priorityQueue* pq);

int main()
{
    priorityQueue* pqList[10] = {NULL};

    pqList[0] = create();
    int value, topValue, topPr;

    insert(pqList[0], 4, 3);
    insert(pqList[0], 5, 4);
    insert(pqList[0], 3, 2);
    printQ(pqList[0]);
    
    pop(pqList[0], &value);

    printQ(pqList[0]);

    peek(pqList[0], &topValue, &topPr);
    printf("top v = %d, top pr = %d\n",topValue, topPr);

    delete(pqList[0]);
    printQ(pqList[0]);

    return 0;
}

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