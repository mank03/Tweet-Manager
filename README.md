# Assignment #3: Dynamic Data Structures

### Information
* Student Name: Manu Konnur
* Student ID: 1178498
* Course: CIS*2500 
* Assignment #3: dynamic data structures (linked lists)
* Date of Last Revision: April 3, 2022

### Setup
To run the program, go to the folder in which contain the files. Use the make command to compile all files and run the executable:
```
$ make
$ ./konnurManuA3
```

### About Program
Via a menu-driven solution, create a program that allows a user to run basic tasks on a set of tweet data that emulates the basic functionality of Twitter.

### Components of Program
#### Create Tweet
When the user enters 1 in the menu option, it will ask for their username and what they would like to tweet and the program will generate a unique user ID. Each tweet is stored in a node at the end of the linked list.
#### Display Tweets
If option 2 is selected, all of the tweets that are currently in memory (ie. in the linked list) will be displayed to the user. 