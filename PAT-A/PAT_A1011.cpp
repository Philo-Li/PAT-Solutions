#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
//A1011 World Cup Betting
int main() {
  int bet[3] = {0};
  char mm[] = {'W', 'T', 'L'};
  double profit = 1.0, d[3][3];
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      scanf("%lf", &d[i][j]);
      if(d[i][j] > d[i][bet[i]]) bet[i] = j;
    }
    profit *= d[i][bet[i]];
  }
  profit = (profit * 0.65 - 1) * 2;
  printf("%c %c %c %.2lf\n", mm[bet[0]], mm[bet[1]], mm[bet[2]], profit);
  return 0;
}

// #define _CRT_SECURE_NO_WARNINGS
// #include <cstdio>
// #include <cstdlib>
// #include <cstring>
// using namespace std;
// int main(){
//     char map[3] = {'W', 'T', 'L'};
//     double Result[3][3] = {0.0};
//     double Max[3][2];
//     for(int i = 0; i < 3; i++){
//         for(int j = 0; j < 3; j++){
//             scanf("%lf", &Result[i][j]);
//             if(j == 0){
//                 Max[i][0] = j;
//                 Max[i][1] = Result[i][j];
//             }
//             else{
//                 if(Max[i][1] < Result[i][j]){
//                     Max[i][1] = Result[i][j];
//                     Max[i][0] = j;
//                 }
//             }
//         }
//     }
//     for(int i = 0; i < 3; i++){
//         int k = Max[i][0];
//         printf("%c ", map[k]);
//     }
//     double profit = (Max[0][1] * Max[1][1] * Max[2][1] * 0.65 - 1) * 2;
//     printf("%.2f\n", profit);
//     system("pause");
//     return 0;
// }
