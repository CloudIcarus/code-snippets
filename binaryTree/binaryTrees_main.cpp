#include<iostream>
#include<string>
#include"binaryTrees.h"

using namespace std;

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~ assertions ~~~~~~~~~~~~~~~
void assertTrue(string testName, string query, bool statement) {
  cout << testName << ": " << query << ": expect true: " << (statement ? "SUCCESS" : "FAIL") << endl;
}

void assertFalse(string testName, string query, bool statement) {
  cout << testName << ": " << query << ": expect false: " << (statement ? "FAIL" : "SUCCESS") << endl;
}

void assertEquals(string testName, string query, int a, int b) {
  cout << testName << ": " << query << ": expect equals: " << (a == b ? "SUCCESS" : "FAIL") << endl;
}

void assertEquals(string testName, string query, unsigned int a, unsigned int b) {
  cout << testName << ": " << query << ": expect equals: " << (a == b ? "SUCCESS" : "FAIL") << endl;
}

void assertEquals(string testName, string query, string a, string b) {
  cout << testName << ": " << query << ": expect equals: " << (a == b ? "SUCCESS" : "FAIL") << endl;
}

void assertEquals(string testName, string query, char a, char b) {
  cout << testName << ": " << query << ": expect equals: " << (a == b ? "SUCCESS" : "FAIL") << endl;
}

template <typename Exp>
void expectExp(string testName, string query, Exp e) {
  cout << testName << ": " << query << ": caught (" << e.what() << "): SUCCESS" << endl;
}

void assertFail(string testName, string query) {
  cout << testName << ": " << query << ": " << "FAIL" << endl;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


void constructAndInsert() {
  string testName = "constructAndInsert";

  BinaryTree bt = BinaryTree();
  bt.insert(   0);
  bt.insert(  -3);
  bt.insert(   3);
  bt.insert(  -4);
  bt.insert(  -2);
  bt.insert(   2);
  bt.insert(   5);
  bt.insert(   4);
  bt.insert(   1);
  bt.insert(   6);

  bt.inOrderPrint();
  bt.preOrderPrint();
  bt.postOrderPrint();
  bt.levelOrderPrint();
  cout << testName << "height of tree is: " << bt.getHeight() << endl;
  cout << testName << "size of tree is:   " << bt.getSize() << endl;
  cout << testName << "tree is " << (bt.isOrdered() ? "ordered": "not ordered") << endl;
  cout << testName << "tree is: " << endl;
  bt.print();
  bt.remove(3);
  cout << testName << "after deleting 3: " << endl;
  bt.print();
  bt.remove(4);
  cout << testName << "after deleting 4: " << endl;
  bt.print();
  bt.remove(-3);
  cout << testName << "after deleting -3: " << endl;
  bt.print();
  bt.remove(0);
  cout << testName << "after deleting 0: " << endl;
  bt.print();
  bt.remove(-4);
  cout << testName << "after deleting -4: " << endl;
  bt.print();
  bt.remove(6);
  cout << testName << "after deleting 6: " << endl;
  bt.print();
  bt.remove(5);
  cout << testName << "after deleting 5: " << endl;
  bt.print();
}

void rotation() {
  string testName = "constructAndInsert";

  BinaryTree bt = BinaryTree();
  bt.insert(   0);
  bt.insert(  -3);
  bt.insert(   3);
  bt.insert(  -4);
  bt.insert(  -2);
  bt.insert(   2);
  bt.insert(   5);
  bt.insert(   4);
  bt.insert(   1);
  bt.insert(   6);

  cout << testName << "tree is: " << endl;
  bt.print();
  bt.rotateLeft(3);
  cout << testName << "after rotating 3 left: " << endl;
  bt.print();
  bt.rotateLeft(-3);
  cout << testName << "after rotating -3 left: " << endl;
  bt.print();
  bt.rotateLeft(0);
  cout << testName << "after rotating 0 left: " << endl;
  bt.print();
  bt.rotateRight(3);
  cout << testName << "after rotating 3 right: " << endl;
  bt.print();
  bt.rotateRight(-2);
  cout << testName << "after rotating -2 right: " << endl;
  bt.print();
  bt.rotateRight(5);
  cout << testName << "after rotating 5 right: " << endl;
  bt.print();
}

/* 

g++ -std=c++11 -o binaryTrees binaryTrees_main.cpp binaryTrees.cpp
*/
int main() {

  //constructAndInsert();
  rotation();

  return 0;
}