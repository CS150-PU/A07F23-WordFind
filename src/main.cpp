//******************************************************************************
// File name:   main.cpp
// Author:      CS Faculty
// Date:        11/17/2023
// Class:       CS150-xx (xx is your section number)
// Assignment:  Word Find
// Purpose:     Word find puzzle
// Hours:       xxx
//******************************************************************************

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>

using namespace std;

const int NUM_SYMBOLS = 3;
const int MAX = 20;
const string FILE_NAME = "data/puzzle.txt";

void printHeading (string prompt, char symbol);
void openFile (ifstream &inFile);
void readPuzzle (ifstream &inFile, int &numRows, int &numCols, 
                 char puzzle[][MAX]);
void printPuzzle (char puzzle[][MAX], int numRows, int numCols);
void searchPuzzle (ifstream &inFile, char puzzle[][MAX], int numRows, 
                   int numCols);

int main () {
  ifstream inFile;
  int numRows, numCols;
  char puzzle[MAX][MAX];



  return EXIT_SUCCESS;
}

/***********************************************************************
Function:			printHeading

Description:	Displays a heading to the screen

Parameters:		prompt  - the text to be displayed
							symbol  - the symbol to be displayed three times on either
                        side of the prompt

Returned:			None
***********************************************************************/
void printHeading (string prompt, char symbol) {

}

/***********************************************************************
Function:			openFile

Description:	Opens the file and checks that it was opened correctly

Parameters:		inFile  - the input file stream passed by reference

Returned:			None
***********************************************************************/
void openFile (ifstream &inFile) {

}

/***********************************************************************
Function:			readPuzzle

Description:	Reads in the size of the puzzle and the puzzle from the file

Parameters:		inFile  - the input file stream passed by reference
              numRows - number of rows in the puzzle
              numCols - number of columns in the puzzle
              puzzle  - the puzzle

Returned:			None
***********************************************************************/
void readPuzzle (ifstream &inFile, int &numRows, int &numCols, 
                 char puzzle[][MAX]) {

}

/***********************************************************************
Function:			printPuzzle

Description:	Displays the puzzle to the screen

Parameters:		puzzle  - the puzzle
              numRows - number of rows in the puzzle
              numCols - number of columns in the puzzle

Returned:			None
***********************************************************************/
void printPuzzle (char puzzle[][MAX], int numRows, int numCols) {

}

/***********************************************************************
Function:			searchPuzzle

Description:	Reads in the words from the file, searches the puzzle for 
              the word, and displays the results to the screen

              NOTE - the function should call other functions!!

Parameters:		inFile  - the input file stream passed by reference
              puzzle  - the puzzle
              numRows - number of rows in the puzzle
              numCols - number of columns in the puzzle

Returned:			None
***********************************************************************/
void searchPuzzle (ifstream &inFile, char puzzle[][MAX], int numRows, 
                   int numCols) {

}