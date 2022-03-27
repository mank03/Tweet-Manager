#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
#include <time.h> 
#include <stdbool.h> 
#include <ctype.h>
#include "../include/headerA3.h"

int searchTweetsByKeyword(tweet * tweetList)
{
    char *temp;
    char *temp2;
    char search[10];
    int x = 0;
    int i = 0;

    temp2 = malloc(sizeof(tweet));

    if(tweetList == NULL)
    {
        printf("tweetList is NULL\n");
        exit(0);
    }

    if(temp2 == NULL)
    {
        printf("TEMP IS NULL\n");
    }
    
    printf("Enter a keyword to search: ");
    scanf("%s", search);
    

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
            //printf("temp: %s\n", temp);
            if(toupper(temp[i]) == toupper(search[i]))
            {
                printf("%s\n", tweetList -> user);
                printf("%s\n", tweetList -> text);
                x++;
            }
            else
            {
                printf("Search not found\n");
            }
            
            temp = strtok(NULL, " ");
        }
        tweetList = tweetList -> next;
    }

    if(x != 0)
    {
        x = 1;
    }
    else
    {
        x = -1;
    }

    free(temp2);
    
    return x;
}