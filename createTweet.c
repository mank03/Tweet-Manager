#include "headerA3.h"
#include "header2A3.h"

tweet * createTweet(tweet * tweetList)
{
    //declare and initialize required variables
    tweet *newNode;
    tweet *x;
    int lenUser;
    int lenTweet;
    int sum = 0;
    int check = 0;
    char a[5000] = {0};
    char b[5000] = {0};
    int j = 0;
    int k = 0;

    //malloc temp variable
    newNode = malloc(sizeof(tweet));

    getchar();  
    //taking user input for username
    while(k == 0)
    {
        k = 1;
        printf("Enter a username: ");
        fgets(b, 5000, stdin); 
        b[strlen(b)-1] = '\0';
        if(strlen(b) == 0 || strlen(b) > 50)
        {
            printf("Error!\n");
            k = 0;
        }
    }

    //taking user input for user text
    while(j == 0)
    {
        j = 1;
        printf("Enter user tweet: ");
        fgets(a, 5000, stdin);
        a[strlen(a)-1] = '\0';
        if(strlen(a) == 0 || strlen(a) > 141)
        {
            printf("Error\n");
            j = 0;
        }
    }
    
    strcpy(newNode -> user, b);
    strcpy(newNode -> text, a);
    //set lenUser and lenText to corresponding strlen
    lenUser = strlen(newNode -> user);
    lenTweet = strlen(newNode -> text);
    
    //calculating sum of ASCII characters
    for(int i = 0; i < lenUser; i++)
    {
        sum = sum + newNode -> user[i];
    }
    //setting newNode -> to sum plus the length of user tweet
    newNode -> id = sum + lenTweet;

    while(check == 0)
    {
        x = tweetList;
        check = 1;

       //while x and head is not equal NULL, generate random user ID number if it already exists
        while(x != NULL && tweetList != NULL)
        {
            newNode -> next = NULL;
            //if equal generate random user ID number
            if(newNode -> id == x -> id)
            {
                check = 0;
                srand(time(NULL));
                newNode -> id += rand()%999 + 1;
                printf("it is the same");
            }
            else
            {
                //otherwise do nothing
                printf("it is NOT the same");
            }
            //go to next node
            x = x -> next;
        }
    }
    //set next node to NULL once done creating node
    newNode -> next = NULL;
    printf("\nYour computer-generated userid is %d.\n", newNode -> id);
    //free temp variable and return new node created

    return newNode;
}
//helper function to add a node to the end of the list
void addNodeToList(tweet**tweetList,tweet * node)
{
    //set a temp variable to head
    tweet *a = *tweetList;
    //if head is NULL, then set to node 
    if(*tweetList == NULL)
    {
        *tweetList = node;
    }
    else
    {
        //other add a to next node and loop to next node
        while(a -> next != NULL)
        {
            a = a -> next;
        }
        a -> next = node;
    }
}

