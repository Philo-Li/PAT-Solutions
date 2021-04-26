#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;
//A1037 Magic Coupon
bool cmp(int a, int b){
  return a > b;
}
int main(){
    int money = 0;
    int NC, NP, c[100010], p[100010];
    scanf("%d", &NC);
    for(int i = 0; i < NC; i++){
      scanf("%d", &c[i]);
    }
    scanf("%d", &NP);
    for(int i = 0; i < NP; i++){
      scanf("%d", &p[i]);
    }
    sort(c, c + NC, cmp);
    sort(p, p + NP, cmp);
    for(int i = 0; i < NC; i++){
      if(c[i] > 0 && p[i] > 0) money += c[i]*p[i];
      else if(c[i] < 0){
        int k = NP - 1;
        for(int j = NC - 1; j >= i && k >= 0; j--){
          if(c[j] < 0 && p[k] < 0){
            money += c[j] * p[k]; k--;
          }
        }
        break;
      }
    }
    printf("%d", money);
    return 0;
}
