#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;
//A1125_B1070 Chain the Ropes结绳
int main() {
  int n;
  double ans, rope[10010];
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%lf", &rope[i]);
  }
  sort(rope, rope + n);
  ans = rope[0];
  for(int i = 1; i < n; i++){
    ans = (ans + rope[i]) / 2;
  }
  printf("%d", (int)ans);
  return 0;
}
