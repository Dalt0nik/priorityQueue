#pragma once

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

priorityQueue* createQ();
int deleteQ(priorityQueue* pq);
int isEmpty(priorityQueue* pq);
int isFull(priorityQueue* pq);
int insert(priorityQueue* pq, int newValue, int newPriority);
int pop(priorityQueue* pq, int* poppedValue);
int peek(priorityQueue* pq, int* topValue, int* topPriority);