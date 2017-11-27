class BinaryTree {

public:
  BinaryTree();
  ~BinaryTree();

  // mutators
  void insert(int value);
  bool remove(int value);
  bool rotateLeft(int value);
  bool rotateRight(int value);

  // accessors
  void preOrderPrint();
  void inOrderPrint();
  void postOrderPrint();
  void levelOrderPrint();

  int getHeight();
  int getSize();
  int getMin();
  int getMax();

  bool hasValue(int value); // BT search
  bool empty();
  bool isOrdered();

  // special print method
  void print() const;

private:
  struct Node {
    Node(int v): value(v), left(NULL), right(NULL) {};

    int value;
    Node* left;
    Node* right;
  };

  #include "binaryTrees_private.h"

  // mutators
  void insertHelper(int value, Node* curr);
  //bool removeHelper(int value, Node* curr);
  //void rotateHelper(int value, Node* curr);

  // accessor helpers
  void preOrderPrintHelper(Node* );
  void inOrderPrintHelper(Node* );
  void postOrderPrintHelper(Node* );
  void levelOrderPrintHelper(Node* );

  int getHeightHelper(Node* );
  int getSizeHelper(Node* );
  int getMinHelper(Node* );
  int getMaxHelper(Node* );

  bool isOrderedHelper(Node* curr, int minVal, int maxVal);

  const int MIN = -9999;
  const int MAX =  9999;

  Node* root;
};