#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
//A1105_B1050 Spiral Matrix
const int maxn = 10010;
int A[maxn], N;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
bool vis[maxn][maxn] = {{false}};
bool cmp(int a, int b){ return a > b;}
int main(){
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    scanf("%d", &A[i]);
  }
  sort(A, A + N, cmp);
  int n = (int)sqrt(1.0 * N);
  while(N % n != 0) n--;
  int m = N / n, matrix[m][n];
  bool vis[m][n];
  memset(vis, false, sizeof(vis));
  int i = 0, j = 0, now = 0, nd = 0;
  while(now < N){
    matrix[i][j] = A[now++];
    vis[i][j] = true;
    int ni = i + dx[nd], nj = j + dy[nd];
    if(ni < 0 || ni >= m || nj < 0 || nj >= n || vis[ni][nj]){
      nd = (nd + 1) % 4;
    }
    i += dx[nd];
    j += dy[nd];
  }
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      if(j != 0) printf(" ");
      printf("%d", matrix[i][j]);
    }
    printf("\n");
  }
  return 0;
}
// 乙级有一个测试点超时，甲级能过。。。
// #define _CRT_SECURE_NO_WARNINGS
// #include <cstdio>
// #include <cmath>
// #include <algorithm>
// using namespace std;
// //A1105 Spiral Matrix
// const int maxn = 10010;
// int matrix[maxn][maxn], A[maxn], N;
// bool cmp(int a, int b){ return a > b;}
// int main(){
//   scanf("%d", &N);
//   for(int i = 0; i < N; i++){
//     scanf("%d", &A[i]);
//   }
//   if(N == 1){
//     printf("%d\n", A[0]);
//     return 0;
//   }
//   sort(A, A + N, cmp);
//   int n = (int)sqrt(1.0 * N), m;
//   while(N % n != 0) n--;
//   m = N / n;
//   int i = 1, j = 1, now = 0;
//   int U = 1, D = m, L = 1, R = n;
//   while(now < N){
//     while(now < N && j < R){
//       matrix[i][j] = A[now++];
//       j++;
//     }
//     while(now < N && i < D){
//       matrix[i][j] = A[now++];
//       i++;
//     }
//     while(now < N && j > L){
//       matrix[i][j] = A[now++];
//       j--;
//     }
//     while(now < N && i > U){
//       matrix[i][j] = A[now++];
//       i--;
//     }
//     U++, D--, L++, R--, i++, j++;
//     if(now == N - 1) matrix[i][j] = A[now++];
//   }
//   for(int i = 1; i <= m; i++){
//     for(int j = 1; j <= n; j++){
//       if(j != 1) printf(" ");
//       printf("%d", matrix[i][j]);
//     }
//     printf("\n");
//   }
//   return 0;
// }
