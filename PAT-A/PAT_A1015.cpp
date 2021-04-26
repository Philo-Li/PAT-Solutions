#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
//A1015 Reversible Primes
int change(int n, int d){
  int sum = 0;
  while(n != 0){
    sum = sum * d + n % d;
    n = n / d;
  }
  return sum;
}
bool isPrime(int n){
  if(n <= 1) return false;
  for(int i = 2; i <= sqrt(n); i++){
    if(n % i == 0) return false;
  }
  return true;
}
int main(){
  int n, d;
  while(scanf("%d", &n) != EOF){
    if(n < 0) break;
    scanf("%d", &d);
    if(isPrime(n)){
      n = change(n, d);
      if(isPrime(n)) printf("Yes\n");
      else printf("No\n");
      // 妈的你写YES一辈子都过不了
      // if(isPrime(n)) printf("YES\n");
      // else printf("NO\n");
    }
    // else printf("NO\n");
    else printf("No\n");
  }
  return 0;
}
// 我不懂啊，怎么过不了， 进制转换只有那样才行么？
