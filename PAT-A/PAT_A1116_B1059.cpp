#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cctype>
#include <string>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
//A1116 Come on! Let's C  /B1059 C语言竞赛
int n, k, p[10010] = {0}, id, checked[10010] = {false};
bool isprime(int x){
  for(int i = 2; i * i <= x; i++){//=不能少
    if(x % i == 0) return false;
  }
  return true;
}
int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    scanf("%d", &id);
    p[id] = i;
  }
  scanf("%d", &k);
  for(int i = 0; i < k; i++){
    scanf("%d", &id);
    printf("%04d: ", id);
    if(p[id] == 0) printf("Are you kidding?\n");
    else if(!checked[id]){
      if(p[id] == 1) printf("Mystery Award\n");
      else if(isprime(p[id])) printf("Minion\n");
      else printf("Chocolate\n");
      checked[id] = true;
    }else if(checked[id]) printf("Checked\n");
  }
  return 0;
}
