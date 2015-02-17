#include <iostream>
#include <stdio.h>
#include "queue.h"
using namespace std;

int main()
{
  Queue<int> q;
  cout<<q.empty()<<endl; // 0
  q.enqueue(5);
  q.enqueue(4);
  q.enqueue(3);
  cout<<"Pop current top: "<<q.dequeue()<<endl; // 5
  cout<<"Pop current top: "<<q.dequeue()<<endl; // 4
  cout<<"Pop current top: "<<q.dequeue()<<endl; // 3
  cout<<q.empty()<<endl; // 0
  return 0;
}
