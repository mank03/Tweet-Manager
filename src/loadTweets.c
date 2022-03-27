#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
#include "../include/headerA3.h"


void loadTweetsFromFile(tweet ** tweetList)
{
    FILE *file;
    tweet *temp;

    char filename[20];
    char *pointer;
    char *token;
    int x = 0;

    char userInfo[100];
    token = strtok(userInfo, ",");



    while(x==0)
    {
        printf("Enter a filename to load from: ");
        scanf("%s", filename);
        pointer = filename + strlen(filename);

        if(file == NULL)
        {
            exit(1);
        }

        //if((strcmp(pointer,".csv.csv") != 0) && (strcmp(pointer,".csv") == 0))
        if((pointer = strstr(filename,".")) != NULL ) 
        {   
            printf("pointer: %s\n", pointer);
        
            if((strcmp(pointer,".csv") != 0))
            {
                x = 0;
                printf("1 - File extension is not .csv!\n");
            }
            else
            {
                printf("1 - HELLO!!\n");
                x = 1;
                file = fopen(filename, "r");
                if(file == NULL)
                {
                    exit(1);
                }
                printf("2 - HELLO!!\n");

                while(!feof(file))
                {
                    if(token == NULL)
                    {
                        printf("temp is NULL\n");
                    }
                    while(token != NULL)
                    {
                        temp = malloc(sizeof(tweet));
                        temp -> next = NULL;

                        fgets(userInfo, sizeof(userInfo), file);
                        userInfo[strlen(userInfo)-1] = '\0';
                        //printf("\nUSER: %s\n", userInfo);

                        token = strtok(NULL, ",");
                    }


                    //addNodeToList(tweetList, userInfo);
                }
                 
                
                
                 
                 
                 /*
                while(fscanf(file, "%d, %s, %s\n", &temp -> id, temp -> user, temp -> text) != EOF)
                {
                    
                    printf("3 - HELLO!!\n");
                    printf("\nUsername: %s\n", temp->user);
                    printf("User Tweet: %s\n", temp->text);
                    printf("User ID: %d\n", temp->id);

                    //addNodeToList(tweetList, temp);


                   
                    

                    
                    
                    
                   
                    if(node == NULL)
                    {
                        *tweetList = node; (tweet*)malloc(sizeof(tweet));
                        node = (tweet*)malloc(sizeof(tweet));
                        node -> id = temp -> id;
                        strcpy(node -> user, temp -> user);
                        strcpy(node -> text, temp -> text);
                        printf("4 - HELLO!!\n");
                    }
                    else
                    {
                        while(node -> next != NULL)
                        {
                            node = node -> next;
                        }

                        node -> next = (tweet*)malloc(sizeof(tweet));
                        strcpy(node -> user, temp -> user);
                        strcpy(node  -> text, temp -> text);
                        //node -> next = (tweet*)malloc(sizeof(tweet));
                        //node = node -> next;
                        printf("5 - HELLO!!\n");
                        node -> next = NULL;
                    }   
                   
                }
                 */
            }
        }
        else
        {
            x = 0;
            printf("3 -File extension is not .csv!\n");
        }
    }

    /*
    printf("\nUsername: %s\n", temp->user);
    printf("User Tweet: %s\n", temp->text);
    printf("User ID: %d\n", temp->id);
    */

   fclose(file);
}