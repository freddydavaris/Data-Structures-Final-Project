//
//  WordList.h
//  
//

#ifndef __WordList__
#define __WordList__

#include "Hashtable.h"
#include "Song.h"
#include "hashfunc.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class WordList {
	public:
		WordList(); 
		~WordList();
		
		void read_lyrics(const char * filename, bool show_progress);
		
		string alpha_only(string s);
		
		void search();
		
		void Print(int index);
		
		void Sort(SongInfo *top_searches); 
		
	private:
		
		Hashtable table; 
		
		vector<Song*> list_songs; 
 
};

#endif
