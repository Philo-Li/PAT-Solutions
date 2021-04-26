#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
using namespace std;
//A1048 Find Coins
//更简洁的做法
// int a[1001];
// int main() {
//     int n, m, temp;
//     scanf("%d %d", &n, &m);
//     for(int i = 0; i < n; i++) {
//         scanf("%d", &temp);
//         a[temp]++;
//     }
//     for(int i = 0; i < 1001; i++) {
//         if(a[i]) {
//             a[i]--;
//             if(m > i && a[m-i]) {
//                 printf("%d %d", i, m - i);
//                 return 0;
//             }
//             a[i]++;
//         }
//     }
//     printf("No Solution");
//     return 0;
// }
int main(){
    int n, m;
    int face[510] = {0};
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
      int k = 0;
      scanf("%d", &k);
      face[k]++;
    }
    int i, j;
    bool find = false;
    for(i = 1; !find && i <= 500; i++){
      for(j = i; !find && j <= 500; j++){
        if( face[i] && face[j] && i + j == m){
          if(i == j && face[i] < 2) continue;
          else find = true;
        }
      }
    }
    if(!find) printf("No Solution\n");
    else printf("%d %d", i - 1, j - 1);
    return 0;
}
// 二分法
// const int maxn = 100010;
// int n, m, face[maxn];
// int main() {
//     scanf("%d%d", &n, &m);
//     for(int i = 0; i < n; i++){
//       scanf("%d", &face[i]);
//     }
//     sort(face, face + n);
//     int left, right;
//     for(int i = 0; i < n; i++){
//       left = i + 1, right = n - 1;
//       while(left <= right){
//         int mid = (left + right) / 2;
//         if(face[mid] > m - face[i]) right = mid - 1;
//         else if(face[mid] == m - face[i]) {
//           printf("%d %d", face[i], face[mid]);
//           return 0;
//         }
//         else left = mid + 1;
//       }
//     }
//     printf("No Solution\n");
//     return 0;
// }
// two pointers
// int main() {
//     scanf("%d%d", &n, &m);
//     for(int i = 0; i < n; i++){
//       scanf("%d", &s[i]);
//     }
//     sort(s, s + n);
//     int i = 0, j = n - 1;
//     while(i < n && j >= 0){
//       if(s[i] + s[j] == m){
//         printf("%d %d\n", s[i], s[j]);
//         return 0;
//       }
//       else if(s[i] + s[j] < m) i++;
//       else j--;
//     }
//     printf("No Solution\n");
//     return 0;
// }
