#include <iostream>
#include <string>
using namespace std;
int main(){
  string str;
  int n;
  cin >> str >> n;
  while(--n){
    string temp, temp2;
    while(!str.empty()){
      temp += str[0];
      int cnt = 0;
      while(!str.empty() && str[0] == temp.back()){
        str.erase(str.begin());
        cnt++;
      }
      temp += to_string(cnt);
    }
    str = temp;
  }
  cout << str << endl;
  return 0;
}


// #include <cstdio>
// #include <queue>
// #include <iostream>
// using namespace std;
// //B1084 外观数列
// int main() {
//   int n, k;
//   queue<int> q;
//   cin >> k >> n;
//   q.push(k);
//   for(int i = 0; i < n - 1; i++){
//     int len = q.size();
//     while(len > 0){
//       int cnt = 0, front = q.front();
//       while(len > 0 && q.front() == front){
//         cnt++;
//         len--;
//         // printf("i:%d q.front:%d cnt:%d len:%d\n", i, q.front(), cnt, len);
//         q.pop();
//       }
//       q.push(front);
//       q.push(cnt);
//     }
//   }
//   while(!q.empty()){
//     printf("%d", q.front());
//     q.pop();
//   }
//   return 0;
// }
