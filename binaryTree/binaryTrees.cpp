#include<iostream>
#include<string>
#include<queue>
#include"binaryTrees.h"
#include "printtree.h"

using namespace std;

/**
 * An exploration of trees, binary trees, and sorted binary trees
 * 
 */
BinaryTree::BinaryTree() {
  root = NULL;
}

BinaryTree::~BinaryTree() {
  deleteNode(root);
  delete root;
  root = NULL;

}

//--------------------------------------//
//-------------- MUTATORS --------------//
//--------------------------------------//

// client for insertion
void BinaryTree::insert(int value) {
  insertHelper(value, root);
}

// helper for insertion
void BinaryTree::insertHelper(int value, Node* curr) {
  if(!curr)         root = new Node(value);
  else if(value > curr->value) {
    if(curr->right) return insertHelper(value, curr->right);
    else            curr->right = new Node(value);
  }
  else if(value < curr->value) {
    if(curr->left) return insertHelper(value, curr->left);
    else           curr->left  = new Node(value);
  } else { // value = curr->value
    return; // don't need to do anything
  }
}

bool BinaryTree::remove(int value) {

  if(!root) return false;

  Node* parent       = NULL;
  Node* nodeToRemove = root;
  Node* leftSubtree;
  Node* rightSubtree;
  bool isLeftChild   = true;

  // get node to remove and the parent
  while(nodeToRemove->value != value) {
    if(nodeToRemove == NULL)
      return false; // quit if node does not exist
    if(value < nodeToRemove->value) {
      parent       = nodeToRemove;
      nodeToRemove = nodeToRemove->left;
      isLeftChild  = true;
    } else { // value > nodeToRemove->value
      parent       = nodeToRemove;
      nodeToRemove = nodeToRemove->right;
      isLeftChild  = false;
    }
  }

  // get left and right subtree
  leftSubtree  = nodeToRemove->left;
  rightSubtree = nodeToRemove->right;
  Node* successor      = rightSubtree;

  if(rightSubtree) {

    // get successor
    Node* successorParent = nodeToRemove;
    while(successor->left) {
      successorParent  = successor;
      successor        = successor->left;
    }
    successorParent->left = successor->right;

    // switch successor
    successor->left    = leftSubtree;
    if(successorParent != nodeToRemove)
      successor->right = rightSubtree;

  } else { // !rightSubtree

    successor = leftSubtree;

  }

  // switch parent
  if(!parent) {
    root = successor;
  } else if(isLeftChild) {
    parent->left  = successor;
  } else { // is right child
    parent->right = successor;
  }

  delete nodeToRemove;
  return true;
}

bool BinaryTree::rotateLeft(int value) {

  if(!root) return false;

  Node* parent       = NULL;
  Node* nodeToRotate = root; // is the predecessor
  Node* successor = NULL;
  Node* mover = NULL;
  bool isLeftChild   = true;

  // get node to remove and the parent
  while(nodeToRotate->value != value) {
    if(nodeToRotate == NULL)
      return false; // quit if node does not exist
    if(value < nodeToRotate->value) {
      parent       = nodeToRotate;
      nodeToRotate = nodeToRotate->left;
      isLeftChild  = true;
    } else { // value > nodeToRotate->value
      parent       = nodeToRotate;
      nodeToRotate = nodeToRotate->right;
      isLeftChild  = false;
    }
  }

  successor = nodeToRotate->right;

  if(!successor) return true;

  // get/switch mover
  mover = successor->left;
  nodeToRotate->right = mover;
  successor->left = nodeToRotate;

  // switch parent
  if(!parent) {
    root = successor;
  } else if(isLeftChild) { // parent
    parent->left = successor;
  } else { // !isLeftChild
    parent->right = successor;
  }

  return true;
}

bool BinaryTree::rotateRight(int value) {

  if(!root) return false;

  Node* parent       = NULL;
  Node* nodeToRotate = root; // is the predecessor
  Node* successor = NULL;
  Node* mover = NULL;
  bool isLeftChild   = true;

  // get node to remove and the parent
  while(nodeToRotate->value != value) {
    if(nodeToRotate == NULL)
      return false; // quit if node does not exist
    if(value < nodeToRotate->value) {
      parent       = nodeToRotate;
      nodeToRotate = nodeToRotate->left;
      isLeftChild  = true;
    } else { // value > nodeToRotate->value
      parent       = nodeToRotate;
      nodeToRotate = nodeToRotate->right;
      isLeftChild  = false;
    }
  }

  successor = nodeToRotate->left;

  if(!successor) return true;

  // get/switch mover
  mover = successor->right;
  nodeToRotate->left = mover;
  successor->right = nodeToRotate;

  // switch parent
  if(!parent) {
    root = successor;
  } else if(isLeftChild) { // parent
    parent->left = successor;
  } else { // !isLeftChild
    parent->right = successor;
  }

  return true;
}

