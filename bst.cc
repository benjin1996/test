#include "bst.h"
#include <iostream>
#include <string>

using namespace std;

treenode::treenode(int v): element{v}, left{NULL}, right{NULL}, size{1}, height{1} {}

treenode::treenode(const treenode& t): element{t.element}, left{NULL}, right{NULL}, size{t.size} {
 left = new treenode(*(t.left));
 right = new treenode(*(t.right));}

//treenode& treenode::operator=(const treenode& t) {
// v = t.v;}

void treenode::updateheight() {
 if (left == NULL && right == NULL) {
  height = 1;}
 else if (left == NULL || right == NULL) {
  if (left == NULL) {
   height = right->height + 1;}
  else {
   height = left->height + 1;}}
 else {
  int l = left->height;
  int r = right->height;
  if (r > l) {
   height = 1 + r;}
  else {
   height = 1 + l;}}}

void treenode::insert(int v) {
 size += 1;
 if (v > element) {
  if (right == NULL) {
   right = new treenode(v);}
  else {
   right->insert(v);}}
 else {
  if (left == NULL) {
   left = new treenode(v);}
  else {
   left->insert(v);}}
 updateheight();}

int treenode::sum() {
 if (this == NULL) {
  return 0;}
 return element + right->sum() + left->sum();}

int ithele(treenode* t, int i) {
 if (t->left == NULL) {
  if (i == 1) {
   return t->element;}
  else if (i > 1) {
   return ithele(t->right, i - 1);}}
 else {
  int counter = t->left->size;
  if (i == counter + 1) {
   return t->element;}
  else if (i > counter + 1) {
   return ithele(t->right,i - counter - 1);}
  else {
   return ithele(t->left,i);}}}

treenode* delnode(treenode* t, int v) {
 if (t->element == v) {
  if (t->left == NULL && t->right == NULL) {
   delete t;
   return NULL;}
  else if (t->left == NULL) {
   treenode* temp = t->right;
   delete t;
   return temp;}
  else if (t->right == NULL) {
   treenode* temp = t->left;
   delete t;
   return temp;}
  else {
   treenode* temp = t->right;
   treenode* leftcopy = t->left;
   treenode* rightcopy = t->right;
   int cursize = t->size;
   if (temp->left == NULL) {
    temp->left = leftcopy;
    temp->size += temp->left->size;
    delete t;
    return temp;}
   treenode* tc = t->right;
   int r = tc->right->height;
   int l = tc->left->height;
   int counter = 0;
   while (temp->left != NULL) {
    if (counter != 0) {
     tc = tc->left;}
    
    temp->size -= 1;
    temp = temp->left;
    counter += 1;}
   tc->left = temp->right;
   temp->size = cursize - 1;
   temp->right = rightcopy;
   temp->left = leftcopy;
   delete t;
   return temp;}}
 else {
  t->size -= 1;
  if (v > t->element) {
   t->right = delnode(t->right,v);}
  else {
   t->left = delnode(t->left,v);}}
 t->updateheight();}

void treenode::printtree() {
 if (this == NULL) {
  return;}
 left->printtree();
 cout << element << endl;
 right->printtree();}

treenode::~treenode() {} 

bsttree::bsttree(treenode* t) {
 root = t;
 treenode* temp = t;
 treenode* temp2 = t;
 while (temp->left != NULL) {
  temp = temp->left;}
 min = temp->element;
 while (temp2->right != NULL) {
  temp2 = temp2->right;}
 max = temp2->element;}

void bsttree::ins(int v) {
 if (v > max) {
  max = v;}
 else if (v < min) {
  min = v;}
 root->insert(v);}

void bsttree::del(int v) {
// if (v == max) {
//  max = ithele(root,root->size-1);}
// else if (v == min) {
//  min = ithele(root,2);}
 root = delnode(root,v);}

void deletehelper(treenode* t) {
 if (t == NULL) {
  return;}
 deletehelper(t->left);
 deletehelper(t->right);
 delete t;}

void bsttree::print() {
 root->printtree();
 cout << endl;}

bsttree::~bsttree() {
 deletehelper(root);}


