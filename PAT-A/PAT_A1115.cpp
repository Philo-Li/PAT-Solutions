#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
//A1115 Counting Nodes in a BST
struct Node{
  int v, depth;
  Node* left;
  Node* right;
};
int Insert(Node* &root, int x, int depth){
  if(root == NULL){
    root = new Node;
    root->v = x;
    root->left = root->right = NULL;
    return depth;
  }else if(root->v >= x){//左子树小于等于右子树，所以相等也往左搜索
    Insert(root->left, x, depth + 1);
  }else Insert(root->right, x, depth + 1);
}
int main() {
  int n, t, d, maxd = 0, dep[10000] = {0};
  Node* root = NULL;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &t);
    d = Insert(root, t, 0);
    maxd = max(d, maxd);
    dep[d]++;
  }
  printf("%d + %d = %d\n", dep[maxd], dep[maxd - 1], dep[maxd] + dep[maxd - 1]);
  return 0;
}