/*void BinaryTree::rotateHelper(int value, Node* curr) {
  // stub
}*/

//---------------------------------------//
//-------------- ACCESSORS --------------//
//---------------------------------------//

// client for pre-order print
void BinaryTree::preOrderPrint() {
  std::cout << "pre order:   ";
  preOrderPrintHelper(root);
  std::cout << std::endl;
}

// helper for pre-order print
void BinaryTree::preOrderPrintHelper(Node* curr) {
  if(!curr) return;
  else {
    std::cout << curr->value << " ";
    preOrderPrintHelper(curr->left);
    preOrderPrintHelper(curr->right);
  }
}

// client for in-order print
void BinaryTree::inOrderPrint() {
  std::cout << "in order:    ";
  inOrderPrintHelper(root);
  std::cout << std::endl;
}

// helper for in-order print
void BinaryTree::inOrderPrintHelper(Node* curr) {
  if(!curr) return;
  else {
    preOrderPrintHelper(curr->left);
    std::cout << curr->value << " ";
    preOrderPrintHelper(curr->right);
  }
}

// client for post-order print
void BinaryTree::postOrderPrint() {
  std::cout << "post order:  ";
  postOrderPrintHelper(root);
  std::cout << std::endl;
}

// helper for post-order print
void BinaryTree::postOrderPrintHelper(Node* curr) {
  if(!curr) return;
  else {
    preOrderPrintHelper(curr->left);
    preOrderPrintHelper(curr->right);
    std::cout << curr->value << " ";
  }
}

void BinaryTree::levelOrderPrint() {
  std::cout << "level order: ";
  levelOrderPrintHelper(root);
  std::cout << std::endl;
}

void BinaryTree::levelOrderPrintHelper(Node* root) {
  queue<Node*> traverseLst;

  traverseLst.push(root); // init

  while(!traverseLst.empty()) {
    Node* curr = traverseLst.front();
    traverseLst.pop();

    cout << curr->value << " ";

    if(curr->left != NULL)  traverseLst.push(curr->left);
    if(curr->right != NULL) traverseLst.push(curr->right);
  }
}

// client for getting height (0-based)
int BinaryTree::getHeight() {
  return getHeightHelper(root);
}

// helper for getting height (0-based)
int BinaryTree::getHeightHelper(Node* curr) {
  if(curr) {
    int ret1 = getHeightHelper(curr->left);
    int ret2 = getHeightHelper(curr->right);
    return 1 + max(ret1, ret2);
  }
  else return -1;
}


int BinaryTree::getSize() {
  return getSizeHelper(root);
}

int BinaryTree::getSizeHelper(Node* curr) {
  if(curr) {
    return getSizeHelper(curr->left) 
         + getSizeHelper(curr->right)
         + 1;
  } else return 0;
}

int BinaryTree::getMin() {
  if(empty()) return 0; // trivial
}

int BinaryTree::getMax() {
  if(empty()) return 0; // trivial
}

bool BinaryTree::hasValue(int value) {
  if(empty()) return false; // trivial
}

bool BinaryTree::empty() {
  return root == NULL;
}

// because of the way insertion is designed, the tree is always ordered BST.

// client : is ordered?
bool BinaryTree::isOrdered() {
  if(empty()) return true; // trivial

  return isOrderedHelper(root, MIN, MAX);
}

// helper : is ordered?
bool BinaryTree::isOrderedHelper(Node* curr, int minVal, int maxVal) {
  if(curr == NULL) return true;
  else return
    minVal <= curr->value &&
    curr->value <= maxVal &&
    isOrderedHelper(curr->left, minVal, curr->value) &&
    isOrderedHelper(curr->right, curr->value, maxVal);
}

//---------------------------------------//
//---------SPECIAL PRINT METHOD----------//
//---------------------------------------//

// This is a template so we can declare it outside of the .h file - we don't
// need to actually see the BinaryTree<T>::Node class
template <typename Node>
class BinaryTreeNodeDescriptor
    : public GenericNodeDescriptor<BinaryTreeNodeDescriptor<Node>> {
  public:
    BinaryTreeNodeDescriptor(const Node* node_ptr) : node(node_ptr) {
    }

    bool isNull() const {
        return node == NULL;
    }

    string key() const {
        std::stringstream ss;
        //ss << node->elem;
        ss << node->value;
        return ss.str();
    }

    BinaryTreeNodeDescriptor left() const {
        return BinaryTreeNodeDescriptor(node->left);
    }

    BinaryTreeNodeDescriptor right() const {
        return BinaryTreeNodeDescriptor(node->right);
    }

  private:
    const Node* node;

};

void BinaryTree::print() const {
    printTree(BinaryTreeNodeDescriptor<Node>(root));

}