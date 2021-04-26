#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;
//A1046 Shortest Distance
int n, m, st, ed, dis[100010] = {0};
int main() {
  scanf("%d %d", &n, &dis[1]);
  for(int i = 2; i <= n; i++){
    scanf("%d", &dis[i]);
    dis[i] += dis[i - 1];
  }
  scanf("%d", &m);
  for(int i = 0; i < m; i++){
    scanf("%d %d", &st, &ed);
    if(st > ed) swap(st, ed);
    int mindis = min(abs(dis[ed - 1] - dis[st-1]), abs(dis[n] - dis[ed - 1] + dis[st - 1]));
    printf("%d\n", mindis);
  }
  return 0;
}


// #define _CRT_SECURE_NO_WARNINGS
// #include <cstdio>
// #include <cstdlib>
// #include <cstring>
// // A1046
// int main(){
//     int N, M, Num = 0, D_all = 0;
//     int D[100001] = {0}, Distance_M[10001] = {0};
//     scanf("%d", &N);
//     for(int i = 0, temp; i < N; i++){
//         scanf("%d", &temp);
//         D_all += temp;
//         D[i] = D_all;
//         Num++;
//     }
//     scanf("%d", &M);
//     for(int i = 0; i < M; i++){
//         int Point_A, Point_B, D_AB_1 = 0, D_AB_2 = 0;
//         scanf("%d %d", &Point_A, &Point_B);
//         if(Point_A > Point_B){
//             int temp = Point_A;
//             Point_A = Point_B;
//             Point_B = temp;
//         }
//         D_AB_1 = D[Point_B-1] - D[Point_A-1];
//         D_AB_2 = D_all - D_AB_1;
//         Distance_M[i] = (D_AB_1 > D_AB_2 ? D_AB_2 : D_AB_1);
//     }
//     for(int i = 0; i < M; i++){
//         printf("%d\n", Distance_M[i]);
//     }
//     system("pause");
//     return 0;
// }
