template <class SIT>
Stack<SIT>::Stack() {
  top = new stackNode();
  size = 0;
}

template <class SIT>
Stack<SIT>::~Stack() {
  while ( top!= NULL ) {
    stackNode * temp = top->next;
    delete top;
    top = temp;
  }
}

template <class SIT>
bool Stack<SIT>::empty() {
  return (size>0)?true:false;
}

template <class SIT>
void Stack<SIT>::push(const SIT & e) {
  stackNode * newNode = new stackNode(e);
  newNode->next = top;
  top = newNode;
  size++;
}

template <class SIT>
SIT Stack<SIT>::pop() {
  stackNode * t = top;
  SIT value = t->data;
  top = t->next;
  delete t;
  size--;
  return value;
}
