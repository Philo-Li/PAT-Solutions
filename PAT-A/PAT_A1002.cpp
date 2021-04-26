#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
//A1002 A+B for Polynomials
int main() {
  int k, e, cnt = 0;
  double sum[1010] = {0.0}, x;
  for(int i = 0; i < 2; i++){
    scanf("%d", &k);
    for(int j = 0; j < k; j++){
      scanf("%d %lf", &e, &x);
      sum[e] += x;
    }
  }
  for(int i = 0; i < 1010; i++){
    if(sum[i] != 0) cnt++;
  }
  printf("%d", cnt);
  for(int i = 1000; i >= 0; i--){
    if(sum[i] != 0){
      printf(" %d %.1lf", i, sum[i]);
    }
  }
  return 0;
}

// #define _CRT_SECURE_NO_WARNINGS
// #include <cstdio>
// #include <cmath>
// #include <algorithm>
// using namespace std;
// //A1002 A+B
// int main() {
//   int k, e, cnt = 0;
//   double x, sum[1010] = {0.0};
//   for(int j = 0; j < 2; j++){
//     scanf("%d", &k);
//     for(int i = 0; i < k; i++){
//       scanf("%d %lf", &e, &x);
//       sum[e] += x;
//     }
//   }
//   for(int i = 0; i <= 1000; i++) if(abs(sum[i]) >= 0.05) cnt++;
//   printf("%d", cnt);
//   for(int i = 1000; i >= 0; i--){
//     if(abs(sum[i]) >= 0.05) printf(" %d %.1lf", i, sum[i]);
//   }
//   return 0;
// }
