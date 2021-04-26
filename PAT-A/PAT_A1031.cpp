#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//A1031 Hello World for U  -2nd
int main() {
  int n1, n2;
  string str, ans;
  cin >> str;
  n1 = (str.length() + 2 ) / 3;
  n2 = str.length() + 2 - 2 * n1;
  while(str.length() > n2){
    ans = str[0];
    while(ans.length() < n2 - 1) ans += " ";
    ans += str[str.length() - 1];
    cout << ans << endl;
    str = str.substr(1, str.length() - 2);
  }
  cout << str << endl;
  return 0;
}


// #define _CRT_SECURE_NO_WARNINGS
// #include <cstdio>
// #include <cstdlib>
// #include <cstring>
// using namespace std;
// int main(){
//   char str[81];
//   int cnt = 0;
//   scanf("%s", str);
//   int len = strlen(str);
//   int r = (len + 2) % 3;
//   int n1 = (len + 2 - r) / 3;
//   int n2 = len - 2 * (n1 - 1);
//   int n3 = n1;
//   for(int i = 0; i < n1; i++){
//     for(int j = 0; j < n2; j++){
//       if(i != n1 - 1){
//         if(j == 0) printf("%c", str[cnt]);
//         else if(j == n2 - 1) printf("%c", str[len - 1 - cnt]);
//         else printf(" ");
//       }
//       else if(i == n1 - 1){
//         printf("%c", str[cnt++]);
//       }
//     }
//     printf("\n"); cnt++;
//   }
//   return 0;
// }
