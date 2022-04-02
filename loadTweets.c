#include "headerA3.h"
#include "header2A3.h"

void loadTweetsFromFile(tweet ** tweetList)
{
    //declare and initialize required variables
    FILE *file;
    tweet *temp;
    tweet *temp2;
    char filename[50];
    char *pointer;
    char *token;
    int x = 0;
    char userInfo[1000];
    int a = 0;


    while(x==0)
    {
        //take user input for file name
        printf("Enter a filename to load from: ");
        scanf("%s", filename);
        pointer = filename + strlen(filename);

        //if statement to check if file extension is csv
        if((pointer = strstr(filename,".")) != NULL ) 
        {   
            printf("pointer: %s\n", pointer);
            //if file extension is not csv, then loop again
            if((strcmp(pointer,".csv") != 0))
            {
                x = 0;
                printf("1 - File extension is not .csv!\n");
            }
            else
            {
                //otherwise, open file in read mode
                printf("1 - HELLO!!\n");
                x = 1;
                file = fopen(filename, "r");
                if(file == NULL)
                {
                    printf("file is NULL\n");
                    return;
                }
                printf("2 - HELLO!!\n");
                
                //using while loop that loops to end of file and gets user information
                //!feof(file)
                while(fgets(userInfo, sizeof(userInfo), file))
                {
                    //mallocing a temp variable to store user info
                    temp = calloc(sizeof(tweet), 1);
                    temp -> next = NULL;
                    //using fgets to get each line of fine
                    //fgets(userInfo, sizeof(userInfo), file);
                    userInfo[strlen(userInfo)-1] = '\0';
                    printf("\n\nINFO: %s ", userInfo); 
                    
                    //strtok array with delimiter of ","
                    token = strtok(userInfo, ",");

                    //checking if strtok is NULL
                    if(token == NULL)
                    {
                        printf("token is NULL\n");
                    }
                    //while token is not equal to NULL, populate token into corresponding data
                    while(token != NULL)
                    {
                        a++;
                        //spliting a count variable into 3 parts, first is the id, second is the username, third and greater is the user text
                        if(a == 1)
                        {
                            //when a=1, set temp->id to token using atoi
                            temp -> id = atoi(token);
                            printf("\nID: %s ", token);
                            printf("\na:%d - User ID: %d\n", a, temp->id);
                            temp2 = *tweetList;
                            while(temp2 != NULL)
                            {
                                //if equal generate random user ID number
                                if(atoi(token) == temp2 -> id)
                                {
                                    srand(time(NULL));
                                    temp2 -> id += rand()%999 + 1;
                                    printf("it is the same\n");
                                }
                                else
                                {
                                    //otherwise do nothing
                                    printf("it is NOT the same\n");
                                }
                                //go to next node
                                temp2 = temp2 -> next;
                            }
                        }
                        else if(a == 2)
                        {
                            //when a=2, strcpy temp->user from token
                            strcpy(temp -> user, token);
                            printf("\nUSER: %s ", token);
                            printf("\na:%d - Username: %s\n", a, temp->user);
                        }
                        else if(a >= 3)
                        {
                            //when a>=3, strcat temp->text from token
                            strcat(temp -> text, token);
                            strcat(temp->text, " ");
                            printf("\nTEXT: %s ", token);
                            printf("\na:%d - User Tweet: %s\n", a, temp->text);
                            //temp->text[strlen(token) * 2] = '\0';
                        }
                        else if(a != 2)
                        {
                            printf("hi\n");
                            //break;
                        }
                        //printf("\na:%d - TOKEN: %s ", a, token); 
                        printf("\n");
                        token = strtok(NULL, ",");
                    }
                    
                    //add loaded tweet node to end of linked list
                    addNodeToList(tweetList, temp);
                    a = 0;
                }
                    //printf("USER: %s ", userInfo);
            }
        }
        else
        {
            x = 0;
            printf("3 -File extension is not .csv!\n");
        }
    }
    //close the file once done
    fclose(file);
}