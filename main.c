#include <stdio.h>
#include <stdlib.h>
#include "priorityQueue.h"


void printIndex(priorityQueue* pqList[]);
int chooseQ(priorityQueue* pqList[], int pqListSize);

int main()
{
    int loop = 1, command, pqChoice, newValue, newPr, poppedValue, value, pr, pqListSize = 0;
    priorityQueue* pqList[100] = {NULL};
    printf("Priority Queue\n\n");

    while(loop == 1)
    {
        printf("\n\n\n[1] - Create\n[2] - isEmpty\n[3] - isFull\n[4] - Insert\n[5] - Pop\n[6] - Peek\n[7] - Delete\n[8] - Exit\n\n");

        printf("Iveskite komandos numeri ir paspauskite Enter: ");
        scanf("%d", &command);
        printf("\n\n");
        int i = 0;
        switch (command)
        {
        case 1:
            i = 0;

            while(pqList[i] != NULL)
                i++;

            pqList[i] = createQ();
            pqListSize++;
           
            printf("-> Prideta nauja prioritetine eile su indeksu #%d\n", i);
            break;
        case 2:
            pqChoice = chooseQ(pqList, pqListSize);
            if(pqChoice == -1)
                break;
         
            if(isEmpty(pqList[pqChoice]) == 1)
                printf("-> Eile #%d yra tuscia\n", pqChoice);
            else
                printf("-> Eile #%d nera tuscia\n", pqChoice);

            break;
        case 3:
            pqChoice = chooseQ(pqList, pqListSize);
            if(pqChoice == -1)
                break;
                     
            if(isFull(pqList[pqChoice]) == 1)
                printf("-> Eile #%d yra pilna\n", pqChoice);
            else
                printf("-> Eile #%d nera pilna\n", pqChoice);

            break;
        case 4:
            pqChoice = chooseQ(pqList, pqListSize);
            if(pqChoice == -1)
                break;
            
            printf("Iveskite per tarpa nauja reiksme ir jos prioriteta (mazesnis skaicius = didesnis prioritetas), paspauskite Enter:\n");
            scanf("%d %d", &newValue, &newPr);
          
            if(insert(pqList[pqChoice], newValue, newPr) == 1)
                printf("-> Naujas elementas sekmingai pridetas i eile #%d\n", pqChoice);
            else
                printf("-> Naujas elementas nebuvo pridetas, nes eile #%d pilna\n", pqChoice);

            break;
        case 5:
            pqChoice = chooseQ(pqList, pqListSize);
            if(pqChoice == -1)
                break;
      
            if(pop(pqList[pqChoice], &poppedValue) == 1)
                printf("-> Virsutinis elementas sekmingai pasalintas is eiles #%d, jo reiksme: %d\n", pqChoice, poppedValue);
            else
                printf("-> Virsutinis elementas nebuvo pasalintas, nes eile #%d tuscia\n", pqChoice);
            break;
        case 6:
            pqChoice = chooseQ(pqList, pqListSize);
            if(pqChoice == -1)
                break;
   
            if(peek(pqList[pqChoice], &value, &pr) == 1)
                printf("-> Virsutinio eiles #%d elemento reiksme: %d, prioritetas: %d\n", pqChoice, value, pr);
            else
                printf("-> Virsutinio elemento nera, eile #%d tuscia\n", pqChoice);
            break;
        case 7:
            pqChoice = chooseQ(pqList, pqListSize);
            if(pqChoice == -1)
                break;
            
            
            deleteQ(pqList[pqChoice]);
            pqList[pqChoice] = NULL;
            pqListSize--;

            printf("-> Eile #%d pasalinta\n",pqChoice);

            break;
        case 8:        
            printf("-> Programa uzdaryta\n");
            loop = 0;

            break;  
        default:       
            printf("Tokia komanda neegzistuoja\n");
            break;
        }
    }
    return 0;
}


void printIndex(priorityQueue* pqList[])
{
    for(int i = 0; i < 100; i++)
    {
        if(pqList[i] != NULL)
            printf("#%d ",i);
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
    printf("\n\n");

    if(pqList[pqChoice] == NULL || pqChoice < 0 || pqChoice > 99)
    {
        printf("Eile #%d neegzistuoja\n",pqChoice);
        return -1;
    }

    return pqChoice;
}