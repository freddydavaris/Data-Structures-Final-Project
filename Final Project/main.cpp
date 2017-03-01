/*
 * main.cpp
 *
 */
#include "Hashtable.h"
#include "WordList.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	string filename;
	WordList wordlist;

	if (argc == 2) { // if there is a filename on the command line
		wordlist.read_lyrics(argv[1],true);
	}
	else { // use a pre-defined filename
		//filename = "Text_of_songs.txt";
		//filename = "rick_db.txt";
		cout << " PROGRAM HAS BEGUN! HI NITTA" << endl;
		filename = "lyrics_fulldb.txt";
	        wordlist.read_lyrics(filename.c_str(),true);
	}
	//
	//wordlist.Print(0);
	wordlist.search();


        return 0;
}
