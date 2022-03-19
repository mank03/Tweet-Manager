#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
#include <time.h> 
#include <stdbool.h> 
#include "../include/headerA3.h"

int main(int argc, char *argv[])
{
    int menuOption = 0;

    tweet * tweetList;
    tweetList = malloc(sizeof(tweet));

    tweet * mainTweet;
    mainTweet = malloc(sizeof(tweet));

    tweet * head = NULL;

    tweet *temp;

    tweet * node;

    bool var = true;
    bool check = true;

    do
    {
        printf("\nMenu options: \n\n");
        printf("1. Create a Tweet\n");
        printf("2. Display Tweets\n");
        printf("3. Search a Tweet\n");
        printf("4. Count Number of Stop Words\n");
        printf("5. Delete nth Tweet\n");
        printf("6. Save Tweets to File\n");
        printf("7. Load Tweets from File\n");
        printf("8. Sort Linked List\n");
        printf("9. Exit Program\n");

        printf("Choose a menu option: ");
        scanf("%d", &menuOption);

        switch(menuOption)
        {
            case 1:
                
                mainTweet = createTweet(tweetList);
                //addNodeToList(tweetList,node)
                /*
                if(check) 
                {
                    head = mainTweet;
                    check = false;
                    printf("\nuser id is: %d\n", mainTweet -> id);
                }
                else
                {
                    var = false;

                    while(var == false)
                    {
                        tweetList = head;
                        var = true;

                        while(tweetList != NULL)
                        {
                            if(tweetList -> id == mainTweet -> id)
                            {
                                printf("it is same\n");
                                srand(time(NULL));
                                mainTweet -> id += rand()%999 + 1;
                                //y -> id = y -> id + random;
                                var = false;
                            }
                            tweetList = tweetList -> next;
                        }
                    }
                    printf("\nuser id is %d\n", mainTweet -> id);
                    tweetList = head;  
                */
                
                    while(tweetList -> next != NULL)
                    {
                        tweetList = tweetList -> next;
                    }
                    tweetList -> next = mainTweet;
                
                
                break;
            case 2:
                displayTweets(tweetList);
                break;
            case 9:
                break;
            default: printf ("That is an invalid choice\n");
        }
    }while(menuOption != 9);
    /*
    tweet *x;
    x = head;

    while(x != NULL)
    {
        printf("\nUsername: %s\n", x->user);
        printf("User Tweet: %s\n", x->text);
        printf("User ID: %d\n", x->id);
        x = x -> next;
    }
    */
    return 0;
}
