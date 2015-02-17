#include <iostream>
#include <stdio.h>
using namespace std;

template <class T>
class listNode {
public:
  T data;
  listNode * next;
  listNode(T newData) : data(newData), next(NULL) {}
};

template <class T>
void insertAtFront(listNode<T> * & head, T newData) {
  listNode<T> * newHead = new listNode<T>(newData);
  newHead->next = head;
  head = newHead;
}

template <class T>
void freeAll(listNode<T> * & head) {
  while ( head != NULL ) {
    listNode<T> * next = head->next;
    delete head;
    head = next;
  }
}

template <class T>
void printReverse(listNode<T> * curr) {
  if ( curr!=NULL ) {
    printReverse(curr->next);
    cout<<curr->data<<'\t';
  }
}

template <class T>
listNode<T> * findKth(listNode<T> * curr, int k) {
  if ( k==0 || curr == NULL ) {
    return curr;
  } else {
    return findKth(curr->next,k-1);
  }
}