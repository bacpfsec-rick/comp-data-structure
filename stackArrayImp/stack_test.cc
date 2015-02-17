#include <iostream>
#include <stdio.h>
#include "stack.h"
using namespace std;

int main()
{
  Stack<int> s;
  cout<<s.empty()<<endl; // 0
  s.push(5);
  s.push(4);
  s.push(3);
  s.push(2);
  s.push(1);
  cout<<"Pop current top: "<<s.pop()<<endl; // 1
  cout<<"Pop current top: "<<s.pop()<<endl; // 2
  cout<<"Pop current top: "<<s.pop()<<endl; // 3
  cout<<"Pop current top: "<<s.pop()<<endl; // 4
  cout<<"Pop current top: "<<s.pop()<<endl; // 5
  cout<<s.empty()<<endl; // 0
  return 0;
}
