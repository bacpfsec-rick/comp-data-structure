// unknown error: listNode does not name a type
/*
template <class LIT>
listNode * list<LIT>::Find(listNode * place, int k) {
  if ( k==0 || place == NULL ) {
    return place;
  } else {
    return Find(place->next,k-1);
  }
}
*/

// O(1) method with value shift
template <class LIT>
void List<LIT>::removeCurrent(listNode * curr) {
  if ( curr!= NULL ) {
    if ( curr->next != NULL ) {
      curr->data = curr->next->data;
      listNode * temp = curr->next;
      curr->next = temp->next;
      delete temp;
    } else { // tail
      delete curr;
      curr = NULL;
    }
  }
  // do nothing if curr == NULL
}

// constructors and deconstructor for List
template <class LIT>
List<LIT>::List() {
  size = 0;
  head = new listNode; // sentinel
}

template <class LIT>
List<LIT>::~List() {
  listNode * curr = head;
  listNode * next;
  while ( curr!=NULL ) {
    next = curr->next;
    delete curr;
    curr = next;
  }
}

template <class LIT>
int List<LIT>::getSize() const{
  return size;
}

template <class LIT>
void List<LIT>::insert(int loc, LIT e) {
  listNode * t = Find(head,loc-1);
  listNode * newNode = new listNode(e);
  newNode->next = t->next;
  t->next = newNode;
  size ++;
}

template <class LIT>
void List<LIT>::remove(int loc) {
  listNode * locNode = Find(head,loc);
  removeCurrent(locNode);
  size --;
}

template <class LIT>
LIT const & List<LIT>::getItem(int loc) {
  listNode * locNode = Find(head,loc);
  return locNode->data;
}

template <class LIT>
void List<LIT>::print(listNode * curr) const{
  if ( curr == head ) {
    print(curr->next);
  } else if ( curr!= NULL ) {
    cout<<curr->data<<'\t';
    print(curr->next);
  }
}

template <class LIT>
void List<LIT>::print() const{
  print(head);
  cout<<endl;
}
