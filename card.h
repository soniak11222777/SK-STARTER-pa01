// card.h
// Author: Sonia Kumar
// All class declarations related to defining a single card go here

#ifndef CARD_H
#define CARD_H

#include <iostream>

using namespace std;
class Card {

public:
char suit;
string value; 

Card(char s = '\0', string v  = " ");
~Card();

bool operator==(const Card& f) const; 
bool operator!=(const Card& f) const; 
bool operator<(const Card& f) const;
bool operator>(const Card& f) const;


private: 
int suithelper(char s) const;
int valuehelper(string v) const;

};

ostream& operator<<(ostream &out, const Card& c);

#endif