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
  int capacity;
  int size;
  SIT * items;
};

#include "stack.cc"
#endif