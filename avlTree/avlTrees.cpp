#include<iostream>
#include<string>
#include<queue>
#include"avlTrees.h"
#include "printtree.h"

using namespace std;

/**
 * An exploration of trees, binary trees, and sorted binary trees
 * 
 */
AVLTree::AVLTree() {
  root = NULL;
}

AVLTree::~AVLTree() {
  deleteNode(root);
  delete root;
  root = NULL;

}

//--------------------------------------//
//-------------- MUTATORS --------------//
//--------------------------------------//

// client for insertion
void AVLTree::insert(int value) {
  insertHelper(value, root);
}

// helper for insertion
bool AVLTree::insertHelper(int value, Node*& curr) {
  if(!curr) {
    // trivial case: no root node
    root = new Node(value);
    return true;
  }
  else if(value > curr->value) {
    if(curr->right) {
      if( insertHelper(value, curr->right) ) { // insertion successful
        curr->weight += 1;
        if( rebalance(curr) ) return false;
        else                  return true;
      }
    }
    else {
      curr->right = new Node(value);
      curr->weight += 1;
      if( rebalance(curr) ) return false;
      else                  return true;
    }
  }
  else if(value < curr->value) {
    if(curr->left) {
      if( insertHelper(value, curr->left) ) { // insertion successful
        curr->weight -= 1;
        if( rebalance(curr) ) return false;
        else                  return true;
      }
    }
    else {
      curr->left  = new Node(value);
      curr->weight -= 1;
      if( rebalance(curr) ) return false;
      else                  return true;
    }
  } else { // value = curr->value
    return false; // don't need to do anything
  }
}

