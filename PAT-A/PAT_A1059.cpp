#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
//A1059 Prime Factors
long int n;
int cnt = 0,factor[100010] = {0}, flag = 0;
int main(){
  cin >> n;
  cout << n << '=';
  long int sqr = (long int)sqrt(n);
  for(long int i = 2; i <= sqr; i++){
    cnt = 0;
    if(n % i == 0){
      if(flag) printf("*");
      printf("%ld", i);
      while(n % i == 0){
        cnt++; n = n / i;
      }
      if(cnt > 0) flag = 1;
    }
    if(cnt > 1) printf("^%d", cnt);
  }
  if(!flag) printf("%ld\n", n);
  return 0;
}
