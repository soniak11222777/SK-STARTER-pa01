#include "card.h"
#include "card_list.h"
#include <iostream>
#include <cassert>
using namespace std;


void TestBST(){

CardBST bstO;

Card t('h', "j");
Card a('s', "5");
Card b('c', "9");
Card c('d', "a");
Card d('s', "2");

assert(bstO.contains(t) == false);
assert(bstO.insert(t) == true);
assert(bstO.count() == 1);
assert(bstO.insert(t) == false);


bstO.insert(a);
bstO.insert(b);
bstO.insert(c);
assert(bstO.remove(a) == true);

assert(bstO.contains(a) == false);
assert(bstO.remove(d) != true);

cout << "BST functions tested" << endl;
}


void TestBSTIterators(){

CardBST bstO;

Card t('h', "j");
Card a('s', "5");
Card b('c', "9");
Card c('d', "a");
Card d('h', "k");
Card e('c', "7");

assert (bstO.begin() == bstO.end());
assert (bstO.rbegin() == bstO.rend());

bstO.insert(c);


for (auto it = bstO.begin(); it != bstO.end(); ++it) {
    cout << *it; 
}
cout<< "single node traversed" << endl;

bstO.insert(a);
bstO.insert(b);
bstO.insert(d);
bstO.insert(e);

for (auto it = bstO.begin(); it != bstO.end(); ++it) {
    cout << *it; 
}
cout<< "multiple nodes forward traversed" <<endl;

for (auto it = bstO.rbegin(); it != bstO.rend(); --it) {
    cout << *it << endl; 
}
cout<< "multiple nodes backward traversed";

auto it = bstO.end();
++it;
assert(it ==bstO.end());

auto rit = bstO.rend();
--rit;
assert(rit ==bstO.rend());

auto itA = bstO.begin();
auto itB = bstO.begin();
assert(itA ==itB);
++itA;
assert(itA !=itB);


cout << "Iterator functions tested" << endl;
}


void TestPlayGame(){

CardBST bstA;
CardBST bstB;

Card a('s', "2");

bstB.insert(a);
playGame(bstA, bstB);
assert(bstB.contains(a)==true);


bstB.insert(Card('c', "5"));
bstB.insert(Card('h', "4"));
bstB.insert(Card('d', "q"));

bstA.insert(Card('h', "j"));
bstA.insert(Card('d', "q"));
bstA.insert(Card('s', "9"));;
bstA.insert(Card('c', "3"));

playGame(bstA, bstB);
assert(bstA.count()==3);
assert(bstB.count()==3);


CardBST oBST;
CardBST tBST;

oBST.insert(Card('s', "2"));
oBST.insert(Card('c', "5"));
oBST.insert(Card('h', "4"));


tBST.insert(Card('h', "j"));
tBST.insert(Card('s', "9"));;
tBST.insert(Card('c', "3"));


playGame(oBST, tBST);
assert(bstA.count()==3);
assert(bstB.count()==3);
cout << "PlayGame conditions tested" << endl;
}

int main() {
TestBST();
TestBSTIterators();
TestPlayGame();
cout << "All functions tested"<< endl;

}
