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
//A1099 Build A Binary Search Tree

int n, lchild, rchild, temp[105], cnt = 0;
struct node{
  int data;
  int left;
  int right;
}tree[105];
void inorder(int root){
  if(tree[root].left == -1 && tree[root].right == -1){
    tree[root].data = temp[cnt++];
    return;
  }
  if(tree[root].left != -1) inorder(tree[root].left);
  tree[root].data = temp[cnt++];
  if(tree[root].right != -1) inorder(tree[root].right);
}
void level(int root){
  queue<int> q;
  q.push(root);
  int flag = 0;
  while(!q.empty()){
    int top = q.front();
    if(flag != 0) printf(" ");
    printf("%d", tree[top].data); flag = 1;
    q.pop();
    if(tree[top].left != -1) q.push(tree[top].left);
    if(tree[top].right != -1) q.push(tree[top].right);
  }
}
int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d %d", &lchild, &rchild);
    tree[i].left = lchild;
    tree[i].right = rchild;
  }
  for(int i = 0; i < n; i++){
    scanf("%d", &temp[i]);
  }
  sort(temp, temp + n);
  inorder(0);
  level(0);
  return 0;
}
