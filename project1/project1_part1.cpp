/**
 * Project 1 - Part One.
 *
 * Copyright (c) [2021], Zhao Liu.
 */

#include <iostream>
#include <fstream>

const int ARRAY_SIZE = 8;

void displayArray(char *array) {
  for (int i = 0; i < ARRAY_SIZE; i++) {
    std::cout << array[i];
  }
  std::cout << std::endl;
}

int main() {
  char accum[ARRAY_SIZE];
  char element;
  std::ifstream inFile;
  std::string fileName = "Data.txt";

  inFile.open(fileName);

  // Read 8 chars from "Data.txt" store the 8 chars in array accum[8]
  for (char i = 0; i < ARRAY_SIZE; i++) {
    inFile >> accum[i];
  }

  // Output the array elements
  displayArray(accum);

  while (inFile >> element && element != 'S') {
    // If the next char read is an 'R'
    if (element == 'R') {
      for (int i = (ARRAY_SIZE - 2); i >= 0; i--) {
        accum[i + 1] = accum[i];
      }
      accum[0] = 'Z';
    }

    // If the next char read is an 'L'
    if (element == 'L') {
      for (int i = 0; i < (ARRAY_SIZE - 1); i++) {
        accum[i] = accum[i + 1];
      }
      accum[7] = 'Z';
    }

    // If the next char read is an 'A'
    if (element == 'A') {
      for (int i = (ARRAY_SIZE -2); i >= 0; i--) {
        accum[i + 1] = accum[i];
      }
    }
  }

  // Output the array elements
  displayArray(accum);

  inFile.close();
  
  return 0;
}