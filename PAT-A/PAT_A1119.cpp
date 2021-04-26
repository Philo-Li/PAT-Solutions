#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;
// A1119 Pre- and Post-order Traversals
int n, pre[50], post[50], cnt = 0;
bool flag = true;
struct Node{
  int v;
  Node* left, *right;
};
Node* create(int preL, int preR, int postL, int postR){
  if(preL > preR) return NULL;
  Node* root = new Node;
  root->v = pre[preL];
  root->left = root->right = NULL;
  if(preL == preR) return root;
  int k;
  for(k = preL + 1; k <= preR; k++){
    if(pre[k] == post[postR - 1]) break;
  }
  int numleft = k - preL - 1;
  if (k - preL > 1) {//如何区分左右子树很重要
    root->left = create(preL + 1, k - 1, postL, postL + numleft - 1);
  }
  else flag = false;
  root->right = create(k, preR, postL + numleft, postR - 1);
  return root;
}
void inorder(Node* root){
  if(root == NULL) return;
  inorder(root->left);
  if(cnt++ != 0) printf(" ");
  printf("%d", root->v);
  inorder(root->right);
}
int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", &pre[i]);
  for(int i = 0; i < n; i++) scanf("%d", &post[i]);
  Node* root = create(0, n - 1, 0, n - 1);
  if(flag == true) printf("Yes\n");
  else printf("No\n");
  inorder(root);
  printf("\n");
  return 0;
}

// #include <vector>
// int n, pre[50], post[50], cnt = 0;
// vector<int> in;
// bool flag = true;
// void getans(int preL, int preR, int postL, int postR){
//   if(preL == preR){
//     in.push_back(pre[preL]);
//     return;
//   } 
//   int k;
//   for(k = preL + 1; k <= preR; k++){
//     if(pre[k] == post[postR - 1]) break;
//   }//如何区分左右子树很重要
//   int numleft = k - preL - 1;
//   if (k - preL > 1) getans(preL + 1, k - 1, postL, postL + numleft - 1);
//   else flag = false;
//   in.push_back(post[postR]);
//   getans(k, preR, postL + numleft, postR - 1);
// }
// int main() {
//   scanf("%d", &n);
//   for(int i = 0; i < n; i++) scanf("%d", &pre[i]);
//   for(int i = 0; i < n; i++) scanf("%d", &post[i]);
//   getans(0, n - 1, 0, n - 1);
//   printf("%s\n",flag == true ? "Yes" : "No");
//   for(int i = 0; i < in.size(); i++){
//     if(i != 0) printf(" ");
//     printf("%d", in[i]);
//   }
//   printf("\n");
//   return 0;
// }
