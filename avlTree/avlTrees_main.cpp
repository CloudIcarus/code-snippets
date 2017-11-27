#include<iostream>
#include<string>
#include"avlTrees.h"

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

/*
 * ll rebalancing seems ok
 */
void testLLRebalance() {
  string testName = "testLLRebalance";

  AVLTree at = AVLTree();
  at.insert(   0);
  at.insert(  -3);
  at.insert(   3);
  at.insert(  -4);
  at.insert(  -5);
  at.insert(  -6);
  at.insert(  -7);
  at.insert(  -8);
  at.insert(  -9);
  at.insert( -10);
  at.insert( -11);
  at.insert( -12);
  at.insert( -13);
  at.insert( -14);
  at.insert( -15);
  at.insert( -16);
  at.print();
}

/*
 * rr rebalancing seems ok
 */
void testRRRebalance() {
  string testName = "testRRRebalance";

  AVLTree at = AVLTree();
  at.insert(   0);
  at.insert(   1);
  at.insert(   2);
  at.insert(   3);
  at.insert(   4);
  at.insert(   5);
  at.insert(   6);
  at.insert(   7);
  at.insert(   8);
  at.insert(   9);
  at.insert(  10);
  at.insert(  11);
  at.insert(  12);
  at.print();
}

/*
 * lr rebalancing seems ok
 */
void testLRRebalance() {
  string testName = "testLRRebalance";

  AVLTree at = AVLTree();
  at.insert(   1);
  at.insert(  -6);
  at.insert(  -2);
  at.insert(  -8);
  at.insert(  -7);
  at.insert( -10);
  at.insert(  -9);
  at.insert( -12);
  at.insert( -11);
  at.insert( -14);
  at.insert( -13);
  at.print();
}

/*
 * rl rebalancing seems ok
 */
void testRLRebalance() {
  string testName = "testRLRebalance";

  AVLTree at = AVLTree();
  at.insert(  -1);
  at.insert(   6);
  at.insert(   2);
  at.insert(   8);
  at.insert(   7);
  at.insert(  10);
  at.insert(   9);
  at.insert(  12);
  at.insert(  11);
  at.insert(  14);
  at.insert(  13);
  at.print();
}

/*
 * advanced rebalancing
 */
void testAdvRebalance() {
  string testName = "testAdvRebalance";

  AVLTree at = AVLTree();
  at.insert(   0);
  at.insert(  12);
  at.insert( -12);
  at.insert(   6);
  at.insert(   3);
  at.insert(   4);
  at.insert(   9);
  at.insert(   5);
  at.print();
}

/*
 * advanced rebalancing
 */
void testAdvRebalance2() {
  string testName = "testAdvRebalance2";

  AVLTree at = AVLTree();
  at.insert(   0);
  at.insert( -12);
  at.insert(  12);
  at.insert(  -6);
  at.insert(  -3);
  at.insert(  -4);
  at.insert(  -9);
  at.insert(  -5);
  at.print();
}

/*
 * advanced rebalancing
 */
void testAdvRebalance3() {
  string testName = "testAdvRebalance2";

  AVLTree at = AVLTree();
  at.insert(   0); //at.print();
  at.insert(  36); //at.print();
  at.insert(  66); //at.print();
  at.insert(  12); //at.print();
  at.insert( -36); //at.print();
  at.insert( -12); //at.print();
  at.insert( -24); //at.print();
  at.insert(  60); at.print();
}

/*
 * advanced rebalancing
 */
void testAdvRebalance4() {
  string testName = "testAdvRebalance2";

  AVLTree at = AVLTree();
  at.insert(  66); //at.print();
  at.insert(  12); //at.print();
  at.insert(   0); //at.print();
  at.insert(  36); //at.print();
  at.insert( -12); //at.print();
  at.insert( -36); //at.print();
  at.insert( -24); //at.print();
  at.insert(  60); //at.print();
  at.insert(  20); //at.print();
  at.insert(   1); //at.print();
  at.insert(   2); //at.print();
  at.insert(   3); //at.print();
  at.insert( -60); //at.print();
  at.insert(  50); //at.print();
  at.insert(  51); //at.print();
  at.insert(  52); //at.print();
  at.insert(  53); //at.print();
  at.insert(  54); at.print();
}

/* 

g++ -std=c++11 -o avlTrees avlTrees_main.cpp avlTrees.cpp
*/
int main() {

  //testLLRebalance();
  //testRRRebalance();
  //testLRRebalance();
  //testRLRebalance();
  //testAdvRebalance();
  //testAdvRebalance2();
  //testAdvRebalance3();
  testAdvRebalance4();

  return 0;
}