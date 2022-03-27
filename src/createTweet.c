#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
#include <time.h> 
#include <stdbool.h>
#include "../include/headerA3.h"

tweet * createTweet(tweet * tweetList)
{
    tweet *newNode;
    tweet *x;
    x = malloc(sizeof(tweet));
    int lenUser;
    int lenTweet;
    int sum = 0;
    int check = 0;
    
    newNode = malloc(sizeof(tweet));

    printf("Enter a username: ");    
    scanf("%s", newNode -> user);
    getchar();

    printf("Enter user tweet: ");
    fgets(newNode->text, 141, stdin);
    //newNode->text[strlen(newNode->text)-1] = '\0';

    lenUser = strlen(newNode -> user);
    lenTweet = strlen(newNode -> text);
    for(int i = 0; i < lenUser; i++)
    {
        sum = sum + newNode -> user[i];
    }
    
    newNode -> id = sum + lenTweet;

    while(check == 0)
    {
        x = tweetList;
        check = 1;
       
        while(x != NULL && tweetList != NULL)
        {
            newNode -> next = NULL;
            if(newNode -> id == x -> id)
            {
                check = 0;
                srand(time(NULL));
                newNode -> id += rand()%999 + 1;
                printf("it is the same");
            }
            else
            {
                printf("it is NOT the same");
            }
            x = x -> next;
        }
    }
    newNode -> next = NULL;
    printf("\nuser id is %d\n", newNode -> id);
    free(x);
    return newNode;
}

void addNodeToList(tweet**tweetList,tweet * node)
{
    tweet *a = *tweetList;
        
    if(*tweetList == NULL)
    {
        *tweetList = node;
    }
    else
    {
        while(a -> next != NULL)
        {
            a = a -> next;
        }
        a -> next = node;
    }
}

