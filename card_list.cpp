// card_list.cpp
// Author: Sonia Kumar
// Implementation of the classes defined in card_list.h

#include "card_list.h"

#include <iostream>
using std::cout;


CardBST::CardBST(){
root = nullptr;
}

CardBST::~CardBST() {
clear(root);
}

void CardBST::clear(Node *n) {
if(n!=nullptr){
clear(n->left);
clear(n->right);
delete n;
}
}

bool CardBST::insert(const Card& c) {
   return insert(c, root);
   cout << endl;
}

bool CardBST::insert(const Card& c, Node* &n) {
    if (n == nullptr){
    n = new Node(c);
    return true;
    }
bool add;
    if(c == n->card){
       // cout << "Rejected duplicate: " << c << std::endl;
            return false;
        } else if(c < n->card){
            add = insert(c, n->left);
            if(n->left != nullptr){
                n->left->parent = n;
            }
            return add;
        } else {
            add = insert(c, n->right);
            if(n->right != nullptr){
                n->right->parent = n;
            }
            return add;
        }
    return true; 
}

int CardBST::count() const {
    return count(root);
}

int CardBST::count(Node *n) const {
if (n!= nullptr){
return 1 + count(n->left) + count(n->right);
 }
return 0;
}


CardBST::Node* CardBST::getNodeFor(const Card& c, Node* n) const{
    if (n==nullptr){
        return nullptr; 
    }
     if (c < n->card){
        return getNodeFor(c, n->left);
    } else if (n->card < c) {
        return getNodeFor(c, n->right);
         } 
          else{
    return n;
    } 
}

bool CardBST::contains(const Card& c) const {
    if (getNodeFor(c, root) != nullptr){
    return true;
  } 
  return false;
}

CardBST::Node* CardBST::getPredecessorNode(Node* r, const Card& c) const {
    /*Node* s = getNodeFor(c, r);
    if (s==nullptr){
    return nullptr;
    }
    if(s->left != nullptr){
        s = s->left;
        while (s->right != nullptr){
            s = s->right;
            }
            return s;
            }

    Node* p = s->parent;
    Node* pred = s;
    
    while ( p != nullptr && pred == pred->left){
    pred = p;
    p = p->parent; 
    }
    return p;*/
    Node* s = getNodeFor(c, r);
if (s==nullptr){
return nullptr;
}
Node* p = s->parent;
Node* pred = nullptr;
if (s->left == nullptr){
   while (p!= nullptr){
       if (p->card < s->card){
           pred = p;
           break;
           }
   p = p->parent;
   }
} else {
   s = s->left;
   while (s->right != nullptr){
       s = s->right;
       }
       pred = s;
       }
      
return pred;
}

Card CardBST::getPredecessor(const Card& c) const{
   if (getPredecessorNode(root, c)!= nullptr){
    return (getPredecessorNode(root, c))->card;
   }
   return 0;
}

CardBST::Node* CardBST::getSuccessorNode(Node* r, const Card& c) const{
    /*if(contains(c) != true){
    return nullptr;
    }*/
  /*Node* s = getNodeFor(c, r);
  if (s==nullptr){
    return nullptr;
}
if(s->right != nullptr){
    s = s->right;
        while (s->left != nullptr){
            s = s->left;
        }
        return s;
        }
  Node* p = s->parent;
  Node* succ = s;
while (p!= nullptr && succ == p->right){
        succ = p;
        p = p->parent;
        }
        return p;  */
 Node* s = getNodeFor(c, r);
 if (s==nullptr){
   return nullptr;
}
 Node* p = s->parent;
 Node* succ = nullptr;


if (s->right == nullptr){
   while (p!= nullptr){
       //cout << p->info << " " << endl;
       if (p->card > s->card){
       succ = p;
       break;
        }
       p = p->parent;
        }
       } else {
           s = s->right;
       while (s->left != nullptr){
           s = s->left;
               }
           succ = s;
           }
       return succ;

    }

