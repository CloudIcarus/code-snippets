class AVLTree {

public:
  AVLTree();
  ~AVLTree();

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
    Node(int v): value(v), left(NULL), right(NULL), weight(0) {};

    int value;
    Node* left;
    Node* right;
    int weight;
  };

  void deleteNode(Node* curr) {
    if(!curr) return;
    if(curr->left) {
      deleteNode(curr->left);
      delete curr->left;
    }
    if(curr->right) {
      deleteNode(curr->right);
      delete curr->right;
    }
  }

  // mutators
  bool insertHelper(int value, Node*& curr);
  //bool removeHelper(int value, Node* curr);

  // NEW avl methods
  bool rebalance(Node*& curr);

  void llRebalance(Node*& curr);
  void lrRebalance(Node*& curr);
  void rrRebalance(Node*& curr);
  void rlRebalance(Node*& curr);

  bool rotateRight(Node*& curr);
  bool rotateLeft(Node*& curr);

  int getWeightAfterRebalance(Node*& curr);

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