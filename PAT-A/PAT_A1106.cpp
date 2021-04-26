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
//A1106 Lowest Price in Supply Chain
double lowp, p, r;
int n, k, id, lown = 0, layer[100010] = {0};
int maxdepth = 0, mindepth = 100010;
vector<int> tree[100010];
void dfs(int index, int depth){
  if(tree[index].size() == 0){
    if(mindepth > depth) mindepth = depth;
    if(maxdepth < depth) maxdepth = depth;
    layer[depth]++;
    return;
  }else{
    for(int i = 0; i < tree[index].size(); i++){
      dfs(tree[index][i], depth + 1);
    }
  }
}
int main() {
  scanf("%d%lf%lf", &n, &p, &r);
  for(int i = 0; i < n; i++){
    scanf("%d", &k);
    for(int j = 0; j < k; j++){
      scanf("%d", &id);
      tree[i].push_back(id);
    }
  }
  dfs(0, 0);
  printf("%.4lf %d\n", p * pow(1 + 0.01 * r, mindepth), layer[mindepth]);
  return 0;
}
