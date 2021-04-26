#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <map>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//A1007 Maximum Subsequence Sum
int main() {
  int n, dp[100010], k = 0, l = -1;
  int flag = 0, data[100010];
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &data[i]);
    if(data[i] >= 0) flag = 1;
  }
  dp[0] = data[0];
  for(int i = 1; i < n; i++){
    dp[i] = max(data[i], dp[i - 1] + data[i]);
    if(dp[i] > dp[k]) k = i;
  }
  for(int i = k; i >= 0; i--){
    if(dp[i] < 0){
      l = i; break;
    }
  }
  if(dp[l] < 0) l++;
  else if (l == -1) l = 0;
  if(flag == 0) printf("0 %d %d\n", data[0], data[n-1]);
  else{
    printf("%d %d %d\n", dp[k], data[l], data[k]);
  }
  return 0;
}

// int main() {
//     int n;
//     scanf("%d", &n);
//     vector<int> v(n);
//     int leftindex = 0, rightindex = n - 1, sum = -1, temp = 0, tempindex = 0;
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &v[i]);
//         temp = temp + v[i];
//         if (temp < 0) {
//             temp = 0;
//             tempindex = i + 1;
//         } else if (temp > sum) {
//             sum = temp;
//             leftindex = tempindex;
//             rightindex = i;
//         }
//     }
//     if (sum < 0) sum = 0;
//     printf("%d %d %d", sum, v[leftindex], v[rightindex]);
//     return 0;
// }