Card CardBST::getSuccessor(const Card& c) const{
    if (getSuccessorNode(root, c) != nullptr){
    return (getSuccessorNode(root, c))->card;
   }
   return 0;
}

bool CardBST::remove(const Card& c){
bool del = false;
Node* target = getNodeFor(c, root);
if (target == nullptr){
    return del;
}
Node* par = target->parent;
Node* r = target->right;
Node* l = target->left;

if (contains(c)){
  if (l == nullptr && r == nullptr){
    if (target == root){
        root = nullptr;
    } else if (target == par->right){
        par->right = nullptr;
        } else{
            par->left = nullptr;
            }
            delete target;
       } else if(l != nullptr && r ==nullptr){
         if (target == root){
            root = l;
            l->parent = nullptr;
            delete target;
             } else if (target == par->right){
             par->right = l;
             l->parent = par;
             delete target;
             }else{
                par->left = l;
                l->parent = par;
                delete target;
                }
                } else if(r != nullptr && l == nullptr){
                    if (target == root){
                        root = r;
                        r->parent = nullptr;
                        delete target;
                        } else if (target == par->right){
                        par->right = r;
                        r->parent = par;
                        delete target;
                        } else {
                            par->left = r;
                            r->parent = par;
                            delete target;
                            }
                            } else if (r != nullptr && l != nullptr){
                                Node* succ = getSuccessorNode(root, c);
                                Node* pred = getPredecessorNode(root, c);
                                if (succ!=nullptr){
                               Card sVal = succ->card;
                               target->card = sVal;
                                remove(sVal);
                                } else {
                                Card pVal = pred->card;
                                target->card = pVal;
                                remove(pVal);
                                }
                            }
                                del = true;
                                }
                                return del;
}





bool CardBST::BSTiterator::operator!=(const BSTiterator& rhs) const{
    return curr != rhs.curr;
}

bool CardBST::BSTiterator::operator==(const BSTiterator& rhs) const{
    return curr == rhs.curr;
}


Card CardBST::BSTiterator::operator*() const{
   if (curr==nullptr){
        return Card();
    }
    return curr->card; 
}

CardBST::BSTiterator CardBST::begin(){
   Node* temp = root;
    while(temp != nullptr && temp->left != nullptr){
        temp = temp->left;
    }
    return BSTiterator(this, temp);
}

CardBST::BSTiterator CardBST::end(){
    return BSTiterator(this, nullptr);
}

CardBST::BSTiterator CardBST::rbegin(){
    Node* temp = root;
    while(temp != nullptr && temp->right != nullptr){
        temp = temp->right;
    }
    return BSTiterator(this, temp);
}

CardBST::BSTiterator CardBST::rend(){
    return BSTiterator(this, nullptr);
}

CardBST::BSTiterator& CardBST::BSTiterator::operator++(){
    if (curr==nullptr){
        return *this;
    }
    curr = tree->getSuccessorNode(tree->root, curr->card);
    return *this;
}

CardBST::BSTiterator& CardBST::BSTiterator::operator--(){
    if (curr==nullptr){
        return *this;
    }
    curr = tree->getPredecessorNode(tree->root, curr->card);
    return *this;
}

void AliceTurn(CardBST& a, CardBST& b){
for (auto it = a.begin(); it != a.end(); ++it) {
    Card current = *it;
  if (b.contains(current)){
    cout << "Alice picked matching card " << current;
    a.remove(current);
    b.remove(current);
    return;
  }
}
}

void BobTurn(CardBST& a, CardBST& b){
for (auto rit = b.rbegin(); rit != b.rend(); --rit) {
    Card current = *rit;
  if (a.contains(current)){
    cout << "Bob picked matching card " << current;
    b.remove(current);
    a.remove(current);
    return;
  }
}
}

void playGame(CardBST& a, CardBST& b){
while(a.count()>0 && b.count()>0){ 
int cA = a.count();
int cB = b.count();
AliceTurn(a, b);
BobTurn(a, b);
    if(a.count() == cA && b.count() == cB){
        break;
    }
}
}




 
