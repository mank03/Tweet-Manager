konnurManuA3: createTweet.o displayTweets.o searchTweets.o stopWords.o deleteTweets.o saveTweets.o loadTweets.o sortId.o mainA3.o
	gcc -Wall -std=c99 -g createTweet.o displayTweets.o searchTweets.o stopWords.o deleteTweets.o saveTweets.o loadTweets.o sortId.o mainA3.o -o bin/konnurManuA3

createTweet.o: src/createTweet.c include/headerA3.h 
	gcc -Wall -std=c99 -c -g src/createTweet.c

displayTweets.o: src/displayTweets.c include/headerA3.h 
	gcc -Wall -std=c99 -c -g src/displayTweets.c

searchTweets.o: src/searchTweets.c include/headerA3.h 
	gcc -Wall -std=c99 -c -g src/searchTweets.c

stopWords.o: src/stopWords.c include/headerA3.h 
	gcc -Wall -std=c99 -c -g src/stopWords.c

deleteTweets.o: src/deleteTweets.c include/headerA3.h 
	gcc -Wall -std=c99 -c -g src/deleteTweets.c

saveTweets.o: src/saveTweets.c include/headerA3.h 
	gcc -Wall -std=c99 -c -g src/saveTweets.c

loadTweets.o: src/loadTweets.c include/headerA3.h 
	gcc -Wall -std=c99 -c -g src/loadTweets.c

sortId.o: src/sortId.c include/headerA3.h 
	gcc -Wall -std=c99 -c -g src/sortId.c	

mainA3.o: src/mainA3.c include/headerA3.h 
	gcc -Wall -std=c99 -c -g src/mainA3.c

clean: 
	rm *.o bin/konnurManuA3
