#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <set>
#include <vector>
#include <iostream>
using namespace std;
//A1134 Vertex Cover
// "可以记录每条边的编号，然后用hash记录每条边是否命中
// 最后遍历hash，发现有没命中的边为false"
int main() {
  int n, m, a, b, k;
  scanf("%d %d", &n, &m);
  vector<int> G[10010];
  for(int i = 0; i < m; i++){
    scanf("%d %d", &a, &b);
    G[a].push_back(i);
    G[b].push_back(i);
  }
  scanf("%d", &k);
  for(int i = 0; i < k; i++){
    int q, flag = 1;
    vector<int> hash(m, 0);
    scanf("%d", &q);
    for(int j = 0; j < q; j++){
      scanf("%d", &a);
      for(int p = 0; p < G[a].size(); p++){
        hash[G[a][p]] = 1;
      }
    }
    for(int j = 0; j < m; j++){
      if(hash[j] == 0){ flag = 0; break; }
    }
    printf("%s\n", flag == 1 ? "Yes":"No");
  }
  return 0;
}
