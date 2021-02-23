/**
 * Project 1 - Part One.
 *
 * Copyright (c) [2021], Zhao Liu.
 */

#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

const int ARRAY_SIZE = 8;

void displayArray(char *array) {
  for (int i = 0; i < ARRAY_SIZE; i++) {
    cout << array[i];
  }
  cout << endl;
}

int main() {
  char accum[ARRAY_SIZE];
  char element;
  ifstream inFile;
  string fileName = "Data.txt";

  inFile.open(fileName);

  // Read 8 chars from "Data.txt" store the 8 chars in array accum[8]
  for (char i = 0; i < ARRAY_SIZE; i++) {
    inFile >> accum[i];
  }

  // Output the original array elements
  displayArray(accum);

  while (inFile >> element && element != 'S') {
    // If the next char read is an 'R'
    if (element == 'R') {
      for (int i = (ARRAY_SIZE - 2); i >= 0; i--) {
        accum[i + 1] = accum[i];
      }
      accum[0] = 'Z';
      // Output the array elements when 'R' is read
      displayArray(accum);
    }

    // If the next char read is an 'L'
    if (element == 'L') {
      for (int i = 0; i < (ARRAY_SIZE - 1); i++) {
        accum[i] = accum[i + 1];
      }
      accum[7] = 'Z';
      // Output the array elements when 'L' is read
      displayArray(accum);
    }

    // If the next char read is an 'A'
    if (element == 'A') {
      for (int i = (ARRAY_SIZE -2); i >= 0; i--) {
        accum[i + 1] = accum[i];
      }
      // Output the array elements when 'A' is read
      displayArray(accum);
    }
  }

  inFile.close();
  
  return 0;
}