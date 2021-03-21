/**
 * Project 2
 *
 * Copyright (c) [2021], Zhao Liu.
 */

#include <iostream>
#include <bitset>
#include <fstream>
#include <string>
using namespace std;

int main() {
  ifstream inFile;
  string cmd;
  int num;
  int symbAddr = 0;
  int memAddr[32] = {0};
  int value[32] = {0};
  string cmdSymb[32] = {" "};

  // Open file assemblycode.txt
  inFile.open("assemblycode.txt");

  inFile >> cmd;  // data read
  inFile >> cmd;  // byte read
  while (cmd != "code") {
    memAddr[symbAddr] = symbAddr;   // symbol memory address starts from 0   
    inFile >> cmd;                  // mulcand read
    cmdSymb[symbAddr] = cmd;        // store command into command symbol array
    inFile >> num;                  // 4 read
    value[symbAddr] = num;          // store number value into value array
    symbAddr++;                     // increase counter symbAddr by 1
  }

  for (int i = 0; i < 6; ++i) {
    cout << memAddr[i] << " " << 
  }
  return 0;
}