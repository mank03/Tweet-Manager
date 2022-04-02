#include "headerA3.h"
#include "header2A3.h"

void countStopWords(tweet * tweetList)
{   
    //declare and initialize required variables
    char *temp;
    char *temp2;
    int x = 0;
    int y = 0;

    //store all stop words in an array
    char stopWords[25][10] = {"a","an","and","are","as","at","be","by","for","from","has","he","in","is","it","its",
                        "of","on","that","the","to","was","were","will","with"};

    //callocing a temp variable
    temp2 = calloc(10, sizeof(tweet));

    //checking if head is NULL
    if(tweetList == NULL)
    {
        printf("tweetList is NULL\n");
        exit(0);
    }

    //checking if the temp variable is NULL
    if(temp2 == NULL)
    {
        printf("TEMP IS NULL\n");
    }
    
    //temp2 = tweetList;
    while(tweetList != NULL)
    {       
        //strcpy temp2 with user tweet text's and strtok to get individual words
        strcpy(temp2, tweetList -> text); 
        temp = strtok(temp2, " ");
        //checking if temp variable is NULL
        if(temp == NULL)
        {
            printf("TEMP IS NULL\n");
        }  
        //using a while loop to loop through nodes and count stop words
        while(temp != NULL)
        {
            for(int i = 0; i < 25; i++)
            {
                if(strcmp(temp, stopWords[i]) == 0)
                {
                    x++;
                    //printf("temp: %s\n", temp);
                }
            }
            //printf("temp: %s\n", temp);
            temp = strtok(NULL, " ");
        }
        //count the number of total tweet and go to next node
        y++;
        tweetList = tweetList -> next;
    }
    printf("Across %d tweets, %d stop words were found.\n", y, x);
    //free temp2 after dynamic allocation
    free(temp2);
}
