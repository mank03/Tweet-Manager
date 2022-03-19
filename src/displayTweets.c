#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
#include <time.h> 
#include <stdbool.h> 
#include "../include/headerA3.h"

void displayTweets(tweet * tweetList)
{
    while(tweetList != NULL)
    {
        printf("\nUsername: %s\n", tweetList->user);
        printf("User Tweet: %s\n", tweetList->text);
        printf("User ID: %d\n", tweetList->id);
        tweetList = tweetList -> next;
    }
}
