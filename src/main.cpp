//******************************************************************************
// File name:   main.cpp
// Author:      CS Faculty
// Date:        8/22/2023
// Class:       CS150-xx (xx is your section number)
// Assignment:  Hello World
// Purpose:     Display the message Hello World to the screen
// Hours:       0.25
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
bool searchHorizontal (char puzzle[][MAX], int numRows, int numCols, 
                       char word[], int length, int &rowI, int &colJ);
bool checkRow (char line[], int numCols, int start, char word[], int length);
bool searchVertical (char puzzle[][MAX], int numRows, int numCols, char word[], 
                     int length, int &rowI, int &colJ);
bool checkCol (char puzzle[][MAX], int numRows, int start, int j, char word[], 
               int length);

int main () {
  ifstream inFile;
  int numRows, numCols;
  char puzzle[MAX][MAX];

  openFile (inFile);

  readPuzzle (inFile, numRows, numCols, puzzle);

  printHeading ("Word Search Puzzle" , '*');
  cout << endl << endl;
  printHeading ("Number of Rows", ':');
  cout << "  " << numRows << endl;
  printHeading ("Number of Columns ", ':');
  cout << "  " << numCols << endl << endl;
  printHeading ("The Puzzle", '/');
  cout << endl;
  printPuzzle (puzzle, numRows, numCols);
  cout << endl;
  printHeading ("Search Word Results", '/');
  cout << endl;
  searchPuzzle (inFile, puzzle, numRows, numCols);

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
  for (int i = 0; i < NUM_SYMBOLS; i++) {
    cout << symbol;
  }
  cout << " " << prompt << " ";
  for (int i = 0; i < NUM_SYMBOLS; i++) {
    cout << symbol;
  }
  cout << " ";
}

/***********************************************************************
Function:			openFile

Description:	Opens the file and checks that it was opened correctly

Parameters:		inFile  - the input file stream passed by reference

Returned:			None
***********************************************************************/
void openFile (ifstream &inFile) {
  inFile.open (FILE_NAME);
  if (inFile.fail()) {
    cout << "The file was not opened" << endl;
    exit (EXIT_FAILURE);
  }
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
  inFile >> numRows >> numCols;

  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numCols; j++) {
      inFile >> puzzle[i][j];
    }
  }
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
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numCols; j++) {
      cout << puzzle[i][j];
    }
    cout << endl;
  }
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
  char word[MAX];
  int wordLength, rowI, colJ;
  while (inFile >> word) {
    cout << setw(20) << left << word;
    wordLength = strlen (word);
    if (searchHorizontal (puzzle, numRows, numCols, word, wordLength, rowI, colJ)) {
      cout << " FOUND " << "(Row: " << rowI << " Column: " << colJ << " Horizontally)";
    }
    else if (searchVertical (puzzle, numRows, numCols, word, wordLength, rowI, colJ)) {
      cout << " FOUND " << "(Row: " << rowI << " Column: " << colJ << " Vertically)";
    }

    cout << endl;
  }
}

bool searchHorizontal (char puzzle[][MAX], int numRows, int numCols, char word[], 
                       int length, int &rowI, int &colJ) {
  bool bFound = false;
  int index = 0;
  for (int i = 0; i < numRows && !bFound; i++) {
    for (int j = 0; j < numCols && !bFound; j++) {
      if (puzzle[i][j] == word[index] && j + length <= numCols) {
        bFound = checkRow (puzzle[i], numCols, j, word, length);
        if (bFound) {
          rowI = i + 1;
          colJ = j + 1;
        }
      }
    }
  }
  return bFound;
}

bool checkRow (char line[], int numCols, int start, char word[], int length) {
  bool bFound = true;
  for (int i = start, j = 0; i < numCols && j < length; i++, j++) {
    if (line[i] != word[j]) {
      bFound = false;
    }
  }
  return bFound;
}

bool searchVertical (char puzzle[][MAX], int numRows, int numCols, char word[], 
                     int length, int &rowI, int &colJ) {
  bool bFound = false;
  int index = 0;
  for (int j = 0; j < numCols && !bFound; j++) {
    for (int i = 0; i < numRows && !bFound; i++) {
      if (puzzle[i][j] == word[index] && i + length <= numRows) {
        bFound = checkCol (puzzle, numRows, i, j, word, length);
        if (bFound) {
          rowI = i + 1;
          colJ = j + 1;
        }
      }
    }
  }
  return bFound;

}

bool checkCol (char puzzle[][MAX], int numRows, int start, int j, char word[], int length){
  bool bFound = true;
  for (int i = start, w = 0; i < numRows && w < length; i++, w++) {
    if (puzzle[i][j] != word[w]) {
      bFound = false;
    }
  }
  return bFound;
}