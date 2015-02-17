template <class SIT>
Stack<SIT>::Stack() {
  capacity = 2;
  size = 0;
  items = new SIT(capacity);
}

template <class SIT>
Stack<SIT>::~Stack() {
  capacity = 2;
  size = 0;
  delete items;
  items = NULL;
}

template <class SIT>
bool Stack<SIT>::empty() {
  return (size>0)?true:false;
}

template <class SIT>
void Stack<SIT>::push(const SIT & e) {
  if ( size >= capacity ) { // copy and grow
    capacity *= 2;
    SIT * newItems = new SIT[capacity];
    for ( int i=0; i<(capacity/2); i++ ) {
      newItems[i] = items[i];
    }
    delete items;
    items = newItems;
  }
  items[size] = e;
  size++;
}

template <class SIT>
SIT Stack<SIT>::pop() {
  SIT value = items[size-1];
  size --;
  return value;
}