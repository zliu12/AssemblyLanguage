/**
 * Project 1 - Part two.
 *
 * Copyright (c) [2021], Zhao Liu.
 */

#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

const int SIZE = 8;
const string FILE1 = "code.txt";
const string FILE2 = "memory.txt";

// Output the content of array
void displayArray(char *array) {
  for (int i = 0; i < SIZE; i++) {
    cout << array[i];
  }
  cout << endl;
}

// Initialize array to '?'
void intialize_array(char *array) {
  for (int i = 0; i < SIZE; i++) {
    *(array + i) = '?';
  }
}

// Shift array element to the right
void shift_right(char *array) {
  for (int i = (SIZE - 2); i >= 0; i--) {
    array[i + 1] = array[i];
  }
}

// Shift array element to the left
void shift_left(char *array) {
  for (int i = 0; i < (SIZE - 1); i++) {
    array[i] = array[i + 1];
  }
}

// Convert array elements 'I' to 'O' and 'O' to 'I'
void convert(char *array) {
  for (int i = 0; i < sizeof(array); i++) {
    if (array[i] == 'O') {
      array[i] = 'I';
    } else if (array[i] == 'I') {
      array[i] = 'O';
    }
  }
}

// Plus arrayA and array B by the addition with bit by bit logic, stores the
// result in arrayA
void bit_add(char *arrayA, char *arrayB) {
  // carry is 'O' by default
  char carry = 'O';

  for (int i = 7; i >= 0; i--) { 
    // arrayA, arrayB have the different element on ith position, carry is 'O'
    // result the 'I', carry stays the same
    if (arrayA[i] != arrayB[i] && carry == 'O') {
      arrayA[i] = 'I';
      carry = 'O';

      // arrayA, arrayB have the different element on ith position, carry is 'I'
      // result the 'O', carry becomes 'I'
    } else if (arrayA[i] != arrayB[i] && carry == 'I') {
      arrayA[i] = 'O';
      carry = 'I';

      // Both arrayA and arrayB have 'O' on ith position, carry is 'O',
      // result the 'O', carry stays the same
    } else if (arrayA[i] == 'O' && arrayB[i] == 'O' && carry == 'O') {
      arrayA[i] = 'O';
      carry = 'O';
      
      // Both arrayA and arrayB have 'O' on ith position, carry is 'I',
      // result the 'I', carry stays the same
    } else if (arrayA[i] == 'O' && arrayB[i] == 'O' && carry == 'I') {
      arrayA[i] = 'I';
      carry = 'O';

      // Both arrayA and arrayB have 'I' on ith position, carry is 'O',
      // result the 'O', carry becomes 'I'
    } else if (arrayA[i] == 'I' && arrayB[i] == 'I' && carry == 'O') {
      arrayA[i] = 'O';
      carry = 'I';

      // Both arrayA and arrayB have 'I' on ith position, carry is 'I',
      // result the 'I', carry becomes 'I'
    } else if (arrayA[i] == 'I' && arrayB[i] == 'I' && carry == 'I') {
      arrayA[i] = 'I';
      carry = 'I';
    }
  }
}

int main() {
  char accumA[SIZE];
  char accumB[SIZE];
  char element;
  ifstream inFile1;
  ifstream inFile2;

  // Initialize accumA and accumB
  intialize_array(accumA);
  intialize_array(accumB);

  // Output the content of the array
  displayArray(accumA);
  displayArray(accumB);
  cout << endl;

  inFile1.open(FILE1);    // code.txt
  inFile2.open(FILE2);    // memory.txt
  
  while (inFile1 >> element && element != 'S') {
    // If 'a' is read, reads 8 chars from memory.txt and stores it in accumA
    if (element == 'a') {
      for (int i = 0; i < SIZE; i++) {
        inFile2 >> accumA[i];
      }
      cout << "char: " << element << endl;
      displayArray(accumA);
      displayArray(accumB);
      cout << endl;
    }

    // If 'a' is read, reads 8 chars from memory.txt and stores it in accumB
    if (element == 'b') {
      for (int i = 0; i < SIZE; i++) {
        inFile2 >> accumB[i];
      }
      cout << "char: " << element << endl;
      displayArray(accumA);
      displayArray(accumB);
      cout << endl;
    }

    // If 'L' is read, shift accumA to the left and stores an 'O' in accumA[7]
    if (element == 'L') {
      shift_left(accumA);
      accumA[7] = 'O';
      cout << "char: " << element << endl;
      displayArray(accumA);
      displayArray(accumB);
      cout << endl;
    }

    // If 'R' is read, shift accumA to the right and stores an 'O' in accumA[0]
    if (element == 'R') {
      shift_right(accumA);
      accumA[0] = 'O';
      cout << "char: " << element << endl;
      displayArray(accumA);
      displayArray(accumB);
      cout << endl;
    }

    // If 'A' is read, shift accumA to the right and no change on elements
    if (element == 'A') {
      shift_right(accumA);
      cout << "char: " << element << endl;
      displayArray(accumA);
      displayArray(accumB);
      cout << endl;
    }

    // If 'C' is read, converts 'O' in accumA in to 'I', and 'I' into 'O'
    if (element == 'C') {
      convert(accumA);
      cout << "char: " << element << endl;
      displayArray(accumA);
      displayArray(accumB);
      cout << endl;
    }

    // If 'P' is read, plus accumA and accumB with bit by bit logic and store
    // the result in accumA
    if (element == 'P') {
      bit_add(accumA, accumB);
      cout << "char: " << element << endl;
      displayArray(accumA);
      displayArray(accumB);
      cout << endl;
    }
  }

  inFile1.close();
  inFile2.close();
  
  return 0;
}