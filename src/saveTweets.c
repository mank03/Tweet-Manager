#include <stdio.h>
#include <stdlib.h>
#include <string.h>	
#include "../include/headerA3.h"

void saveTweetsToFile(tweet * tweetList)
{
    FILE *file;
    tweet *temp;
    char filename[20];
    char *pointer;
    int x = 0;


    while(x==0)
    {
        printf("Enter the filename you would like to store your tweets: ");
        scanf("%s", filename);
        pointer = filename + strlen(filename);

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
                x = 1;
                file = fopen(filename, "w");
                if(file == NULL)
                {
                    exit(1);
                }
                for(temp = tweetList; temp != NULL; temp = temp -> next)
                {
                    fprintf(file, "%d, ", temp -> id);
                    fprintf(file, "%s, ", temp -> user);

                    //fwrite(temp -> id, sizeof(int), sizeof(temp -> id)+1, file);
                    //fwrite(temp -> id, sizeof(int), sizeof(temp -> id)+1, file);
                    //fwrite("\"" + temp -> text + "\"", sizeof(char), strlen(temp -> text)+1, file);

                    //fprintf(file, "\"");
                    fprintf(file, "%s", temp -> text);
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


    fclose(file);
}