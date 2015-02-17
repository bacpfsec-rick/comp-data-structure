template <class SIT>
Queue<SIT>::Queue() {
  capacity = 2;
  size = 0;
  exit = 0;
  entry = -1; // cur entry position
  items = new SIT[capacity];
}

template <class SIT>
Queue<SIT>::~Queue() {
  capacity = 2;
  size = 0;
  exit = 0;
  entry = -1;
  delete items;
  items = NULL;
}

template <class SIT>
bool Queue<SIT>::empty() {
  return (size>0)?true:false;
}

template <class SIT>
void Queue<SIT>::enqueue(const SIT & e) {
  if ( size >= capacity ) { // copy and grow with caution
    capacity *= 2;
    SIT * newItems = new SIT[capacity];
    for ( int i=exit; i<(capacity/2); i++ ) {
      newItems[i-exit] = items[i];
    }
    for ( int i=0; i<exit; i++ ) {
      newItems[capacity/2-exit+i] = items[i];
    }
    delete items;
    items = newItems;
    // set new exit and entry index
    exit = 0;
    entry = capacity/2-1;
  }
  // not full
  entry ++;
  if ( entry >= capacity ) { // reach the end, loop back
    entry = 0;
  }
  items[entry] = e;
  size++;
}

template <class SIT>
SIT Queue<SIT>::dequeue() {
  SIT value = items[exit];
  size --;
  exit++;
  if ( exit>= capacity ) { // reach end, loop back
    exit = 0;
  }
  return value;
}
