#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
//A1053 Path of Equal Weight
struct node{
  int weight;
  vector<int> child;
}tree[110];
int m, n, s, path[100];
void dfs(int index, int numnode, int sum){
  sum += tree[index].weight;
  if(sum > s) return;
  if(sum == s){
    if(tree[index].child.size() != 0) return;
    for(int i = 0; i < numnode; i++){
      if(i != 0) printf(" ");
      printf("%d", tree[path[i]].weight);
      if(i == numnode - 1) printf("\n");
    }
  }
  for(int i = 0; i < tree[index].child.size(); i++){
    path[numnode] = tree[index].child[i];
    dfs(tree[index].child[i], numnode + 1, sum);
  }
}
bool cmp(int a, int b){
  return tree[a].weight > tree[b].weight;
}
int main() {
  scanf("%d%d%d", &n, &m, &s);
  for(int i = 0; i < n; i++){
    scanf("%d", &tree[i].weight);
  }
  int id, num, child;
  for(int i = 0; i < m; i++){
    scanf("%d%d", &id, &num);
    for(int j = 0; j < num; j++){
      scanf("%d", &child);
      tree[id].child.push_back(child);
    }
    sort(tree[id].child.begin(), tree[id].child.end(), cmp);
  }
  path[0] = 0;//重要
  dfs(0, 1, 0);
  return 0;
}
