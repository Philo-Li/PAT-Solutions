#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
//A1120_B1064	Friend Numbers 朋友数
int main() {
  int n, num = 0;
  bool h[50] = {false};
  scanf("%d", &n);
  for(int i = 0, temp, sum; i < n; i++, sum = 0){
    scanf("%d", &temp);
    while(temp!=0){
      sum = sum + temp % 10;
      temp /= 10;
    }
    if(h[sum] == false){
      num++;
      h[sum] = true;
    }
  }
  printf("%d\n", num);
  int flag = 0;
  for(int i = 1; i < 50; i++){
    if(h[i]) {
      if(flag != 0) printf(" ");
      printf("%d", i);
      flag++;
    }
  }
  return 0;
}
