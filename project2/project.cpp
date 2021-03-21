/**
 * Project2
 *
 * Copyright (c) [2021], Zhao Liu.
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <bitset>

const int SIZE_DATA = 6;
const int SIZE_CODE = 16;
const std::string SRC_FILE = "assemblycode.txt";
const std::string OBJ_FILE = "object.txt";
const int Afrom_binary = 8;
const int Bfrom_binary = 9;
const int Comp_binary = 0;
const int Add_binary = 0;
const int Ato_binary = 4;
const int JNZ_binary = 2;

int main() {
  std::ifstream inFile;
  std::ofstream outFile;
  std::string word;
  std::string byte[SIZE_DATA];
  std::string data_symbol[SIZE_DATA];
  std::string code_symbol[SIZE_CODE];
  int data_addr[SIZE_DATA];
  int data_val[SIZE_DATA];
  int code_addr[SIZE_CODE];
  int loop_addr = 0;

  inFile.open(SRC_FILE);    // assemblycode.txt
  outFile.open(OBJ_FILE);   // object.txt 

  // First time reading
  while (inFile >> word) {
    // If "data" is found
    if (word == "data") {
      for (int i = 0; i < SIZE_DATA; ++i) {
        inFile >> byte[i] >> data_symbol[i] >> data_val[i];
        data_addr[i] = i;
      }
    }

    // If "code" is found
    if (word == "code") {
      inFile >> word;
      for (int i = 0; i < SIZE_CODE; ++i) {
        for (int j = 0; j < SIZE_DATA; ++j) {
          if (word == data_symbol[j]) {
            inFile >> word;
            break;
          }
        }
        if (word == "loop:") {
          loop_addr = i;
          inFile >> word;
        }
        if (word == "loop") {
          inFile >> word;
        }
        code_symbol[i] = word;
        code_addr[i] = i;
        inFile >> word;
      }
    }
  }

  inFile.close();

  inFile.open(SRC_FILE);

  std::cout << "Address\tContent\ndata" << std::endl;
  for (int i = 0; i < SIZE_DATA; ++i) {
    std::cout << std::bitset<4>(data_addr[i]) << "\t"
              << std::bitset<8>(data_val[i]) << std::endl;
  }
  std::cout << "code\n";

  // Second time reading
  while (inFile >> word) {
    // If "code" is found
    if (word == "code") {
      for (int i = 0; i < SIZE_CODE; ++i) {
        inFile >> word;  
        if (word == "loop:") {
          inFile >> word;
          std::cout << std::bitset<4>(code_addr[loop_addr]) << "\t";
          std::cout << std::bitset<4>(Afrom_binary) << "\t";
          inFile >> word;
          std::cout << "\n";
        } else {
          std::cout << std::bitset<4>(code_addr[i]) << "\t";
          if (word == "Afrom") {
            std::cout << std::bitset<4>(Afrom_binary);
            inFile >> word;
          } else if (word == "Bfrom") {
            std::cout << std::bitset<4>(Bfrom_binary);
            inFile >> word;
          } else if (word == "Comp") {
            std::cout << std::bitset<8>(Comp_binary) << std::endl;
          } else if (word == "Add") {
            std::cout << std::bitset<8>(Add_binary) << std::endl;
          } else if (word == "Ato") {
            std::cout << std::bitset<4>(Ato_binary);
            inFile >> word;
          } else if (word == "JNZ") {
            std::cout << std::bitset<4>(JNZ_binary);
            std::cout << std::bitset<4>(code_addr[loop_addr]) << std::endl;
            inFile >> word;
          } else if (word == "loop") {
            std::cout << std::bitset<4>(code_addr[loop_addr]);
            inFile >> word;
          }
  
          for (int j = 0; j < SIZE_DATA; ++j) {
            if (word == data_symbol[j]) {
              std::cout << std::bitset<4>(data_addr[j]) << std::endl;
            }
          }
        }
      }
    }
  }

  inFile.close();
  return 0;
}