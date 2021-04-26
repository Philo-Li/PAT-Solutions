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
//A1094 The Largest Generation
vector< vector<int> > tree[100];
struct tree{
  vector <int> child;
}T[100];
int maxnum, anslayer = 0;
int m, n, id, num, child, p[100] = {0};
void dfs(int index, int layer){
  p[layer]++;
  if(T[index].child.size() == 0){
    return;
  }else{
    int len = T[index].child.size();
    for(int i = 0; i < len; i++){
      dfs(T[index].child[i], layer + 1);
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i < m; i++){
    scanf("%d%d", &id, &num);
    for(int j = 0; j < num; j++){
      scanf("%d", &child);
      T[id].child.push_back(child);
    }
  }
  dfs(1, 1);
  maxnum = p[0];
  for(int i = 0; i < 100; i++){
    if(maxnum < p[i]){
      maxnum = p[i]; anslayer = i;
    }
  }
  printf("%d %d\n", maxnum, anslayer);
  return 0;
}
