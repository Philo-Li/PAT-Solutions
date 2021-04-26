#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cctype>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
//A1102 Invert a Binary Tree
int tree[20][2];
int n, notroot[20] = {0}, k = 0;
vector<int> level, inl;
void inorder(int root){
  if(tree[root][0] == -1 && tree[root][1] == -1){
    inl.push_back(root);//不能少！！
    return;
  }
  if(tree[root][0] != -1) inorder(tree[root][0]);
  inl.push_back(root);
  if(tree[root][1] != -1) inorder(tree[root][1]);
}
void print(vector<int> p){
  for(int i = 0; i < n; i++){
    if(i != 0) printf(" ");
    printf("%d", p[i]);
  }
  printf("\n");
}
int main() {
  scanf("%d", &n);
  string temp;
  getchar();
  for(int i = 0; i < 20; i++){
    tree[i][0] = -1; tree[i][1] = -1;
  }
  for(int i = 0; i < n; i++){
    getline(cin, temp);
    temp[1] = temp[0];//这里直接逆转过来
    temp[0] = temp[2];
    for(int j = 0; j < 2; j++){
      if(temp[j] != '-'){
        int t = (int)(temp[j] - '0');
        notroot[t] = 1;
        tree[i][j] = t;
      }else tree[i][j] = -1;
    }
  }
  while(notroot[k] && k < n) k++;
  queue<int> q;
  q.push(k);
  while(!q.empty()){
    int top = q.front();
    level.push_back(top);
    q.pop();
    if(tree[top][0] != -1) q.push(tree[top][0]);
    if(tree[top][1] != -1) q.push(tree[top][1]);
  }
  inorder(k);
  print(level);
  print(inl);
  return 0;
}
