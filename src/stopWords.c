#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
#include <time.h> 
#include <stdbool.h> 
#include "../include/headerA3.h"


void countStopWords(tweet * tweetList)
{   
    char *temp;
    char *temp2;
    int x = 0;
    int y = 0;

    char stopWords[25][10] = {"a","an","and","are","as","at","be","by","for","from","has","he","in","is","it","its",
                        "of","on","that","the","to","was","were","will","with"};

    temp2 = calloc(10, sizeof(tweet));

    if(tweetList == NULL)
    {
        printf("tweetList is NULL\n");
        exit(0);
    }

    if(temp2 == NULL)
    {
        printf("TEMP IS NULL\n");
    }
    
    //temp2 = tweetList;
    while(tweetList != NULL)
    {       
        strcpy(temp2, tweetList -> text); 
        temp = strtok(temp2, " ");
        if(temp == NULL)
        {
            printf("TEMP IS NULL\n");
        }  
        while(temp != NULL)
        {
            for(int i = 0; i < 25; i++)
            {
                if(strcmp(temp, stopWords[i]) == 0)
                {
                    x++;
                }
            }
            //printf("temp: %s\n", temp);
            temp = strtok(NULL, " ");
        }
        y++;
        tweetList = tweetList -> next;
    }
    printf("Across %d tweets, %d stop words were found.\n", y, x);
    
    free(temp2);
}
