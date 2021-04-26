#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;
//A1107 Social Clusters
const int maxn = 1010;
int father[maxn];
int isroot[maxn] = {0};
int course[maxn] = {0};
int findfather(int x){
  int a = x;
  while(x != father[x]){
    x = father[x];
  }
  while(a != father[a]){//压缩路径
    int z = a;
    a = father[a];
    father[z] = x;
  }
  return x;
}
void Union(int a, int b){
  int faA = findfather(a);
  int faB = findfather(b);
  if(faA != faB) father[faA] = faB;
}
void init(int n){
  for(int i = 1; i <= n; i++){
    father[i] = i;
    isroot[i] = false;
  }
}
bool cmp(int a, int b) { return a > b; }
int main() {
  int n, num, k;
  scanf("%d", &n);
  init(n);
  for(int i = 1; i <= n; i++){
    scanf("%d:", &num);
    for(int j = 0; j < num; j++){
      scanf("%d", &k);
      if(course[k] == 0) course[k] = i;
      Union(i, findfather(course[k]));
    }
  }
  for(int i = 1; i <= n; i++){
    isroot[findfather(i)]++;
  }
  int ans = 0;
  for(int i = 1; i <= n; i++){
    if(isroot[i] != 0) ans++;
  }
  printf("%d\n", ans);
  sort(isroot + 1, isroot + n + 1, cmp);
  for(int i = 1; i <= ans; i++){
    if(i != 1) printf(" ");
    printf("%d", isroot[i]);
  }
  return 0;
}