bool AVLTree::remove(int value) {

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

bool AVLTree::rotateLeft(int value) {

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

bool AVLTree::rotateRight(int value) {

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

bool AVLTree::rotateRight(Node*& curr) {
  Node* successor = curr->left;
  Node* mover = NULL;

  if(!successor) return true;

  // get/switch mover
  mover = successor->right;
  curr->left = mover;
  successor->right = curr;
  curr = successor;

  return true;
}

bool AVLTree::rotateLeft(Node*& curr) {
  Node* successor = curr->right;
  Node* mover = NULL;

  if(!successor) return true;

  // get/switch mover
  mover = successor->left;
  curr->right = mover;
  successor->left = curr;
  curr = successor;

  return true;
}


/**
 * Rebalance each node
 *
 * The idea is that each node will receive info on whether it its subtrees are imbalanced or not
 */
bool AVLTree::rebalance(Node*& curr) {
  cout << "DEBUG: in rebalance()" << endl;

  if        (curr->weight == -2) { // left-* imbalance
    if(curr->left->weight == -1) { // left-left imbalance 
      llRebalance(curr);
    } else if(curr->left->weight == 1) { // left-right imbalance
      lrRebalance(curr);
    } else { 
      // throw something
      std::cout << "ERROR: -2 0 imbalance invalid" << std::endl;
    }
    return true;

  } else if  (curr->weight ==  2) { // right-* imbalance
    if(curr->right->weight == -1) { // right-left imbalance 
      rlRebalance(curr);
    } else if(curr->right->weight == 1) { // right-right imbalance
      rrRebalance(curr);
    } else {
      // throw something
      std::cout << "ERROR: 2 0 imbalance invalid" << std::endl;
    }
    return true;
  } else if(curr->weight == 0) { // adding node rebalances tree
    return true;
  } else {
    return false;
  }
}

/**
 * left-left imbalance rebalance
 *
 * rebalance the nodes an set weight of thoses nodes to zero
 *
 * TODO: check weight setting is correct
 */
void AVLTree::llRebalance(Node*& curr) {
  cout << "DEBUG: in llRebalance()" << endl;
  rotateRight(curr);
  // new weights
  curr->right->weight = getWeightAfterRebalance(curr->right);
  curr->weight = 0;         // parent is 0
  // curr->left->weight     // left subtree stays the same?
}

/**
 * left-right imbalance rebalance
 *
 * rebalance the nodes an set weight of thoses nodes to zero
 *
 * TODO: check weight setting is correct
 */
void AVLTree::lrRebalance(Node*& curr) {
  cout << "DEBUG: in lrRebalance()" << endl;
  rotateLeft(curr->left);
  rotateRight(curr);
  curr->right->weight = getWeightAfterRebalance(curr->right);
  curr->weight = 0;         // parent is 0
  curr->left->weight -= 1;  // left subtree sub 1
}

void AVLTree::rrRebalance(Node*& curr) {
  cout << "DEBUG: in rrRebalance()" << endl;
  rotateLeft(curr);
  // new weights
  // curr->right->weight    // right subtree stays the same?
  curr->weight = 0;         // parent is 0
  curr->left->weight  = getWeightAfterRebalance(curr->left);
}

void AVLTree::rlRebalance(Node*& curr) {
  cout << "DEBUG: in rlRebalance()" << endl;
  rotateRight(curr->right);
  rotateLeft(curr);
  curr->right->weight += 1; // right subtree sub 1
  curr->weight = 0;         // parent is 0
  curr->left->weight = getWeightAfterRebalance(curr->left);
}

/**
 * check balance after rotation
 *
 * TODO: check that value after rebalance is correct
 */
int AVLTree::getWeightAfterRebalance(Node*& curr) {
  // cout << "DEBUG: in getWeightAfterRebalance()" << endl;
  // cout << "       curr->left=" << (curr->left ? "true" : "false") << endl;
  // cout << "       curr->right=" << (curr->right ? "true" : "false") << endl;
  if(!curr->left && !curr->right) return 0;
  else if(!curr->left)  return 1;
  else if(!curr->right) return -1;
  else return 0;
}

//---------------------------------------//
//-------------- ACCESSORS --------------//
//---------------------------------------//

// client for pre-order print
void AVLTree::preOrderPrint() {
  std::cout << "pre order:   ";
  preOrderPrintHelper(root);
  std::cout << std::endl;
}

// helper for pre-order print
void AVLTree::preOrderPrintHelper(Node* curr) {
  if(!curr) return;
  else {
    std::cout << curr->value << " ";
    preOrderPrintHelper(curr->left);
    preOrderPrintHelper(curr->right);
  }
}

// client for in-order print
void AVLTree::inOrderPrint() {
  std::cout << "in order:    ";
  inOrderPrintHelper(root);
  std::cout << std::endl;
}

// helper for in-order print
void AVLTree::inOrderPrintHelper(Node* curr) {
  if(!curr) return;
  else {
    preOrderPrintHelper(curr->left);
    std::cout << curr->value << " ";
    preOrderPrintHelper(curr->right);
  }
}

// client for post-order print
void AVLTree::postOrderPrint() {
  std::cout << "post order:  ";
  postOrderPrintHelper(root);
  std::cout << std::endl;
}

// helper for post-order print
void AVLTree::postOrderPrintHelper(Node* curr) {
  if(!curr) return;
  else {
    preOrderPrintHelper(curr->left);
    preOrderPrintHelper(curr->right);
    std::cout << curr->value << " ";
  }
}

void AVLTree::levelOrderPrint() {
  std::cout << "level order: ";
  levelOrderPrintHelper(root);
  std::cout << std::endl;
}

void AVLTree::levelOrderPrintHelper(Node* root) {
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
int AVLTree::getHeight() {
  return getHeightHelper(root);
}

// helper for getting height (0-based)
int AVLTree::getHeightHelper(Node* curr) {
  if(curr) {
    int ret1 = getHeightHelper(curr->left);
    int ret2 = getHeightHelper(curr->right);
    return 1 + max(ret1, ret2);
  }
  else return -1;
}


int AVLTree::getSize() {
  return getSizeHelper(root);
}

int AVLTree::getSizeHelper(Node* curr) {
  if(curr) {
    return getSizeHelper(curr->left) 
         + getSizeHelper(curr->right)
         + 1;
  } else return 0;
}

int AVLTree::getMin() {
  if(empty()) return 0; // trivial
}

int AVLTree::getMax() {
  if(empty()) return 0; // trivial
}

bool AVLTree::hasValue(int value) {
  if(empty()) return false; // trivial
}

bool AVLTree::empty() {
  return root == NULL;
}

// because of the way insertion is designed, the tree is always ordered BST.

// client : is ordered?
bool AVLTree::isOrdered() {
  if(empty()) return true; // trivial

  return isOrderedHelper(root, MIN, MAX);
}

// helper : is ordered?
bool AVLTree::isOrderedHelper(Node* curr, int minVal, int maxVal) {
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
        ss << node->value;
        //ss << node->weight;
        //ss << node->value << ":" << node->weight;
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

void AVLTree::print() const {
    printTree(BinaryTreeNodeDescriptor<Node>(root));

}