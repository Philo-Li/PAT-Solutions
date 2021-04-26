#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
//A1054 The Dominant Color
const int D = pow(2, 24) + 1;
int m, n, hashtable[D] = {0}, maxn = 0, maxkey;
int main(){
  scanf("%d%d", &m, &n);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      int temp;
      scanf("%d", &temp);
      hashtable[temp % D]++;
      if(hashtable[temp % D] > maxn){
        maxkey = temp % D;
        maxn = hashtable[maxkey];
      }
    }
  }
  printf("%d", maxkey);
  return 0;
}
