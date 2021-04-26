#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
//A1130 Infix Expression
//中缀表达式, 不能用是不是加减乘除判断运算符，
//因为可能出现不是这几个的运算符，所以要用是不是叶节点判断
//不是叶节点也不是根节点的，两边要加括号，在中序遍历的时候加
int n, root = 1, tree[30][2];
vector<int> ans;
map<int, string> id;
bool isfather[30] = {false}, vis[30] = {false};
void inorder(int idx){
  if(isfather[idx] && root != idx) ans.push_back(n + 1);
  if(tree[idx][0] != -1) inorder(tree[idx][0]);
  ans.push_back(idx);
  if(tree[idx][1] != -1) inorder(tree[idx][1]);
  if(isfather[idx] && root != idx) ans.push_back(n + 2);
}
int main() {
  int l, r;
  cin >> n;
  for(int i = 1; i <= n; i++){
    string str;
    cin >> str >> l >> r;
    id[i] = str;
    tree[i][0] = l; tree[i][1] = r;
    if(l != -1) vis[l] = true;
    if(r != -1) vis[r] = true;
    if(l != -1 || r != -1) isfather[i] = true;
  }
  id[n + 1] = "(";
  id[n + 2] = ")";
  while(vis[root] == true) root++;
  inorder(root);
  for(int i = 0; i < ans.size(); i++){
    cout << id[ans[i]];
  }
  cout << endl;
  return 0;
}
