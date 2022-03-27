#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
#include "../include/headerA3.h"


void deleteTweet(tweet ** tweetList)
{
    int delete = 0;
    int count = 0;
    tweet *node = *tweetList;
    tweet *node2;
    
    
    tweet *a = *tweetList;
        
    while(a != NULL)
    {
        count++;
        a = a -> next;
    }
    
    printf("Currently there are %d tweets.\n", count);
    

    printf("Which tweet do you wish to delete - enter a value between 1 and %d: ", count);
    scanf("%d", &delete);


    if(delete == 1)
    {
        *tweetList = node -> next;
        //node -> next = NULL;
        printf("Tweet %s deleted. There are now %d tweets left.", node -> user, count - 1);
        free(node);
        return;
    }
    else if(delete > count || delete < 1)
    {
        printf("Invalid entry\n");
    }
    else
    {
        while(--delete)
        {
            node2 = node;
            node = node -> next;
        }
        node2 -> next = node -> next;
        printf("Tweet %s deleted. There are now %d tweets left.", node -> user, count - 1);
    }

    free(node);
}