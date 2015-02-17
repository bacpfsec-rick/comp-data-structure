#include <iostream>
#include <stdio.h>
#include "listNode.cc"
using namespace std;

int main()
{
  listNode<int> * head = new listNode<int>(5);
  cout<<"head->data: "<<head->data<<endl;
  cout<<"Insert a new head with value 55:"<<endl;
  insertAtFront(head,55);
  cout<<"head->data: "<<head->data<<endl;
  cout<<"Clear all current data:"<<endl;
  freeAll(head);
  cout<<"Create a list with value 1~10:"<<endl;
  for ( int i=10; i>0; i-- ) {
    insertAtFront(head,i);
  }
  cout<<"Current head: "<<endl;
  cout<<"head->data: "<<head->data<<endl;
  cout<<"Print the list in reverse order: "<<endl;
  printReverse(head);
  cout<<endl;
  cout<<"Get the 5th data: "<<endl;
  cout<<findKth(head,4)->data<<endl;
  freeAll(head);
  return 0;
}
