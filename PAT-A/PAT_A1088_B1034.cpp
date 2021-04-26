#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
#define LL long long
//A1088_B1034 有理数四则运算
LL a1, a2, b1, b2, n;
LL gcd(LL a, LL b){
  return b == 0 ? abs(a) : gcd(b, a % b);
}
void print(LL a, LL b){
  LL integer = a / b;
  if(a < 0) printf("(");
  a = a - integer * b;
  if(integer == 0 && a == 0) printf("0");
  if(integer != 0 && a == 0) printf("%lld", integer);
  if(integer == 0 && a != 0) printf("%lld/%lld", a, b);
  if(integer != 0 && a != 0) printf("%lld %lld/%lld", integer, abs(a), b);
  if(a < 0 || integer < 0) printf(")");
}
void cal(LL &c1, LL &c2, int i){
  LL temp;
  if(i == 0 || i == 1){
    temp = gcd(a2, b2);
    if(i == 1) c1 = a1 * b2 - a2 * b1;
    else c1 = a1 * b2 + a2 * b1;
    c2 = a2 * b2;
  }
  else if(i == 2){
    c1 = a1 * b1;
    c2 = a2 * b2;
  }
  else{
    c1 = a1 * b2;
    c2 = a2 * b1;
  }
  if(c2 < 0){
    c1 = -c1; c2 = -c2;
  }
  if(c1 == 0){
    c1 = 0; c2 = 1;
  }else{
    temp = gcd(c1, c2);
    c1 = c1 / temp;
    c2 = c2 / temp;
  }
}
int main(){
  char map[4] = {'+', '-', '*', '/'};
  LL c1 = 0, c2 = 1;
  scanf("%lld/%lld %lld/%lld", &a1, &a2, &b1, &b2);
  LL temp1, temp2;
  if(a1 == 0){
    a1 = 0, a2 = 1;
  }else{
    temp1 = gcd(a1, a2);
    a1 = a1 / temp1; a2 = a2 / temp1;
  }
  if(b1 == 0){
    b1 = 0, b2 = 1;
  }else{
    temp2 = gcd(b1, b2);
    b1 = b1 / temp2; b2 = b2 / temp2;
  }
  for(int i = 0; i < 4; i++){
    print(a1, a2);
    printf(" %c ", map[i]);
    if(b1 == 0) printf("0");
    else print(b1, b2);
    printf(" = ");
    if(i == 3 && b1 == 0) printf("Inf");
    else {
      cal(c1, c2, i);
      print(c1, c2);
    }
    printf("\n");
  }
  return 0;
}
