#include "headerA3.h"
#include "header2A3.h"

void displayTweets(tweet * tweetList)
{
    //loops through each of node and prints username, user tweet and ID
    while(tweetList != NULL)
    {
        printf("%d: Created by %s: %s", tweetList->id, tweetList->user, tweetList->text);
        printf("\n");
        tweetList = tweetList -> next;
    }
}
