# ReadMe for COMP 15 HW6
## Song Search 

Every assignment you submit you will include a ReadMe file. The name
could be ReadMe, readme, Read-me.txt, readME, ReadMe.md (the “.md”
stands for “markdown,” which allows lightweight formatting) or almost
anything you like that has the word read followed by the word me. Exact
spelling is not important, the contents are.

The purpose of the ReadMe file is the same as the little paper insert
you get in a new appliance -- to give the reader an introduction and
overview of the product.

Your ReadMe file for the assignments **must** include:

1.
This program reads in a txt file containing 170,000 songs. Each song has its lyrics undeneath. The purpose
of this program is to read in all the files hash them into hashtables and when the user typed in the word it would 
print out the top 10 songs and all of their respetive contexts in which the word is being used. 

2.
Hashtable.cpp/h : Hashtable implementation in which the all words are stored as alpha only. It includes two structs,
		  of hasheditems and hashedinfos.
		  
WordList.cpp/h  : Wordlist is a class implementation in which we call functions like sorting the top-10 song list
		  searching for the context artist and title of a song after a song has been input, etc.
		  
Song.cpp/h 	: Song is a class implementation of a song in which we store song title ,artist and a vector
		  of all the lyircs of the song. Songs are put in a vector which holds songs. 
hashfunc.cpp    : Contains two function definitions one of which we used to convert the string into a int before
		  we hash it into a hashtable

3.
Use included Makefile.

4. 
In this project many data structures were used in order for the final output to be generated. A song class which held
all the information about the songs was held into a vector of songs which was built as songs were read into the database.
This song class was pointed to by a pointer to the song that was held in a struct of song information. This struct held a 
pointer to the song class and the number of times every word of every song was used in the song. To this song class pointed
another struct that held the hashed word in a hastable. This hashtable contained all words that had been used in all the songs that 
were passed into.


5.
Initially a hashtable is initialized which holds all the different words passed into the database. For each word, there is a 
pointer to an array of 11 elements in which we do all the frequency sorting and hold the top 10 songs that will be output 
when the user types the specific word. The eleventh position is where we insert a new song in order to compare it with the
top ten list and evaluate if it makes the list or not. Each song that makes the list points to a song class which it uses to 
get all the rest information of the song and output the context song title and song artist.


6. 
    
    (-)

