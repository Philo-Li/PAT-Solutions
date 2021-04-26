#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
//A1118 Birds in Forest
int n, q, father[10010], maxid = 0;
int findfather(int x){
  int a = x;
  while(x != father[x]){
    x = father[x];
  }
  while(a != father[a]){
    int z = a;
    a = father[a];
    father[z] = x;
  }
  return x;
}
void Union(int a, int b){
  int fa = findfather(a);
  int fb = findfather(b);
  if(fa != fb){
    father[fa] = fb;
  }
}
int main() {
  for(int i = 0; i < 10010; i++){
    father[i] = i;
  }
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    int k, first, id;
    scanf("%d", &k);
    for(int j = 0; j < k; j++){
      scanf("%d", &id);
      if(j == 0) first = id;
      Union(id, first);
      maxid = max(maxid, id);
    }
  }
  bool isfather[10010] = {false};
  int ans = 0;
  for(int i = 1; i <= maxid; i++){
    isfather[findfather(i)] = true;
  }
  for(int i = 1; i <= maxid; i++){
    if(isfather[i] == true) ans++;
  }
  printf("%d %d\n", ans, maxid);
  scanf("%d", &q);
  for(int i = 0; i < q; i++){
    int q1, q2;
    scanf("%d%d", &q1, &q2);
    if(findfather(q1) == findfather(q2)) printf("Yes\n");
    else printf("No\n");
  }
  return 0;
}
