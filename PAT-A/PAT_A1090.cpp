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
//A1090 Highest Price in Supply Chain
const int maxn = 100010;
int n, k, id, cnt = 0, maxlayer = -1, maxnum = 0;
double p, r, sum = 0.0;
vector< vector<int> > tree;
void dfs(int index, int layer){
  if(tree[index].size() == 0){
    if(layer > maxlayer) {
      maxlayer = layer;
      maxnum = 1;
    }else if(layer == maxlayer){
      maxnum++;
    }
    return;
  }
  else if(tree[index].size() != 0){
    for(int i = 0; i < tree[index].size(); i++){
      // printf("%d %d %d %d\n", layer, maxlayer, maxnum, tree[index][i]);
      dfs(tree[index][i], layer + 1);
    }
  }
}
int main() {
  scanf("%d%lf%lf", &n, &p, &r);
  tree.resize(n + 1);
  for(int i = 0; i < n; i++){
    scanf("%d", &k);
    if(k == -1){
      tree[n].push_back(i);
    }
    else tree[k].push_back(i);
  }
  dfs(n, 0);
  printf("%.2lf %d\n", p * pow(1 + 0.01 * r, maxlayer - 1), maxnum);
  return 0;
}
