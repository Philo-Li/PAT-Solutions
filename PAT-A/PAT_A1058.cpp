#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;
//A1058 A+B in Hogwarts -2nd
int main() {
  int g1, s1, k1, g2, s2, k2, r1, r2;
  scanf("%d.%d.%d %d.%d.%d", &g1, &s1, &k1, &g2, &s2, &k2);
  r1 = (k1 + k2) / 29;
  k1 = (k1 + k2) % 29;
  r2 = (s1 + s2 + r1) / 17;
  s1 = (s1 + s2 + r1) % 17;
  g1 = g1 + g2 + r2;
  printf("%d.%d.%d\n", g1, s1, k1);
  return 0;
}


// #define _CRT_SECURE_NO_WARNINGS
// #include <cstdio>
// #include <cstdlib>
// #include <cstring>
// using namespace std;
// //Seventeen silver Sickles to a Galleon
// //and twenty-nine Knuts to a Sickle
// int main(){
//     int A[3], B[3], r = 0;
//     long long C[3]={0};
//     int D[3] = {1, 17, 29};
//     scanf("%d.%d.%d", &A[0], &A[1], &A[2]);
//     scanf("%d.%d.%d", &B[0], &B[1], &B[2]);
//     for(int i = 2; i >= 0; i--){
//         long long sum = A[i] + B[i];
//         if(i == 0) C[i] = sum + r;
//         else C[i] = (sum + r) % D[i];
//         r = (sum + r) / D[i];
//     }
//     // C[2] = (A[2] + B[2]) % 29;
//     // r = (A[2] + B[2]) / 29;
//     // C[1] = (A[1] + B[1] + r) % 17;
//     // r = (A[1] + B[1] + r) / 17;
//     // C[0] = A[0] + B[0] + r;
//     printf("%lld.%lld.%lld\n", C[0], C[1], C[2]);
//     system("pause");
//     return 0;
// }
