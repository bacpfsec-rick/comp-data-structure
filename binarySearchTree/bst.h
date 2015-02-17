#ifndef BST_H
#define BST_H
#include <iostream>
using namespace std;

template <class K, class D>
class Dictionary{
 public:
  // constructors
  Dictionary() {
    root = NULL;
  }
 private:
  struct treeNode{
    treeNode(K k, D d) : data(d), key(k) {}
    D data;
    K key;
    treeNode* left;
    treeNode* right;
  };
  treeNode* root;
 public:
  // Find
  D find(const K & key) {
    treeNode * result = find(root,key);
    if (result==NULL) {
      return D();
    } else {
      return result->data;
    }
  }
  treeNode * find(treeNode* cRoot, const K & key) {
    if( cRoot==NULL ) {
      return cRoot;
    } else if ( cRoot->key == key ) {
      return cRoot;
    } else if ( cRoot->key > key ) {
      return find(cRoot->left,key);
    } else {
      return find(cRoot->right,key);
    }
  }

  // Insert
  void insert(const K & key, const D & data) {
    insert(root,key,data);
  }
  void insert(treeNode* &cRoot, const K & key, const D & data) {
    if ( cRoot == NULL ) {
      cRoot = new treeNode(key,data);
    } else if ( cRoot->key == key ) {
      cRoot = new treeNode(key,data);
    } else if ( cRoot->key > key ) {
      insert(cRoot->left,key,data);
    } else {
      insert(cRoot->right,key,data);
    }
  }

  // Remove
  void remove(const K & key) {
    remove(root,key);
  }
  void remove(treeNode* &cRoot, const K & key) {
    if ( cRoot == NULL ) {
      return;
    } else if ( cRoot->key == key ) {
      // this is the tricky part
      doRemoval(cRoot); 
    } else if ( cRoot->key > key ) {
      remove(cRoot->left,key);
    } else {
      remove(cRoot->right,key);
    }
  }

  // doRemoval with comparison
  void doRemoval(treeNode * & cRoot) {
    if ((cRoot->left == NULL) && (cRoot->right == NULL)) {
      noChildRemove(cRoot);
    } else if ((cRoot->left != NULL) && (cRoot->right != NULL)) {
      twoChildRemove(cRoot);
    } else {
      oneChildRemove(cRoot);
    }
  }

  void noChildRemove(treeNode * & cRoot) {
    delete cRoot;
    cRoot = NULL;
  }

  void oneChildRemove(treeNode * & cRoot) {
    treeNode * temp = cRoot;
    if (cRoot->left == NULL) {
      cRoot = cRoot->right;
    } else {
      cRoot = cRoot->left;
    }
    delete temp;
  }

  void twoChildRemove(treeNode * & cRoot) {
    treeNode * &iop = IOP(cRoot); // reference variable
    cRoot->key = iop->key;
    doRemoval(iop);
  }

  // IOP is tricky
  treeNode * & IOP(treeNode * & cRoot) {
    return rightMostChild(cRoot->left);
  }

  treeNode * & rightMostChild(treeNode * & cRoot) {
    if (cRoot->right==NULL) {
      return cRoot;
    } else {
      return rightMostChild(cRoot->right);
    }
  }
};

#endif
