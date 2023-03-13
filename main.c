#include <stdio.h>
#include <stdlib.h>
#include "priorityQueue.h"


void printIndex(priorityQueue* pqList[]);
int chooseQ(priorityQueue* pqList[], int pqListSize, char errorCodes[10][100]);
void printQ(priorityQueue *pq);

int main()
{
    int loop = 1, command, pqChoice, newValue, newPr, poppedValue, value, pr, pqListSize = 0;

    char errorCodes[10][100] = {"Tokia komanda neegzistuoja\n", "Nesukurta jokiu prioritetiniu eiliu\n", "Tokia eile neegzistuoja\n", "-> Naujas elementas nebuvo pridetas, pasirinkta eile yra pilna\n","-> Virsutinis elementas nebuvo pasalintas, pasirinkta eile yra tuscia\n", "-> Virsutinio elemento nera, pasirinkta eile yra tuscia\n"};

    priorityQueue* pqList[100] = {NULL};
    printf("Priority Queue\n\n");

    while(loop == 1)
    {
        printf("\n\n\n[1] - Sukurti (create)\n[2] - Ar suscia (isEmpty)\n[3] - Ar pilna (isFull)\n[4] - Ideti (Insert)\n[5] - Isimti elementa (Pop)\n[6] - Paziureti virsutini (Peek)\n[7] - Pasalinti eile (Delete)\n[8] - Uzbaigti (Exit)\n\n[9] - Paziureti visa eile (testavimui)\n\n");

        printf("Iveskite komandos numeri ir paspauskite Enter: ");
        scanf("%d", &command);
        printf("\n\n");
        int i = 0;
        switch (command)
        {
        case 1:
            i = 1;

            while(pqList[i] != NULL)
                i++;

            pqList[i] = createQ();
            pqListSize++;
           
            printf("-> Prideta nauja prioritetine eile su indeksu #%d\n", i);
            break;
        case 2:
            pqChoice = chooseQ(pqList, pqListSize, errorCodes);
            if(pqChoice == -1)
                break;
         
            if(isEmpty(pqList[pqChoice]) == 1)
                printf("-> Eile #%d yra tuscia\n", pqChoice);
            else
                printf("-> Eile #%d nera tuscia\n", pqChoice);

            break;
        case 3:
            pqChoice = chooseQ(pqList, pqListSize, errorCodes);
            if(pqChoice == -1)
                break;
                     
            if(isFull(pqList[pqChoice]) == 1)
                printf("-> Eile #%d yra pilna\n", pqChoice);
            else
                printf("-> Eile #%d nera pilna\n", pqChoice);

            break;
        case 4:
            pqChoice = chooseQ(pqList, pqListSize, errorCodes);
            if(pqChoice == -1)
                break;
            
            printf("Iveskite per tarpa nauja reiksme ir jos prioriteta(>0), (abu skaiciai turi buti sveikieji; didesnis prioriteto skaicius = didesnis prioritetas), paspauskite Enter:\n");
            scanf("%d %d", &newValue, &newPr);
          
            if(insert(pqList[pqChoice], newValue, newPr) == 1)
                printf("-> Naujas elementas sekmingai pridetas i eile #%d\n", pqChoice);
            else
                printf("-> Error #4: %s", errorCodes[3], pqChoice);

            break;
        case 5:
            pqChoice = chooseQ(pqList, pqListSize, errorCodes);
            if(pqChoice == -1)
                break;
      
            if(pop(pqList[pqChoice], &poppedValue) == 1)
                printf("-> Virsutinis elementas sekmingai pasalintas is eiles #%d, jo reiksme: %d\n", pqChoice, poppedValue);
            else
                printf("-> Error #5: %s", errorCodes[4]);
            break;
        case 6:
            pqChoice = chooseQ(pqList, pqListSize, errorCodes);
            if(pqChoice == -1)
                break;
   
            if(peek(pqList[pqChoice], &value, &pr) == 1)
                printf("-> Virsutinio eiles #%d elemento reiksme: %d, prioritetas: %d\n", pqChoice, value, pr);
            else
                printf("-> Error #6: %s", errorCodes[5]);
            break;
        case 7:
            pqChoice = chooseQ(pqList, pqListSize, errorCodes);
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
        case 9:
            pqChoice = chooseQ(pqList, pqListSize, errorCodes);
            if(pqChoice == -1)
                break;

            printQ(pqList[pqChoice]);
            break;
        default:       
            printf("-> Error #1: %s\n",errorCodes[0]);
            break;
        }
    }
    return 0;
}


void printIndex(priorityQueue* pqList[])
{
    for(int i = 1; i < 100; i++)
    {
        if(pqList[i] != NULL)
            printf("#%d ",i);
    }
}

int chooseQ(priorityQueue* pqList[], int pqListSize, char errorCodes[10][100])
{
    int pqChoice;
    if(pqListSize == 0)
    {
        printf("-> Error #2: %s", errorCodes[1]);
        return -1;
    }
    printf("Galimos eiles: ");
    printIndex(pqList);
    printf("\nIveskite norimos eiles indeksa ir paspauskite Enter:\n");
    scanf("%d", &pqChoice);
    printf("\n\n");

    if(pqList[pqChoice] == NULL || pqChoice < 0 || pqChoice > 99)
    {
        printf("-> Error #3: %s",errorCodes[2]);
        return -1;
    }

    return pqChoice;
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