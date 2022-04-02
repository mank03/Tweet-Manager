#include "headerA3.h"
#include "header2A3.h"

void saveTweetsToFile(tweet * tweetList)
{
    //declare and initialize required variables
    FILE *file;
    tweet *temp;
    char filename[50];
    char *pointer;
    int x = 0;

    while(x==0)
    {
        //ask user for file name to store tweets
        printf("Enter the filename you would like to store your tweets: ");
        scanf("%s", filename);
        pointer = filename + strlen(filename);

        //if statement to check if file extension is csv
        if((pointer = strstr(filename,".")) != NULL ) 
        {   
            //printf("pointer: %s\n", pointer);
            //if file extension is not csv, then loop again
            if((strcmp(pointer,".csv") != 0))
            {
                x = 0;
                printf("1 - File extension is not .csv!\n");
            }
            else
            {
                printf("output successful!\n");

                //otherwise, open file in write mode
                x = 1;
                file = fopen(filename, "w");
                //check if file pointer is NULL
                if(file == NULL)
                {
                    printf("file is NULL\n");
                    return;
                }
                //using for loop to obtain information of linked list
                for(temp = tweetList; temp != NULL; temp = temp -> next)
                {
                    fprintf(file, "%d,", temp -> id);
                    fprintf(file, "%s,", temp -> user);
                    //fwrite(temp -> id, sizeof(int), sizeof(temp -> id)+1, file);
                    //fwrite(temp -> id, sizeof(int), sizeof(temp -> id)+1, file);
                    //fwrite("\"" + temp -> text + "\"", sizeof(char), strlen(temp -> text)+1, file);
                    //fprintf(file, "\"");
                    fprintf(file, "%s,", temp -> text);
                    //fprintf(file, "\"");
                    //fprintf(file, "%s\n", "\"" + temp -> text + "\"");
                    fprintf(file, "\n");
                }
            }
        }
        else
        {
            x = 0;
            printf("3 -File extension is not .csv!\n");
        }
    }

    //close file once done
    fclose(file);
}