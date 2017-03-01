#ifndef SONG_H
#define SONG_H

#include <vector>
#include <string>
using namespace std;

class Song {
	public:
		Song();
		~Song(); 	

		string getSongName();

		string getSongArtist();
		
		void setSongName(string songname);

		void setSongArtist(string songartist);
				
		void insert(string word);
		
		void print(); 
		
		vector<string> words;

		
		

	private:
		string song_name;
		
		string song_artist;
		

		


};

		
#endif	/* SONG_H */



