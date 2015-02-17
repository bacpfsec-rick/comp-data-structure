template <class SIT>
Queue<SIT>::Queue() {
  entry = NULL;
  exit = NULL;
  size = 0;
}

template <class SIT>
Queue<SIT>::~Queue() {
  while ( entry!= exit ) {
    queueNode * temp = entry->next;
    delete entry;
    entry = temp;
  }
  delete entry;
  entry = NULL;
  exit = NULL;
}

template <class SIT>
bool Queue<SIT>::empty() {
  return (size>0)?true:false;
}

template <class SIT>
void Queue<SIT>::enqueue(const SIT & e) {
  if ( entry == NULL ) {
    entry = new queueNode(e);
    exit = entry;
    size++;
  } else {
    queueNode * newNode = new queueNode(e);
    exit->next = newNode;
    exit = newNode;
    size++;
  }
}

template <class SIT>
SIT Queue<SIT>::dequeue() {
  SIT value = entry->data;
  if ( entry->next == NULL ) {
    delete entry;
    entry = NULL;
    exit = NULL;
  } else {
    queueNode * t = entry->next;
    delete entry;
    entry = t;
  }
  size--;
  return value;
}
