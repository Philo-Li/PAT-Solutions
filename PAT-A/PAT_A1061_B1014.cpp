#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <cctype>
#include <iostream>
#include <algorithm>
using namespace std;
//A1061 Dating -2nd
int main() {
  string str1, str2;
  int day, hh = -1, mm, flag = 0;
  char week[][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
  cin >> str1 >> str2;
  for(int i = 0; i < min(str1.length(), str2.length()); i++){
    if(flag == 0 && str1[i] == str2[i] && str1[i] >= 'A' && str1[i] <= 'G'){
      day = (int)(str1[i] - 'A');
      flag = 1; i++;
    }
    if(flag == 1 && str1[i] == str2[i]){
      if(str1[i] >= '0' && str1[i] <= '9'){
        hh = (int)(str1[i] - '0');
      }else if(str1[i] >= 'A' && str1[i] <= 'N'){
        hh = (int)(str1[i] - 'A' + 10);
      }
      if(hh != -1) break;
    }
  }
  cin >> str1 >> str2;
  for(int i = 0; i < min(str1.length(), str2.length()); i++){
    if(str1[i] == str2[i] && isalpha(str1[i])){
      mm = i; break;
    }
  }
  printf("%s %02d:%02d\n", week[day], hh, mm);
  return 0;
}


// #define _CRT_SECURE_NO_WARNINGS
// #include <cstdio>
// #include <cstring>
// #include <iostream>
// #include <string>
// #include <cctype>
// #include <vector>
// #include <algorithm>
// using namespace std;
// //A1061_B1014 Dating
//
// int main() {
//   char week[][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
//   char str1[81], str2[81];
//   int dd, mm, hh, cnt = 0;
//   scanf("%s%s", str1, str2);
//   for(int i = 0; i < strlen(str1) && i < strlen(str2); i++){
//     if(str1[i] == str2[i]){
//       if(cnt == 0 && str1[i] == str2[i] && str1[i]>= 'A' && str1[i] <= 'G'){
//         dd = (int)(str1[i] - 'A');
//         cnt++;
//       }else if(cnt == 1){//cnt is important
//         if(isdigit(str1[i])) {
//           hh = (int)(str1[i] - '0');
//           break;// break is important
//         }
//         else if(str1[i] >= 'A' && str1[i] <= 'N'){
//           hh = (int)(str1[i] - 'A') + 10;
//           break;
//       }
//       }
//     }
//   }
//   scanf("%s%s", str1, str2);
//   for(int i = 0; i < strlen(str1) && i < strlen(str2); i++){
//     if(str1[i] == str2[i] && isalpha(str1[i])){
//         mm = i; break;
//     }
//   }
//   printf("%s %02d:%02d\n", week[dd], hh, mm);
//   return 0;
// }
