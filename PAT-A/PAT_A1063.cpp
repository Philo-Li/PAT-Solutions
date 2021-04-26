#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
//A1063 Set Similarity
const int maxm = 10010;
const int maxn = 55;
int m, n, k;
set<int> ss[maxm];
int main(){
  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    scanf("%d", &m);
    for(int j = 0; j < m; j++){
      int temp;
      scanf("%d", &temp);
      ss[i].insert(temp);
    }
  }
  scanf("%d", &k);
  for(int i = 0; i < k; i++){
    int a, b, common = 0;
    scanf("%d %d", &a, &b);
    for(set<int>::iterator it = ss[a].begin(); it != ss[a].end(); it++){
      if(ss[b].find(*it) != ss[b].end()) common++;
    }
    double ans = 100.0 * common / (ss[a].size() + ss[b].size() - common);
    printf("%.1f%%\n", ans);
  }
  return 0;
}
