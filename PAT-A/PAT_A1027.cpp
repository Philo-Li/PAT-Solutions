#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
//A1027 Colors in Mars -2nd
string change(int x){
  int a = x / 13, b = x % 13;
  string temp;
  temp = temp + (char)(a >= 10 ? (a - 10 + 'A'):(a + '0'));
  temp += (char)(b >= 10 ? (b - 10 + 'A') : (b + '0'));
  return temp;
}
int main() {
  int r, g, b;
  scanf("%d %d %d", &r, &g, &b);
  cout << "#" << change(r) << change(g) << change(b) << endl;
  return 0;
}


// #define _CRT_SECURE_NO_WARNINGS
// #include <cstdio>
// #include <cstdlib>
// #include <cstring>
// using namespace std;
// const int D = 13; //13 进制
// int main(){
//     int C[3];
//     int result[2];
//     char map[] = {'A', 'B', 'C'};
//     scanf("%d %d %d", &C[0], &C[1], &C[2]);
//     printf("#");
//     for(int i = 0; i < 3; i++){
//         result[0] = C[i] / D;
//         result[1] = C[i] % D;
//         for(int j = 0; j < 2; j++){
//             if(result[j] < 10) printf("%d", result[j]);
//             else printf("%c", map[result[j]-10]);
//         }
//     }
//     system("pause");
//     return 0;
// }
