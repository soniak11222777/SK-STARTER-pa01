// card_list.h
// Author: Sonia Kumar
// All class declarations related to defining a BST that represents a player's hand

#ifndef CARD_LIST_H
#define CARD_LIST_H

#include <iostream>
#include "card.h"

using namespace std;

class CardBST{

private:
struct Node {
	Card card;
	Node *left, *right, * parent;
    Node(const Card& c) : card(c), left(nullptr), right(nullptr), parent(nullptr) { }
    };

    Node *root;
    Node* getNodeFor(const Card& c, Node*n) const;
    void clear(Node *n); 
    bool insert(const Card& c, Node * &n); 
    Node* getSuccessorNode(Node* r, const Card& c) const;   
    Node* getPredecessorNode(Node* r, const Card& c) const; 
    int count(Node *n) const;
   

public:

    CardBST();
    ~CardBST();
    class BSTiterator {
        friend class CardBST;
        private:
        const CardBST* tree;
        Node* curr;

        public:
        BSTiterator(CardBST* t = nullptr, Node* p = nullptr): tree(t), curr(p) {} 
        bool operator!=(const BSTiterator& rhs) const;
        bool operator==(const BSTiterator& rhs) const;
        Card operator*() const;
        BSTiterator& operator++();
        BSTiterator& operator--();
    };

    bool insert(const Card& c);
    int count() const;   
    bool contains(const Card& c) const; 
    Card getPredecessor(const Card& c) const; 
    Card getSuccessor(const Card& c) const; 
    bool remove(const Card& c);

    BSTiterator begin();
    BSTiterator end();
    BSTiterator rbegin();
    BSTiterator rend();

};
void BobTurn(CardBST& a, CardBST& b);
void AliceTurn(CardBST& a, CardBST& b);
void playGame(CardBST& a, CardBST& b);

#endif