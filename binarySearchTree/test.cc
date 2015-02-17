#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
using namespace std;

int main() {
  Dictionary<int,string> isDic;
  isDic.insert(1,"S1");
  isDic.insert(3,"S2");
  cout<<isDic.find(3)<<endl;
  isDic.remove(2);
  isDic.remove(1);
  cout<<isDic.find(3)<<endl;


  return 0;
}
