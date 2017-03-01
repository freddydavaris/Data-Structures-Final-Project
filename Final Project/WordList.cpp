/*
 * WordList.cpp
 *
 *  Created on: Dec 3, 2014
 *      Author: 
 */

#include "WordList.h"

using namespace std;
//Constructor
WordList::WordList() {
	
}
// Destructor
WordList::~WordList() {
	
}
//converts words into alpha_only
string WordList::alpha_only(string s){
        ostringstream ss;
        for (size_t i=0;i<s.length();i++) {
                if (isalnum(s[i])){
                        ss << (char)(tolower(s[i]));
                }
        }
        return ss.str();
}
// read in lyrics puts them into hashtables and
// sorts for each wors an array of 10 elements with 
// the top ten songs that use the specified word
void WordList::read_lyrics(const char * filename, bool show_progress)
{	
						// vector of words (all lyrics)
        ifstream in(filename);			// creates an input stream
        int song_count = 0;			// for progress indicator
	string artist, title, word;

	// -- While more data to read...
	while ( ! in.eof() ) 
	{
		// -- First line is the artist
		getline(in, artist);
		if (in.fail()) break;

		// -- Second line is the title
		getline(in, title);
		if (in.fail()) break;

		if ( show_progress )
		{
			song_count++;
			if (song_count % 10000 == 0) {
				cout << "At "       << song_count << 
					" Artist: " << artist     << 
					" Title:"   << title << endl;
			}
		}
		
		Song *s1 = new Song;  
		s1->setSongName(title); 
		s1->setSongArtist(artist);
		
		list_songs.push_back(s1);
		
		SongInfo song_info; 
		song_info.freq = 1; 
		song_info.pointer_to_Song_Class = s1;
	// -- Then read all words until we hit the 
	// -- special <BREAK> token
		while ( in >> word && word != "<BREAK>" ){
		bool wordfound = false; 

			s1->insert(word);
			//  insert in lyrics
			word = alpha_only(word);
 			SongInfo *tempPointer = table.find(word);
			if (tempPointer != NULL){
					
				for (int k = 0; k < 11; k++){

					if (tempPointer[k].pointer_to_Song_Class != NULL && 
						tempPointer[k].pointer_to_Song_Class->getSongArtist() == song_info.pointer_to_Song_Class->getSongArtist() &&
						tempPointer[k].pointer_to_Song_Class->getSongName() == song_info.pointer_to_Song_Class->getSongName()){
						tempPointer[k].freq++;
						wordfound = true; 
						Sort(tempPointer);
						break;	
					}
				}
					if (wordfound == false) {
						for (int y = 0; y < 11; y++) {
							if (y == 10){
								tempPointer[y] = song_info;
								Sort(tempPointer);
								break;
							}
							else if (tempPointer[y].pointer_to_Song_Class == NULL){
								tempPointer[y] = song_info;
								Sort(tempPointer);
								break;
							}
						}
					}
			}
			else {
			
			SongInfo *top_searches = new SongInfo[11];

			for (int i = 0 ; i < 11; i++) { 
				
				top_searches[i].freq = 0; 
				top_searches[i].pointer_to_Song_Class = NULL;
			}
			word = alpha_only(word); 
			top_searches[0] = song_info;
			table.insert(word, top_searches);
			}
		}
		// -- Important: skip the newline left behind
		in.ignore();
	}
}

//Searches for a word and outputs its information 
// along with all of its contexts
void WordList::search()
{
	string searched_word;
	
	cin >> searched_word;

	while (searched_word != "<BREAK>") {
		searched_word = alpha_only(searched_word);
		SongInfo *temp = table.find(searched_word);
		if (temp != NULL) {
			for (int i = 0; i < 10 ; i++) {
		
			
					for (int x = 0; x < temp[i].pointer_to_Song_Class->words.size(); x++){
							
							int Start = 0; 
							int End =  temp[i].pointer_to_Song_Class->words.size();
							if (alpha_only(temp[i].pointer_to_Song_Class->words.at(x)) == searched_word){
								if (x > 5) Start = (x-5); 
								else Start = 0; 
								if (x < (temp[i].pointer_to_Song_Class->words.size() - 5)) End = (x + 5);
								else End = temp[i].pointer_to_Song_Class->words.size() - 1;
								
								cout << "Title: " << temp[i].pointer_to_Song_Class->getSongName() << endl;
								cout << "Artist: " << temp[i].pointer_to_Song_Class->getSongArtist() << endl;
								cout << "Context: "; 
								
								for (int wordpos = Start; wordpos <= End; wordpos++) {
										cout << temp[i].pointer_to_Song_Class
										->words.at(wordpos) << " ";
								}
								cout << endl << endl; 
							}
					
					}
					if (temp[i+1].pointer_to_Song_Class == NULL){
						break;
					}
			}
		
		}
 		cout << endl << "<END OF REPORT>" << endl; 	
		cin >> searched_word; 
	}
	
}

void WordList::Print(int index){
	list_songs.at(index)->print(); 
}

void WordList::Sort(SongInfo *top_searches){

	SongInfo temp;
	// loop that goes through all elements of the array starting from the second one
	for (int i = 1; i < 11; i++){
		// compares the checked element with all of its previous elements and swaps it
		// everytime it is bigger than any of the preceding ones. 
			for (int k = i; top_searches[k].freq > top_searches[k-1].freq ; k--) {
				if (top_searches[k].freq > top_searches[k-1].freq) {
					// swaps adjacent integers if the right one is greater
					// than the left one
					temp.pointer_to_Song_Class = top_searches[k-1].pointer_to_Song_Class;
					temp.freq = top_searches[k-1].freq;
					
					top_searches[k-1].freq = top_searches[k].freq;
					top_searches[k-1].pointer_to_Song_Class = top_searches[k].pointer_to_Song_Class;
					
					top_searches[k].pointer_to_Song_Class = temp.pointer_to_Song_Class;
					top_searches[k].freq = temp.freq;
				}
			}
			
	}
}