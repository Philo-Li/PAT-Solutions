#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
//A1068 Find More Coins
const int maxn = 10010, maxv = 110;
int n, m, A[maxn], dp[maxv] = {0};
bool flag[maxn] = {false}, choice[maxn][maxv];
vector <int> ans;
bool cmp(int a, int b){ return a > b; }
int main() {
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; i++){
    scanf("%d", &A[i]);
  }
  sort(A + 1, A + n + 1, cmp);
  for(int i = 1; i <= n; i++){
    for(int v = m; v >= A[i]; v--){
      if(dp[v] <= dp[v - A[i]] + A[i]){//放第i件物品
        dp[v] = dp[v - A[i]] + A[i];
        choice[i][v] = 1;
      }else choice[i][v] = 0;
    }
  }
  if(dp[m] != m){ printf("No Solution\n"); }
  else{
    int k = n, v = m;
    while(k >= 0){
      if(choice[k][v] == 1){
        ans.push_back(A[k]);
        v -= A[k];
      }
      k--;
    }
    for(int i = 0; i < ans.size(); i++){
      if(i != 0) printf(" ");
      printf("%d", ans[i]);
    }
  }
  return 0;
}
// 用DFS搜索，最后一个测试点超时
// #define _CRT_SECURE_NO_WARNINGS
// #include <cstdio>
// #include <vector>
// #include <algorithm>
// using namespace std;
// //A1068 Find More Coins
// const int maxn = 10010;
// int n, m, A[maxn], dp[maxn];
// vector<int> ans, temp;
// bool flag[maxn] = {false}, fg = false;
// void DFS(int index, int sum){
//   if(sum == m){
//     ans = temp;
//     fg = true;
//     return;
//   }else if(sum > m || index == n) return;
//   if(!fg) {
//     temp.push_back(A[index]);
//     DFS(index + 1, sum + A[index]);
//     temp.pop_back();
//     DFS(index + 1, sum);
//   }
//   return;
// }
// int main() {
//   scanf("%d%d", &n, &m);
//   for(int i = 0; i < n; i++){
//     scanf("%d", &A[i]);
//   }
//   sort(A, A + n);
//   DFS(0, 0);
//   if(!fg) printf("No Solution\n");
//   else{
//     for(int i = 0; i < ans.size(); i++){
//       if(i != 0) printf(" ");
//       printf("%d", ans[i]);
//     }
//   }
//   return 0;
// }
