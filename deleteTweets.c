#include "headerA3.h"
#include "header2A3.h"

void deleteTweet(tweet ** tweetList)
{
    //declare and initialize required variables
    int delete = 0;
    int count = 0;
    tweet *node = *tweetList;
    tweet *node2;
    tweet *a = *tweetList;
        
    //while loop to count number of tweets
    while(a != NULL)
    {
        count++;
        a = a -> next;
    }

    if(count == 0)
    {
        return;
    }
    
    printf("Currently there are %d tweets.\n", count);
    
    //ask user which tweet to delete
    printf("\nWhich tweet do you wish to delete - enter a value between 1 and %d: ", count);
    scanf("%d", &delete);

    //if delete = 1, set head the next node
    if(delete == 1)
    {
        *tweetList = node -> next;
        printf("\nTweet %s deleted. There are now %d tweets left.\n", node -> user, count - 1);
        //free node after dynamically allocated and return function
        free(node);
        return;
    }
    else if(delete > count || delete < 1)
    {
        //check for invalid input
        printf("Invalid entry\n");
    }
    else
    {
        //otherwise, delete the user requested node using while loop
        while(--delete)
        {
            node2 = node;
            node = node -> next;
        }
        node2 -> next = node -> next;
        printf("\nTweet %s deleted. There are now %d tweets left.\n", node -> user, count - 1);
    }
    //free node after dynamically allocated and return function
    free(node);
}