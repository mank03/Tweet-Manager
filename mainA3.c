#include "headerA3.h"
#include "header2A3.h"

int main(int argc, char *argv[])
{
    //declare and initialize required variables
    int menuOption = 0;
    int a;
    tweet * tweetList = NULL;
    tweet * mainTweet;
    
    //do while loop to loop through menu options until user enter 9
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

        //ask user to choose menu option
        printf("Choose a menu option: ");
        scanf("%d", &menuOption);
        //switch statement that calls a function corresponding to user input
        switch(menuOption)
        {
            case 1:
                mainTweet = createTweet(tweetList);
                addNodeToList(&tweetList,mainTweet);
                break;
            case 2:
                displayTweets(tweetList);
                break;
            case 3:
                a = searchTweetsByKeyword(tweetList);
                //printf("\na is: %d\n", a);
                break;
            case 4:
                countStopWords(tweetList);
                break;
            case 5:
                deleteTweet(&tweetList);
                break;
            case 6:
                saveTweetsToFile(tweetList);
                break;
            case 7:
                loadTweetsFromFile(&tweetList);
                break;
            case 8:
                sortID (&tweetList);
                break;
            case 9:
                break;
            default: printf ("That is an invalid choice\n");
        }
    }while(menuOption != 9);

    //while loop to free temp variable
    while(tweetList != NULL)
    {
        mainTweet = tweetList;
        tweetList = tweetList -> next;
        free(mainTweet);
    }
    
    return 0;
}
