#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
//A1081 分数求和
#define LL long long
LL sum = 0, integer, fracup = 0, fracdown = 1, n;
LL gcd(LL a, LL b){
  return b == 0 ? abs(a) : gcd(b, a % b);
}
int main(){
  scanf("%lld", &n);
  for(int i = 0; i < n; i++){
    LL tempup, tempdown;
    scanf("%lld/%lld", &tempup, &tempdown);
    LL temp1 = gcd(tempdown, fracdown);
    fracup = (fracup * tempdown + tempup * fracdown)/temp1;
    fracdown = tempdown * fracdown / temp1;//顺序不能反过来
    LL temp2 = gcd(fracup, fracdown);
    fracup = fracup / temp2;
    fracdown = fracdown / temp2;
    // printf("%lld/%lld %lld/%lld i:%d\n", tempup, tempdown, fracup, fracdown, i);
  }
  integer = fracup / fracdown;
  fracup = fracup % fracdown;
  if(integer == 0 && fracup == 0) printf("0\n");
  if(integer != 0) printf("%lld", integer);
  if(integer != 0 && fracup != 0) printf(" ");
  if(fracup != 0) printf("%lld/%lld\n", fracup, fracdown);
  return 0;
}
