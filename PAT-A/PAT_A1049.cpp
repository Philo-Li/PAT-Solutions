#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
//A1032 Sharing
int pos1, pos2, n, list[100010], pos = -1;
char D[100010];
void GetPath(int pos, vector<int> &path){
  while(pos != -1){
    path.push_back(pos);
    pos = list[pos];
  }
  reverse(path.begin(), path.end());
}
int main() {
  scanf("%d %d %d", &pos1, &pos2, &n);
  for(int i = 0; i < n; i++){
    int address, v, next;
    scanf("%d %c %d", &address, &D[i], &next);
    list[address] = next;
  }
  vector<int> path1, path2;
  GetPath(pos1, path1);
  GetPath(pos2, path2);
  for(int i = 0; i < min(path1.size(), path2.size()); i++){
    if(path1[i] == path2[i]) pos = path1[i];
  }
  if(pos != -1) printf("%05d\n", pos);
  else printf("%d\n", pos);
  return 0;
}


// #define _CRT_SECURE_NO_WARNINGS
// #include <cstring>
// #include <cstdio>
// #include <iostream>
// #include <string>
// #include <cctype>
// #include <algorithm>
// #include <queue>
// using namespace std;
// //A1049 Counting Ones
// int main(){
//     int n, ans = 0, a = 1;
//     int left, now, right;
//     scanf("%d", &n);
//     while(n / a != 0){
//       left = n / (a * 10);
//       now = n / a % 10;
//       right = n % a;
//       if(now == 0) ans += left * a;
//       else if( now == 1) ans += left * a + right + 1;
//       else ans += (left + 1) * a;
//       a *= 10;
//     }
//     printf("%d\n", ans);
//     return 0;
// }
// // time out...
// // int main(){
// //     int n, ans = 0;
// //     while(scanf("%d", &n)!= EOF){
// //       ans = 0;
// //       string temp;
// //       for(int i = 1; i <= n; i++){
// //         temp = to_string(i);
// //         int pos = temp.find('1');
// //         while(pos != std::string::npos) {
// //           ans++;
// //           pos = temp.find('1', pos + 1);
// //         }
// //       }
// //       // cout << ans << '\n';
// //     }
// //     printf("%d\n", ans);
// //     return 0;
// // }
