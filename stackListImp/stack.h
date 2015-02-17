#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

template <class SIT>
class Stack {
 public: 
  Stack();
  ~Stack();
  bool empty();
  void push(const SIT & e);
  SIT pop();
 private:
  struct stackNode {
    stackNode() : next(NULL) {}
    stackNode(SIT e) : data(e), next(NULL) {}
    SIT data;
    stackNode * next;
  };
  stackNode * top;
  int size;
};

#include "stack.cc"
#endif