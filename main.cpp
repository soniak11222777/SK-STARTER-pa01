// This file should implement the game using a custom implementation of a BST (based on your earlier BST implementation)
#include <iostream>
#include <fstream>
#include <string>
#include "card.h"
#include "card_list.h"
//Do not include set in this file

using namespace std;


int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  //Read each file
CardBST Alice;
CardBST Bob; 

  while (getline (cardFile1, line) && (line.length() > 0)){
    char o = line[0];
    string val = line.substr(2);
    Alice.insert(Card(o,val));
  }
  cardFile1.close();


  while (getline (cardFile2, line) && (line.length() > 0)){
    char o = line[0];
    string val = line.substr(2);
    Bob.insert(Card(o,val));
  }
  cardFile2.close();


playGame(Alice, Bob);
cout<< endl; 
cout<< "Alice's cards: "<< endl;
for (auto it = Alice.begin(); it != Alice.end(); ++it) {
    cout << *it; 
}
cout<< endl; 
cout<< "Bob's cards: "<< endl;
for (auto it = Bob.begin(); it != Bob.end(); ++it) {
    cout << *it;
}

  
  
  return 0;
}
