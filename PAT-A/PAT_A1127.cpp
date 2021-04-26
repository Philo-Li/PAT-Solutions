#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
//A1127 ZigZagging on a Tree
int n, in[40], post[40], level[40], pre[40], cnt = 0;
vector<int> ans[40];
struct node{
  int v, depth;
  node* lchild, *rchild;
};
node* newNode(int x, int depth){
  node* temp = new node;
  temp->depth = depth;
  temp->v = x;
  temp->lchild = temp->rchild = NULL;
  return temp;
}
void create(node* &root, int inL, int inR, int postL, int postR, int depth){
  if(postL > postR) return;
  if(root == NULL){
    root = newNode(post[postR], depth);
  }
  int k;
  for(k = inL; k <= inR; k++){
    if(post[postR] == in[k]) break;
  }
  create(root->lchild, inL, k - 1, postL, postL + k - inL - 1, depth + 1);
  create(root->rchild, k + 1, inR, postL + k - inL, postR - 1, depth + 1);
}
int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", &in[i]);
  for(int i = 0; i < n; i++) scanf("%d", &post[i]);
  node* root = NULL;
  create(root, 0, n - 1, 0, n - 1, 1);
  queue<node*> q;
  vector<int> ans[50];
  q.push(root);
  while(!q.empty()){
    node* top = q.front();
    ans[top->depth].push_back(top->v);
    q.pop();
    if(top->lchild != NULL) q.push(top->lchild);
    if(top->rchild != NULL) q.push(top->rchild);
  }
  int cnt = 0;
  for(int i = 1; i < 50; i++){
    if(i % 2 == 1 && ans[i].size() > 1){ reverse(ans[i].begin(), ans[i].end()); }
    for(int j = 0; j < ans[i].size(); j++, cnt++){
      if(cnt != 0) printf(" ");
      printf("%d", ans[i][j]);
    }
  }
  return 0;
}
