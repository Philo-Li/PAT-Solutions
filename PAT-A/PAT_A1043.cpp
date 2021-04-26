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
//A1043 Is It a Binary Search Tree
//
// #include <cstdio>
// #include <vector>
// using namespace std;
// bool isMirror;
// vector<int> pre, post;
// void getpost(int root, int tail) {
//     if(root > tail) return ;
//     int i = root + 1, j = tail;
//     if(!isMirror) {
//         while(i <= tail && pre[root] > pre[i]) i++;
//         while(j > root && pre[root] <= pre[j]) j--;
//     } else {
//         while(i <= tail && pre[root] <= pre[i]) i++;
//         while(j > root && pre[root] > pre[j]) j--;
//     }
//     if(i - j != 1) return ;
//     getpost(root + 1, j);
//     getpost(i, tail);
//     post.push_back(pre[root]);
// }
// int main() {
//     int n;
//     scanf("%d", &n);
//     pre.resize(n);
//     for(int i = 0; i < n; i++)
//         scanf("%d", &pre[i]);
//     getpost(0, n - 1);
//     if(post.size() != n) {
//         isMirror = true;
//         post.clear();
//         getpost(0, n - 1);
//     }
//     if(post.size() == n) {
//         printf("YES\n%d", post[0]);
//         for(int i = 1; i < n; i++)
//             printf(" %d", post[i]);
//     } else {
//         printf("NO");
//     }
//     return 0;
// }

int n, k;
struct node{
  int data;
  node* left;
  node* right;
};
void insert(node* &root, int data){
  if(root == NULL){
    root = new node;
    root->data = data;
    root->left = root->right = NULL;
    return;
  }
  if(data < root->data) insert(root->left, data);
  else insert(root->right, data);
}
void preorder(node* root, vector<int> &vi){
  if(root == NULL) return;
  vi.push_back(root->data);
  preorder(root->left, vi);
  preorder(root->right, vi);
}
void preorderM(node* root, vector<int> &vi){
  if(root == NULL)return;
  vi.push_back(root->data);
  preorderM(root->right, vi);
  preorderM(root->left, vi);
}
void postorder(node* root, vector<int> &vi){
  if(root == NULL) return;
  postorder(root->left, vi);
  postorder(root->right, vi);
  vi.push_back(root->data);
}
void postorderM(node* root, vector<int> &vi){
  if(root == NULL) return;
  postorderM(root->right, vi);
  postorderM(root->left, vi);
  vi.push_back(root->data);
}
vector<int> origin, pre, preM, post, postM, ans;
int main() {
  scanf("%d", &n);
  node* root = NULL;
  for(int i = 0; i < n; i++){
    scanf("%d", &k);
    origin.push_back(k);
    insert(root, k);
  }
  preorder(root, pre);
  preorderM(root, preM);
  postorder(root, post);
  postorderM(root, postM);
  bool flag = false;
  if(origin == pre){
    flag = true;
    ans = post;
  }else if(origin == preM){
    flag = true;
    ans = postM;
  }else{
    printf("NO\n");
  }
  if(flag){
    printf("YES\n");
    for(int i = 0; i < ans.size(); i++){
      if(i != 0) printf(" ");
      printf("%d", ans[i]);
    }
  }
  return 0;
}
