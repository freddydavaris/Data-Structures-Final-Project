// 
//  InsertionSort.cpp
//  Sorts integers using the InsertionSort algorithm


#include "InsertionSort.h"

using namespace std;

InsertionSort::InsertionSort(){ // constructor
        sortArray.length = 0;
        sortArray.arr = NULL;
}

// reads in a list of integers from stdin and returns an arrayWithLength
void InsertionSort::readList(){
        int currentCapacity = 10;
        sortArray.arr = new int[currentCapacity];
        
        while (cin >> sortArray.arr[sortArray.length]) {
                ++sortArray.length;
                if (sortArray.length==currentCapacity) {
                        int *temp = new int[currentCapacity*2];
                        for (int i=0;i<currentCapacity;i++) {
                                temp[i] = sortArray.arr[i];
                        }
                        delete [] sortArray.arr;
                        sortArray.arr = temp;
                        currentCapacity *= 2;
                }
        }
}

void InsertionSort::sort(){
        // Insertion sort on sortArray
	int temp;
	// loop that goes through all elements of the array starting from the second one
	for (int i = 1; i < sortArray.length; i++){
		// compares the checked element with all of its previous elements and swaps it
		// everytime it is smaller than any of the preceding ones. 
		for (int k = i; sortArray.arr[k] < sortArray.arr[k-1] ; k--) {
			if (sortArray.arr[k] < sortArray.arr[k-1]) {
				
				// swaps adjacent integers if the right one is greater
				// than the left one
				temp = sortArray.arr[k-1];
				sortArray.arr[k-1] = sortArray.arr[k];
				sortArray.arr[k] = temp;
			}
		}
	}
}

void InsertionSort::printArray(){
        // prints out the integers in sorted order
	for (int i = 0; i < sortArray.length; i++) {
		cout << sortArray.arr[i] << endl; 
	}

}