#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
//A1065 A+B and C (64bit)
long long int n, a, b, c;
int main() {
  scanf("%lld", &n);
  for(int i = 1; i <= n; i++){
    bool flag = false;
    scanf("%lld %lld %lld", &a, &b, &c);
    if(a + b > c) flag = true;
    if(a > 0 && b > 0 && a + b <= 0) flag = true;
    else if(a < 0 && b < 0 && a + b >= 0) flag = false;
    printf("Case #%d: %s\n", i, flag == true ? "true":"false");
  }
  return 0;
}

// #define _CRT_SECURE_NO_WARNINGS
// #include <cstdio>
// #include <cstdlib>
// #include <cstring>
// // A + B > C ?
// int main(){
//     long long S[20][3];
//     int N = 0;
//     scanf("%d", &N);
//     for(int i = 0; i < N; i++){
//         scanf("%lld %lld %lld", &S[i][0], &S[i][1], &S[i][2]);
//
//     }
//     for(int i = 0; i < N; i++){
//         long long sum = S[i][0] + S[i][1];
//         bool flag = false;
//         if(S[i][0] < 0 && S[i][1] < 0){
//             if(sum > 0) flag = false;
//         }
//         else if(S[i][0] > 0 && S[i][1] > 0){
//             if(sum < 0 || sum > S[i][2]) flag = true;
//         }
//         else if(sum > S[i][2]) flag = true;
//         if(flag){
//             printf("Case #%d: true\n", i + 1);
//         }
//         else printf("Case #%d: false\n", i + 1);
//     }
//     system("pause");
//     return 0;
// }
