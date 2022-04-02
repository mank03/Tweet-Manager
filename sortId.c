#include "headerA3.h"
#include "header2A3.h"

void sortID (tweet ** head)
{    
    //declare and initialize required variables
    tweet* temp1;
    tweet* temp2;

    //check if head is NULL
    if(*head == NULL)
    {
        printf("head is NULL\n");
        return;
    }
    else
    {
        //otherwise, using for loop, set temp variable to head and loop through each node to perform bubble sort sorting method
        for(temp1 = *head; temp1 != NULL; temp1 = temp1 -> next)
        {
            for(temp2 = temp1 -> next; temp2 != NULL; temp2 = temp2 -> next)
            { 
                if(temp1 -> id > temp2 -> id)
                {   
                    //malloc a temp3 to store data in a temporary location
                    tweet* temp3 = malloc(sizeof(tweet));

                    temp3->id = temp1->id;
                    strcpy(temp3->user, temp1->user);
                    strcpy(temp3->text, temp1->text);

                    temp1 ->id = temp2 ->id;
                    strcpy(temp1->user, temp2->user);
                    strcpy(temp1->text, temp2->text);

                    temp2 -> id = temp3->id;
                    strcpy(temp2->user, temp3->user);
                    strcpy(temp2->text, temp3->text);
                    //free temp3 once memory is dynamically allocated
                    free(temp3);
                }
            }
        }
    }

    printf("linked list is sorted.\n");
}  
