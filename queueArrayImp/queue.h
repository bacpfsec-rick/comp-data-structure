#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

template <class SIT>
class Queue {
 public: 
  Queue();
  ~Queue();
  bool empty();
  void enqueue(const SIT & e);
  SIT dequeue();
 private:
  int capacity;
  int size;
  SIT * items;
  int entry; // Hack for queue
  int exit; // Hack for queue
};

#include "queue.cc"
#endif
