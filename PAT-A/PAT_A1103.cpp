#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
//A1103 Integer Factorization
int n, k, p, maxsum = -1;
vector <int> temp, ans, fac;
void DFS(int index, int nowk, int factorsum, int value){
  if(nowk == k && value == n){
    if(factorsum > maxsum){
      maxsum = factorsum;
      ans = temp;
    }
    return;
  }
  if(nowk > k || value > n) return;
  if(index - 1 >= 0){
    temp.push_back(index);
    DFS(index, nowk + 1, factorsum + index, value + fac[index]);
    temp.pop_back();
    DFS(index - 1, nowk, factorsum, value);
  }
}
int main() {
  scanf("%d%d%d", &n, &k, &p);
  for(int i = 0; pow(i, p) <= n; i++){
    fac.push_back((float)pow(i, p));
  }
  DFS(fac.size() - 1, 0, 0, 0);
  if(maxsum == -1){
    printf("Impossible\n"); return 0;
  }
  printf("%d = %d^%d", n, ans[0], p);
  for(int i = 1; i < ans.size(); i++){
    printf(" + %d^%d", ans[i], p);
  }
  return 0;
}
