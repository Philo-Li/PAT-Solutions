#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cctype>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>
using namespace std;
//A1066 Root of AVL Tree
int n, k;
struct node{
  int data;
  int height;
  node* left;
  node* right;
}*root;
node* newNode(int v){
  node* Node = new node;
  Node->data = v;
  Node->height = 1;
  Node->left = Node->right = NULL;
  return Node;
}
int getHeight(node* root){
  if(root == NULL) return 0;
  return root->height;
}
void updateHeight(node* root){
  root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
}
int getBalanceFactor(node* root){
  return getHeight(root->left) - getHeight(root->right);
}
void L(node* &root){
  node* temp = root->right;
  root->right = temp->left;
  temp->left = root;
  updateHeight(root);
  updateHeight(temp);
  root = temp;
}
void R(node* &root){
  node* temp = root->left;
  root->left = temp->right;
  temp->right = root;
  updateHeight(root);
  updateHeight(temp);
  root = temp;
}
void insert(node* &root, int k){
  if(root == NULL){
    root = newNode(k);
    return;
  }
  if(k < root->data){
    insert(root->left, k);
    updateHeight(root);
    if(getBalanceFactor(root) == 2){
      if(getBalanceFactor(root->left) == 1){//LL
        R(root);
      }else if(getBalanceFactor(root->left) == -1){//LR
        L(root->left);
        R(root);
      }
    }
  }
  else{
    insert(root->right, k);
    updateHeight(root);
    if(getBalanceFactor(root) == -2){
      if(getBalanceFactor(root->right) == -1){//RR
        L(root);
      }else if(getBalanceFactor(root->right) == 1){//RL
        R(root->right);
        L(root);
      }
    }
  }
}
int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &k);
    insert(root, k);
  }
  printf("%d\n", root->data);
  return 0;
}
