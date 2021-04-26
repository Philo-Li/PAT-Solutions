#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cstdio>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
//A1104_B1049 Sum of Number Segments
const int maxn = 100010;
int n;
double v, ans = 0;
int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    scanf("%lf", &v);
    ans += v * i * (n - i + 1);
  }
  printf("%.2lf", ans);
  return 0;
}
