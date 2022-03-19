#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
#include <time.h> 
#include <stdbool.h>
#include "../include/headerA3.h"

tweet * createTweet(tweet * tweetList)
{
    tweet *newNode;
    tweetList = NULL;
    int lenUser;
    int lenTweet;
    int sum = 0;

    bool check = true;
    bool var = true;
    
    newNode = malloc(sizeof(tweet));

    printf("Enter a username: ");    
    scanf("%s", newNode -> user);
    getchar();

    printf("Enter user tweet: ");
    fgets(newNode->text, 141, stdin);
    newNode->text[strlen(newNode->text)-1] = '\0';

    lenUser = strlen(newNode -> user);
    lenTweet = strlen(newNode -> text);
    for(int i = 0; i < lenUser; i++)
    {
        sum = sum + newNode -> user[i];
    }

    //printf("\nsum of username characters: %d\n", sum);
    //printf("length of user's tweet: %d\n", lenTweet);
    newNode -> id = sum + lenTweet;
    //printf("User ID is: %d", sum + lenTweet);

    newNode -> next = NULL;



        if(check) 
        {
            tweetList = newNode;
            check = false;
            printf("\nuser id is: %d\n", newNode -> id);
        }
        else
        {
            printf("HELLLO!!\n");
            var = false;

            while(var == false)
            {
                newNode = tweetList;
                var = true;

                while(tweetList != NULL)
                {
                    
                    if(tweetList -> id == newNode -> id)
                    {
                        printf("it is same\n");
                        srand(time(NULL));
                        newNode -> id += rand()%999 + 1;
                        //y -> id = y -> id + random;
                        var = false;
                    }
                    tweetList = tweetList -> next;
                }
            }
       
            printf("\nuser id is %d\n", newNode -> id);
            newNode = tweetList;  
         }

    return newNode;
}
/*
void addNodeToList(tweet**tweetList,tweet * node)
{
    *tweetList = malloc(sizeof(tweet));
        
    if((*tweetList) -> next == NULL)
    {
        *tweetList = node;
    }
    else
    {
        while((*tweetList) -> next != NULL)
        {
            *tweetList = (*tweetList) -> next;
        }
    }
        (*tweetList) -> next = node;
}
*/
