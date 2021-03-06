
#include <iostream>
#include <stdio.h>
#include "Hashtable.h"
#include "hashfunc.h"
#include <sstream>
#include <fstream>

using namespace std;


// constructor
Song::Song()
{
	song_name = "";
	song_artist = "";
}
// destructor
Song::~Song() 
{
	
}
// assignes the song artist to the song class
string Song::getSongArtist(){

	return song_artist; 
}
// assignes the song name to the song class
string Song::getSongName(){
	
	return song_name;	
}
// sets the song name to the song class
void Song::setSongName(string songname) {
		
	song_name = songname;

}
// sets the song name to the song class
void Song::setSongArtist(string songartist) {

	song_artist = songartist;
}

//Inserts word into a vector of lyrics
void Song::insert(string word){
	words.push_back(word); 
}

// Print function used for debugging mostly
void Song::print(){
	
	for (int i = 0; i < words.size(); i++){
		cout << words.at(i) << endl; 
	}
}