konnurManuA3: createTweet.o displayTweets.o searchTweets.o stopWords.o deleteTweets.o saveTweets.o loadTweets.o sortId.o mainA3.o
	gcc -Wall -std=c99 createTweet.o displayTweets.o searchTweets.o stopWords.o deleteTweets.o saveTweets.o loadTweets.o sortId.o mainA3.o -o konnurManuA3

createTweet.o: createTweet.c headerA3.h header2A3.h
	gcc -Wall -std=c99 -c createTweet.c

displayTweets.o: displayTweets.c headerA3.h header2A3.h 
	gcc -Wall -std=c99 -c displayTweets.c

searchTweets.o: searchTweets.c headerA3.h header2A3.h
	gcc -Wall -std=c99 -c searchTweets.c

stopWords.o: stopWords.c headerA3.h header2A3.h 
	gcc -Wall -std=c99 -c stopWords.c

deleteTweets.o: deleteTweets.c headerA3.h header2A3.h 
	gcc -Wall -std=c99 -c deleteTweets.c

saveTweets.o: saveTweets.c headerA3.h header2A3.h 
	gcc -Wall -std=c99 -c saveTweets.c

loadTweets.o: loadTweets.c headerA3.h header2A3.h 
	gcc -Wall -std=c99 -c loadTweets.c

sortId.o: sortId.c headerA3.h header2A3.h 
	gcc -Wall -std=c99 -c sortId.c	

mainA3.o: mainA3.c headerA3.h header2A3.h 
	gcc -Wall -std=c99 -c mainA3.c

clean: 
	rm *.o konnurManuA3
