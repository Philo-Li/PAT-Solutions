#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;
//A1070_B1020 Mooncake
struct Cake{
  double weight;
  double money;
  double pt;
}cake[1010];
bool cmp(Cake a, Cake b){
  return a.pt > b.pt;
}
int main(){
    int n;
    double k, sum = 0.0;
    scanf("%d %lf", &n, &k);
    for(int j = 0; j < n; j++){
      scanf("%lf", &cake[j].weight);
    }
    for(int j = 0; j < n; j++){
      scanf("%lf", &cake[j].money);
      cake[j].pt = cake[j].money / cake[j].weight;
    }
    sort(cake, cake + n, cmp);
    int cnt = 0;
    while(k!=0 && cnt < n){
      if(k < cake[cnt].weight){
          sum = sum + k * cake[cnt].pt;
          k = 0;
      }
      else{
        sum = sum + cake[cnt].money;
        k = k - cake[cnt].weight;
      }
      cnt++;
    }
    printf("%.2lf", sum);
    return 0;
}
