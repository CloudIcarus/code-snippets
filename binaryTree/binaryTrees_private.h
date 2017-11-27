
#ifndef _BINARYTREES_PRIVATE_H_
#define _BINARYTREES_PRIVATE_H_

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


#endif