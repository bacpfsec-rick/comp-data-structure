#include <iostream>
#include <stdio.h>
#include "queue.h"
using namespace std;

int main()
{
  Queue<int> q;
  cout<<q.empty()<<endl; // 0
  q.enqueue(1);
  q.enqueue(2);
  cout<<"Dequeue: "<<q.dequeue()<<endl; // 1
  cout<<"Dequeue: "<<q.dequeue()<<endl; // 2
  q.enqueue(6);
  q.enqueue(5); // 6 5
  q.enqueue(4); // 6 5 4 *
  q.enqueue(3); // 6 5 4 3
  q.enqueue(2); // 6 5 4 3 2 * * * *
  q.enqueue(1); // size increased: 6 5 4 3 2 1 * *
  cout<<"Dequeue: "<<q.dequeue()<<endl; // 6, the array is * 5 4 3 2 1 * *
  cout<<"Dequeue: "<<q.dequeue()<<endl; // 5,
  cout<<"Dequeue: "<<q.dequeue()<<endl; // 4, the array is * * * 3 2 1 * *
  cout<<"Dequeue: "<<q.dequeue()<<endl;
  cout<<"Dequeue: "<<q.dequeue()<<endl;
  cout<<"Dequeue: "<<q.dequeue()<<endl;
  q.enqueue(8);
  q.enqueue(7);
  q.enqueue(6);
  q.enqueue(5);
  q.enqueue(4);
  q.enqueue(3);
  q.enqueue(2);
  q.enqueue(1);
  cout<<"Dequeue: "<<q.dequeue()<<endl;
  cout<<"Dequeue: "<<q.dequeue()<<endl;
  cout<<"Dequeue: "<<q.dequeue()<<endl;
  cout<<"Dequeue: "<<q.dequeue()<<endl;
  cout<<"Dequeue: "<<q.dequeue()<<endl;
  cout<<"Dequeue: "<<q.dequeue()<<endl;
  cout<<"Dequeue: "<<q.dequeue()<<endl;
  cout<<"Dequeue: "<<q.dequeue()<<endl;
  /*
  q.enqueue(8);
  q.enqueue(7);
  q.enqueue(6);
  q.enqueue(5);
  q.enqueue(4);
  q.enqueue(3);
  q.enqueue(2);
  q.enqueue(1);
  cout<<"Dequeue: "<<q.dequeue()<<endl;
  cout<<"Dequeue: "<<q.dequeue()<<endl;
  cout<<"Dequeue: "<<q.dequeue()<<endl;
  cout<<"Dequeue: "<<q.dequeue()<<endl;
  cout<<"Dequeue: "<<q.dequeue()<<endl;
  cout<<"Dequeue: "<<q.dequeue()<<endl;
  cout<<"Dequeue: "<<q.dequeue()<<endl;
  cout<<"Dequeue: "<<q.dequeue()<<endl;
  */
  cout<<q.empty()<<endl; // 0
  return 0;
}
