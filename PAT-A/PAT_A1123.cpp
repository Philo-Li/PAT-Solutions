#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
//A1123 Is It a Complete AVL Tree
struct node{
  int v, height;
  node* lchild, *rchild;
}*root;
node* newNode(int v){
  node* Node = new node;
  Node->v = v;
  Node->height = 1;
  Node->lchild = Node->rchild = NULL;
  return Node;
}
int getHeight(node* root){
  if(root == NULL) return 0;
  else return root->height;
}
void updateHeight(node* root){
  root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}
int getBalanceFactor(node* root){
  return getHeight(root->lchild) - getHeight(root->rchild);
}
void L(node* &root){
  node* temp = root->rchild;
  root->rchild = temp->lchild;
  temp->lchild = root;
  updateHeight(root);
  updateHeight(temp);
  root = temp;
}
void R(node* &root){
  node* temp = root->lchild;
  root->lchild = temp->rchild;
  temp->rchild = root;
  updateHeight(root);
  updateHeight(temp);
  root = temp;
}
void insert(node* &root, int x){
  if(root == NULL){
    root = newNode(x);
    return;
  }
  root->height++;
  if(x < root->v){
    insert(root->lchild, x);
    updateHeight(root);
    if(getBalanceFactor(root) == 2){
      if(getBalanceFactor(root->lchild) == 1){
        R(root);
      }else if(getBalanceFactor(root->lchild) == -1){
        L(root->lchild);
        R(root);
      }
    }
  }else{
    insert(root->rchild, x);
    updateHeight(root);
    if(getBalanceFactor(root) == -2){
      if(getBalanceFactor(root->rchild) == -1){
        L(root);
      }else if(getBalanceFactor(root->rchild) == 1){
        R(root->rchild);
        L(root);
      }
    }
  }
}
int main() {
  int n, A[25];
  scanf("%d", &n);
  node* root = NULL;
  for(int i = 1; i <= n; i++){
    scanf("%d", &A[i]);
    insert(root, A[i]);
  }
  int cnt = 1, flag = 1;
  queue<node*> q;
  vector<node*> ans;
  q.push(root);
  while(!q.empty()){
    node* top = q.front();
    ans.push_back(top);
    q.pop();
    if(top->lchild != NULL){
      q.push(top->lchild);
      if(flag == 1) cnt++;
    }else flag = 0;
    if(top->rchild != NULL) {
      q.push(top->rchild);
      if(flag == 1) cnt++;
    }else flag = 0;
  }
  for(int i = 1; i < n; i++){
    if(i != 1) printf(" ");
    printf("%d", ans[i]->v);
  }
  printf("\n%s\n", cnt == n ? "YES":"NO");
  return 0;
}
