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
            //if file extension is not csv, then loop again
            if((strcmp(pointer,".csv") != 0))
            {
                x = 0;
                printf("File extension is not .csv!\n");
            }
            else
            {
                //otherwise, open file in read mode
                x = 1;
                file = fopen(filename, "r");
                if(file == NULL)
                {
                    printf("file is NULL\n");
                    return;
                }
                
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
                            temp2 = *tweetList;
                            while(temp2 != NULL)
                            {
                                //if equal generate random user ID number
                                if(atoi(token) == temp2 -> id)
                                {
                                    srand(time(NULL));
                                    temp2 -> id += rand()%999 + 1;
                                }
                                else
                                {
                                    //otherwise do nothing
                                }
                                //go to next node
                                temp2 = temp2 -> next;
                            }
                        }
                        else if(a == 2)
                        {
                            //when a=2, strcpy temp->user from token
                            strcpy(temp -> user, token);
                        }
                        else if(a >= 3)
                        {
                            //when a>=3, strcat temp->text from token
                            strcat(temp -> text, token);
                            strcat(temp->text, " ");
                        }
                        token = strtok(NULL, ",");
                    }
                    //add loaded tweet node to end of linked list
                    addNodeToList(tweetList, temp);
                    a = 0;
                }
                printf("Tweets imported!\n");
            }
        }
        else
        {
            x = 0;
            printf("File extension is not .csv!\n");
        }
    }
    //close the file once done
    fclose(file);
}