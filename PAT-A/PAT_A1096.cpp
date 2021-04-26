#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
//A1096 Consecutive Factors
int ansLen = 0, ansI, n;
int main(){
  cin >> n;
  long long fact = 1;
  for(int i = 2; i <= sqrt(n); i++ ){
    int j = i; fact = 1;
    while(1) {
      fact *= j;
      if(n % fact != 0) break;
      if(j - i + 1 > ansLen){
        ansI = i;
        ansLen = j - i + 1;
      }
      j++;
    }
  }
  if(ansLen == 0) printf("1\n%d", n);
  else{
    printf("%d\n", ansLen);
    for(int i = 0; i < ansLen; i++){
      if(i != 0) printf("*");
      printf("%d", ansI + i);
    }
  }
  return 0;
}
