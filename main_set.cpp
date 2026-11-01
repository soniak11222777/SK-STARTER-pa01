// This file should implement the game using the std::set container class
// Do not include card_list.h in this file
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include "card.h"

using namespace std;
set<Card> Alice;
set<Card> Bob;

void AliceTurn(){
for (const Card& eachA : Alice){
auto it = Bob.find(eachA);
  if (it != Bob.end()){
      cout << "Alice picked matching card " << eachA;
      Alice.erase(eachA);
      Bob.erase(it);
      return;
  }
}
//return false;
}
    
void BobTurn(){
for (set<Card>::const_reverse_iterator rit = Bob.rbegin(); rit != Bob.rend(); ++rit){
auto it = Alice.find(*rit);
  if (it != Alice.end()){
      cout << "Bob picked matching card " << *rit;
    Bob.erase(*rit);
    Alice.erase(it);
    return;
  }
  }
  //return false;
}     


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



for (int i = 0; i < Alice.size(); i++) {
AliceTurn();
BobTurn();
} 


cout<< "Alice's cards: "<< endl;

for (Card each: Alice){
cout<< each; 
}

cout<< "Bobs's cards: "<< endl;
for (Card each: Bob){
cout<< each; 
}

  return 0;
}