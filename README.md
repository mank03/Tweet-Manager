# Assignment #3: Dynamic Data Structures

## Information
* Student Name: Manu Konnur
* Student ID: 1178498
* Course: CIS*2500 
* Assignment #3: dynamic data structures (linked lists)
* Date of Last Revision: April 3, 2022

## Setup
To run the program, go to the folder in which contain the files. Use the make command to compile all files and run the executable:
```
$ make
$ ./konnurManuA3
```

## About Program
Via a menu-driven solution, create a program that allows a user to run basic tasks on a set of tweet data that emulates the basic functionality of Twitter.

### Components of Program
#### Creating a New Tweet
When the user enters 1 in the menu option, it will ask for their username and what they would like to tweet and the program will generate a unique user ID. Each tweet is stored in a node at the end of the linked list.
#### Displaying Tweets
If option 2 is selected, all of the tweets that are currently in memory (ie. in the linked list) will be displayed to the user. 
#### Searching Tweets
If option 3 is selected, the user can search for a keyword in the tweets and the linked list will be traversed to find all tweets that have the user-provided substring inside them.
#### Counting Stop Words
If option 4 is selected, the program wil traverse the entire linked list and calculate the number of stop words (set of 25 unique words) that are present across all tweets and total number of stop words.
#### Delete the nth Tweet
If option 5 is selected, the user can delete a tweet between 1 and the nth tweet where n represents the total number of tweets stored in the linked list.
#### Save Tweets to a File
If option 6 is selected, the program will prompt the user for a .csv filename and saves all of their tweets into that file. 
#### Load Tweets from a File
If option 7 is selected, the program will ask the user to enter the .csv filename to load the tweets from. These tweets will extend the existing linked list and will be added to the end of the list.
#### Sort Tweets on ID
If option 8 is selected, the program will sort the linked list nodes on ascending order of userids.
#### Exit Program
If option 9 is selected, the program will terminate.

## Limitations
* Although the loading the tweets in the program functions properly, my method to do so may have been an lengthy and inefficient

## Future Improvemenets
* Continue to have print statements while testing to debug errors and find root of segmentation faults
* Perform some manual tracing to track a variable's value and location