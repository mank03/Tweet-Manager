#define _GNU_SOURCE  //required for strcasestr
#include "headerA3.h"
#include "header2A3.h"

int searchTweetsByKeyword(tweet * tweetList)
{
    //declare and initialize required variables
    //char *temp;
    char *temp2;
    char search[50];
    int x = 0;

    //mallocing a temp variable
    temp2 = malloc(sizeof(tweet));

    //check to see if head or temp2 is NULL 
    if(tweetList == NULL)
    {
        printf("tweetList is NULL\n");
        return 0;
    }
    if(temp2 == NULL)
    {
        printf("TEMP IS NULL\n");
    }
    
    //take user input for keyword search
    printf("Enter a keyword to search: ");
    scanf("%s", search);
    
    //temp2 = tweetList;
    while(tweetList != NULL)
    {       
        strcpy(temp2, tweetList -> text); 
        //temp = strtok(temp2, " ");
        //while(temp != NULL)
        {
            //printf("temp2: %s\n", temp);
            //using strcasestr function to compare temp2 and search
            if(strcasestr(temp2, search))
            {
                //printf("Search found\n");
                printf("Match found for '%s': %s wrote: %s\n", search, tweetList-> user, tweetList -> text);
                x++;
            }
            else
            {
                //printf("Search not found\n");
            }
            //temp = strtok(NULL, " ");
        }
        tweetList = tweetList -> next;
    }

    //return the corresponding value for x
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