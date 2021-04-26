#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
//A1078
bool isPrime(int n){
  if(n <= 1) return false;
  for(int i = 2; i <= sqrt(n); i++){
    if(n % i == 0) return false;
  }
  return true;
}
int main(){
  int m, n;
  bool hashtable[100010] = {0};
  scanf("%d%d", &m, &n);
  while(!isPrime(m)){
    m++;
  }
  // printf("%d\n", m);
  int i;
  for(i = 0; i < n; i++){
    int temp, pos, step;
    scanf("%d", &temp);
    pos = temp % m;
    if(hashtable[pos] == false) {
      hashtable[pos] = true;
      if(i == 0) printf("%d", pos);
      else printf(" %d", pos);
    }
    else{
      for(step = 1; step < m; step++){
        pos = (temp + step * step) % m;
        // 用pos是错的，妈的找了半天
        // pos = (pos + step * step) % m;
        if(hashtable[pos] == false) {
          hashtable[pos] = true;
          if(i == 0) printf("%d", pos);
          else printf(" %d", pos);
          break;
        }
      }
      if(step >= m) {
        if(i == 0) printf("-");
        else printf(" -");
      }
    }
  }
  return 0;
}
