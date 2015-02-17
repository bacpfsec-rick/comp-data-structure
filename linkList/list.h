#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;

template <class LIT>
class List{
 public:
  List();
  ~List();
  int getSize() const;
  void insert(int loc, LIT e);
  void remove(int loc);
  LIT const &  getItem(int loc);
  void print() const;

 private:
  struct listNode{
  public:
    LIT data;
    listNode * next;
    listNode(LIT newData) : data(newData), next(NULL) {}
    listNode() : next(NULL) {}
  };
  listNode * head;
  int size;
  listNode * Find(listNode * place, int k) {
    if ( k==0 || place == NULL ) {
      return place;
    } else {
      return Find(place->next,k-1);
    }
    }; // helper
  void removeCurrent(listNode * curr); // helper
  void print(listNode * curr) const; // helper
};

#include "list.cc"
#endif

