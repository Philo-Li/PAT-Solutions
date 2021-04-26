#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;
//A1045 Favorite Color Stripe 最长公共子序列
const int maxn = 210;
int main() {
  int n, m, l, dp[maxn][maxn] = {{0}};
  int A[10010], B[10010];
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= m; i++){
    scanf("%d", &A[i]);
  }
  scanf("%d", &l);
  for(int i = 0; i < l; i++){
    scanf("%d", &B[i]);
  }
  for(int i = 0; i <= m; i++) dp[i][0] = 0;
  for(int i = 0; i <= l; i++) dp[0][i] = 0;
  for(int i = 1; i <= m; i++){
    for(int j = 1; j <= l; j++){
      int MAX = max(dp[i-1][j], dp[i][j-1]);
      if(A[i] == B[j]) dp[i][j] = MAX + 1;
      else dp[i][j] = MAX;
    }
  }
  printf("%d\n", dp[m][l]);
  return 0;
}
