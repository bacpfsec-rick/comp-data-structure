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
  struct queueNode {
    queueNode() : next(NULL) {}
    queueNode(SIT e) : data(e), next(NULL) {}
    SIT data;
    queueNode * next;
  };
  queueNode * entry;
  queueNode * exit;
  int size;
};

#include "queue.cc"
#endif
