#ifndef HASHTABLE_H
#define HASHTABLE_H

#include<vector>
#include<string>
#include "Song.h"

#define MAX_LOAD_FACTOR 0.7
#define INIT_CAPACITY 6

using namespace std;

struct SongInfo {
	//pointer
	Song *pointer_to_Song_Class; 
	int freq;

};

struct HashedItems {
	string alpha_only_word; 
	//vector<SongInfo> *songs;
	// are these equivalent  HERE
	SongInfo *songs; 
};

class Hashtable {
	public:
		Hashtable();
		~Hashtable();
		
		void insert(string word, SongInfo *songs);
		
 		SongInfo *find(string word);  // if it empty we insert, 
 								//if not empty we figure out the collision

		float load_factor() {return (float)table_count /
						table_capacity;}
		
		int get_capacity(); 
		
		int get_size(); 
	

		
	private:
		
		void expand(); 
		int table_capacity;
		HashedItems *table;
		int table_count;
};

		
#endif	/* HASHTABLE_H */


