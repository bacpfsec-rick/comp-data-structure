#include <iostream>
#include <stdio.h>
#include "list.h"
using namespace std;

int main()
{
  List<int> il;
  il.insert(1,5);
  il.insert(2,3);
  il.insert(2,4);
  il.print(); // 5 4 3
  il.remove(2);
  il.print(); // 5 3
  cout<<il.getItem(2)<<endl; // 3
  return 0;
}
