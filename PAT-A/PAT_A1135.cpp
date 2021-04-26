#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
//A1135 Is It A Red-Black Tree
struct node{
  int v, height, isblack;
  node *lchild, *rchild;
}*root;
node* newnode(int x, int flag){
  node* temp = new node;
  temp->v = x;
  temp->isblack = flag;
  temp->lchild = temp->rchild = NULL;
  return temp;
}
int getHeight(node* root){
  if(root == NULL) return 0;//这里高度用遍历遇到的黑节点个数定义
  else return max(getHeight(root->lchild), getHeight(root->rchild)) + root->isblack==1?1 : 0;
}
int getBalanceFactor(node* a, node* b){
  return abs(getHeight(a) - getHeight(b));
}
void insert(node* &root, int x){
  if(root == NULL){
    root = newnode(abs(x), x > 0 ? 1:0);
    return;
  }
  if(abs(x) > root->v) insert(root->rchild, x);
  else insert(root->lchild, x);
}
void dfs(node* node, int &cnt, int num, int &flag){
  if(node == NULL){
    if(cnt == -1) cnt = num;
    if(cnt != num) flag = 0;
    return;
  }
  if(getBalanceFactor(node->lchild, node->rchild) > 1) flag = 0;
  if(node == root && root->isblack == 0){ flag = 0; }
  if(node->isblack == 0){
    if(node->lchild != NULL && node->lchild->isblack == 0) flag = 0;
    if(node->rchild != NULL && node->rchild->isblack == 0) flag = 0;
  }
  if(flag == 1) dfs(node->lchild, cnt, node->isblack == 1 ? num + 1:num, flag);
  if(flag == 1) dfs(node->rchild, cnt, node->isblack == 1 ? num + 1:num, flag);
}
int main() {
  int n, k, t;
  scanf("%d", &k);
  for(int i = 0; i < k; i++){
    scanf("%d", &n);
    int cnt = -1, flag = 1;
    root = NULL;
    for(int i = 0; i < n; i++){
      scanf("%d", &t);
      if(t == 0) flag = 0;
      insert(root, t);
    }
    dfs(root, cnt, 0, flag);
    printf("%s\n",  flag == 1 ? "Yes" : "No");
  }
  return 0;
}
