// card.cpp
// Author: Your name
// Implementation of the classes defined in card.h

#include "card.h"

#include <iostream>
using std::cout;

Card::Card(char s, string v) : suit(s) , value(v){}


Card::~Card(){}

bool Card::operator==(const Card& f) const{
    if(suit == f.suit && value == f.value){
        return true;
    }
    return false;
}

bool Card::operator!=(const Card& f) const{
    if (suit != f.suit || value != f.value){
        return true;
    }
    return false;
}



int Card::suithelper(char s) const{
switch(s){
case 'h': return 4;
case 's': return 3;
case 'd': return 2;
case 'c': return 1;
default : return 0;
}
}

int Card::valuehelper(string v) const{
if (v == "a") return 1;
if (v == "2") return 2;
if (v == "3") return 3;
if (v == "4") return 4;
if (v == "5") return 5;
if (v == "6") return 6;
if (v == "7") return 7;
if (v == "8") return 8;
if (v == "9") return 9;
if (v == "10") return 10;
if (v == "j") return 11;
if (v == "q") return 12;
if (v == "k") return 13;
return 0;
}



bool Card::operator<(const Card& f) const{
    int s = suithelper(suit);
    int sf = suithelper(f.suit);
    int v = valuehelper(value);
    int vf = valuehelper(f.value);

    if (s != sf){
    return s<sf;
    }
    return v < vf;
}

bool Card::operator>(const Card& f) const{
    int s = suithelper(suit);
    int sf = suithelper(f.suit);
    int v = valuehelper(value);
    int vf = valuehelper(f.value);

    if (s != sf){
    return s>sf;
    }

return v>vf;
}

ostream& operator<<(ostream &out, const Card& c){
    out << c.suit << " " << c.value << endl;
return out;
}




/*
bool operator<<(ostream &out, const Card& c){
out << c.suit " " << c.value << endl;
return out;
}
*/