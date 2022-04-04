#define _GNU_SOURCE  //required for strcasestr
#include "headerA3.h"
#include "header2A3.h"

int searchTweetsByKeyword(tweet * tweetList)
{
    //declare and initialize required variables
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
    
    while(tweetList != NULL)
    {       
        strcpy(temp2, tweetList -> text); 
        {
            //using strcasestr function to compare temp2 and search
            if(strcasestr(temp2, search))
            {
                printf("Match found for '%s': %s wrote: %s\n", search, tweetList-> user, tweetList -> text);
                x++;
            }
            else
            {
                //otherwise do nothing
            }
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
        x = 0;
    }

    //free dynamically allocated array
    free(temp2);
    
    return x;
}