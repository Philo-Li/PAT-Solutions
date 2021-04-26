#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cctype>
#include <queue>
#include <algorithm>
using namespace std;
//A1020 Tree Traversals
// 题目大意：给定一棵二叉树的后序遍历和中序遍历，
// 请你输出其层序遍历的序列。这里假设键值都是互不相等的正整数。
// 分析：与后序中序转换为前序的代码相仿（无须构造二叉树
// 再进行广度优先搜索~~），只不过加一个变量index，
// 表示当前的根结点在二叉树中所对应的下标（从0开始），
// 所以进行一次输出先序的递归的时候，就可以把根结点下标
// 所对应的值存储在level数组中（一开始把level都置为-1
// 表示此处没有结点），这样在递归完成后level数组中非-1
// 的数就是按照下标排列的层序遍历的顺序~~~
// #include <vector>
// using namespace std;
// vector<int> post, in, level(100000, -1);
// void pre(int root, int start, int end, int index) {
//     if(start > end) return ;
//     int i = start;
//     while(i < end && in[i] != post[root]) i++;
//     level[index] = post[root];
//     pre(root - 1 - end + i, start, i - 1, 2 * index + 1);
//     pre(root - 1, i + 1, end, 2 * index + 2);
// }
// int main() {
//     int n, cnt = 0;
//     scanf("%d", &n);
//     post.resize(n);
//     in.resize(n);
//     for(int i = 0; i < n; i++) scanf("%d", &post[i]);
//     for(int i = 0; i < n; i++) scanf("%d", &in[i]);
//     pre(n-1, 0, n-1, 0);
//     for(int i = 0; i < level.size(); i++) {
//         if (level[i] != -1) {
//             if (cnt != 0) printf(" ");
//             printf("%d", level[i]);
//             cnt++;
//         }
//         if (cnt == n) break;
//     }
//     return 0;
// }
int n;
struct node{
  int data;
  node* lchild;
  node* rchild;
};
int postorder[50], inorder[50];
node* create(int postL, int postR, int inL, int inR){
  if(postL > postR) return NULL;
  node* root = new node;
  root->data = postorder[postR];
  int k;
  for(k = inL; k <= inR; k++){
    if(inorder[k] == postorder[postR]) break;
  }
  int leftnum = k - inL;
  root->lchild = create(postL, postL + leftnum -1, inL, k-1);
  root->rchild = create(postL+leftnum, postR-1, k+1, inR);
  return root;
}
int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &postorder[i]);
  }
  for(int i = 0; i < n; i++){
    scanf("%d", &inorder[i]);
  }
  node* root = create(0, n-1, 0, n-1);
  queue <node*> Q;
  Q.push(root);
  int cnt = 0;
  while(!Q.empty()){
    node* now = Q.front();
    Q.pop();
    if(cnt != 0) printf(" ");
    printf("%d", now->data); cnt++;
    if(now->lchild != NULL) Q.push(now->lchild);
    if(now->rchild != NULL) Q.push(now->rchild);
  }
  return 0;
}
