#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
//A1040 Longest Symmetric String
//自己写的的相当于two pointer方法，能过
// string s;
// int ans = 1, len, temp;
// void getlen(int i, int flag){
//   if(i + 1 + flag >= len) return;
//   int l = i, r = i + 1 + flag, temp = 1;
//   while(l >= 0 && r < len && s[l] == s[r]){
//     temp = r - l + 1;
//     l--; r++;
//   }
//   ans = max(ans, temp);
// }
// int main() {
//   getline(cin, s);
//   len = s.length();
//   for(int i = 0; i < len; i++){
//     getlen(i, 0);
//     getlen(i, 1);
//   }
//   printf("%d\n", ans);
//   return 0;
// }

const int maxn = 1010;
int main() {
  string s;
  getline(cin, s);
  int dp[maxn][maxn] = {{0}}, len = s.length(), ans = 1;
  for(int i = 0; i < len; i++){
    dp[i][i] = 1;
    if(i < len - 1 && s[i] == s[i+1]){
      dp[i][i + 1] = 1;
      ans = 2;
    }
  }
  for(int l = 3; l <= len; l++){
    for(int i = 0; i + l - 1 < len; i++){
      int j = i + l - 1;
      if(s[i] == s[j] && dp[i+1][j-1] == 1){
        dp[i][j] = 1;
        ans = l;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
