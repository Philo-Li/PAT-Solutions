#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <math.h>
#include <iostream>
using namespace std;
//A1009	Product of Polynomials
int main() {
  int n1, n2, a, cnt = 0;
  scanf("%d", &n1);
  double b, arr[1001] = {0.0}, ans[2001] = {0.0};
  for(int i = 0; i < n1; i++) {
    scanf("%d %lf", &a, &b);
    arr[a] = b;
  }
  scanf("%d", &n2);
  for(int i = 0; i < n2; i++) {
    scanf("%d %lf", &a, &b);
    for(int j = 0; j < 1001; j++)
      ans[j + a] += arr[j] * b;
  }
  for(int i = 2000; i >= 0; i--)
    if(ans[i] != 0.0) cnt++;
  printf("%d", cnt);
  for(int i = 2000; i >= 0; i--)
    if(ans[i] != 0.0)
      printf(" %d %.1f", i, ans[i]);
  return 0;
}
//2ed
// #define _CRT_SECURE_NO_WARNINGS
// #include <cstdio>
// #include <iostream>
// #include <algorithm>
// using namespace std;
// //A1009 Product of Polynomials
// int main() {
//   double product[2010] = {0.0}, A[1010] = {0.0} ,x;
//   int n, m, e, cnt = 0;
//   scanf("%d", &n);
//   for(int i = 0; i < n; i++){
//     scanf("%d %lf", &e, &x);
//     A[e] += x;
//   }
//   scanf("%d", &m);
//   for(int i = 0; i < m; i++){
//     scanf("%d %lf", &e, &x);
//     for(int j = 0; j < 1010; j++){
//       product[j + e] += A[j] * x;
//     }
//   }
//   for(int i = 0; i < 2010; i++){
//     if(product[i] != 0) cnt++;
//   }
//   printf("%d", cnt);
//   for(int i = 2000; i >= 0; i--){
//     if(product[i] != 0) printf(" %d %.1lf", i, product[i]);
//   }
//   return 0;
// }


// #define _CRT_SECURE_NO_WARNINGS
// #include <cstdio>
// #include <cstdlib>
// #include <cstring>
// #include <math.h>
// const double eps = 0.00001;
// struct PN{
//   int up;
//   double down;
// }PN1[1000], PN2[1000];
// int main(){
//   int K1, K2, num = 0;
//   double PN3[2001] = {0.0};
//   scanf("%d", &K1);
//   for(int i = 0; i < K1; i++){
//     scanf("%d %lf", &PN1[i].up, &PN1[i].down);
//   }
//   scanf("%d", &K2);
//   for(int i = 0; i < K2; i++) {
//     scanf("%d %lf", &PN2[i].up, &PN2[i].down);
//     for(int j = 0; j < K1; j++){
//       int up = PN1[j].up + PN2[i].up;
//       double down = PN1[j].down * PN2[i].down;
//       PN3[up] += down;
//     }
//   }
//   for(int i = 0; i < 2000; i++){
//     if(abs(PN3[i]) > eps) {
//       num++;
//     }
//   }
//   printf("%d", num);
//   for(int i = 2000; i >= 0; i--){
//     if(abs(PN3[i]) > eps)
//     {
//       printf(" %d %.1lf", i, PN3[i]);
//     }
//   }
//   return 0;
// }
