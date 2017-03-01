
#include <iostream>
#include <stdio.h>
#include "Hashtable.h"
#include "hashfunc.h"
#include <sstream>
#include <fstream>
#include "Song.h"
// HERE

using namespace std;

// constructor
Hashtable::Hashtable()
{
	table = new HashedItems[INIT_CAPACITY];
	table_capacity = INIT_CAPACITY;
	table_count = 0; 
	for(int i = 0; i < table_capacity; i++)
	{
		table[i].alpha_only_word = "";
	}
}
//destructor
Hashtable::~Hashtable() 
{
/*	for (int i = 0; i < table_capacity; i++) {
		if (table[i].alpha_only_word != "") {
			delete table[i].songs;
		}
	}  */ 
	delete [] table;
}

// linear probing
//
//  returns number of collisions before finding a spot
//
void Hashtable::insert(string word, SongInfo *songs)
{
	unsigned int hash_value = hash_string(word); 
	int attempt = 0;
	int index;
	bool done_searching = false;
	if (load_factor() > 0.7) {
		expand(); 
	}
	
	while(!done_searching)
	{
		index = (hash_value + attempt) % table_capacity;
		if (table[index].alpha_only_word != "") {
			attempt++;
		}
		else {
			
			done_searching = true;
			table[index].alpha_only_word = word;
			table[index].songs = songs;		
			table_count++;
		}
	}
}

SongInfo *Hashtable::find(string word) {
	
		unsigned int hash_value = hash_string(word); 
		int attempt = 0; 
		bool done_searching = false; 
		bool found_word = false;
		int index; 
			
		while(!done_searching) {
			
			index = (hash_value + attempt) % table_capacity;

			if (table[index].alpha_only_word == "") {
				done_searching = true;
			}
			else if (table[index].alpha_only_word != word) {
				attempt++; 
			}
			else {
				done_searching = true; 
				found_word = true; 
 				return table[index].songs;
			}
		}
		if (found_word){
			return table[index].songs;
		}
		else {
			return NULL;	
		}
}
// Expands the hashtable when 70% of it is filled
void Hashtable::expand() 
{
	int newCapacity = table_capacity * 2 ; 
	int tempCapacity = table_capacity; 
	
	//create a new table with twice the capacity
	HashedItems *tempTable = new HashedItems[newCapacity];
	HashedItems *tempPointer = table; 
	//initialize the new table with alpha only word set to ""
	for (int i = 0; i < newCapacity; i++){
		tempTable[i].alpha_only_word = ""; 
	}
	table = tempTable; 
	tempTable = tempPointer;
 	table_capacity = newCapacity; 
 	table_count = 0; 
 	
	for (int i = 0; i < tempCapacity; i++) {
		if (tempTable[i].alpha_only_word != ""){
			insert(tempTable[i].alpha_only_word, tempTable[i].songs);
			
		}
	}
	delete [] tempTable; 
}
// Gets the capacity of the table so that it knows when to expand
int Hashtable::get_capacity(){ 
	
	return table_capacity;
}
// Gets the table count of the table so that it knows when to expand
int Hashtable::get_size(){

	return table_count;
}
