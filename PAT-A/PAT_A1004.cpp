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
//A1004 Counting Leaves
int n, m, id, num, k, layer[100] = {0};
int maxdepth = 0;
vector<int> tree[110];
void dfs(int index, int depth){
  if(tree[index].size() == 0){
    if(depth > maxdepth) maxdepth = depth;
    layer[depth]++;
    return;
  }else{
    for(int i = 0; i < tree[index].size(); i++){
      dfs(tree[index][i], depth + 1);
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i < m; i++){
    scanf("%d%d", &id, &num);
    for(int j = 0; j < num; j++){
      scanf("%d", &k);
      tree[id].push_back(k);
    }
  }
  dfs(1, 0);
  for(int i = 0; i <= maxdepth; i++){
    if(i!=0) printf(" ");
    printf("%d", layer[i]);
  }
  return 0;
}
