#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cctype>
#include <string>
#include <iostream>
#include <queue>
using namespace std;
//A1110 Complete Binary Tree
int main() {
  bool isroot[25] = {false}, flag = true;
  int n, node[25][2], root, cnt = 0, last = -1;
  cin >> n;
  for(int i = 0; i < n; i++){
    string l, r;
    cin >> l >> r;
    if(l == "-") node[i][0] = -1;
    else {
      node[i][0] = stoi(l);
      isroot[stoi(l)] = true;
    }
    if(r == "-") node[i][1] = -1;
    else{
      node[i][1] = stoi(r);
      isroot[stoi(r)] = true;
    }
  }
  for(int i = 0; i < n; i++){
    if(!isroot[i]){
      root = i; break;
    }
  }
  queue<int> q;
  q.push(root);
  while(!q.empty()){
    int top = q.front();
    q.pop();
    if(top != -1){
      last = top;
      cnt++;
    }else{
      if(cnt != n) flag = false;
      break;
    }
    q.push(node[top][0]);
    q.push(node[top][1]);
  }
  if(!flag) printf("NO %d\n", root);
  else printf("YES %d\n", last);
  return 0;
}


//我知道为什么怎么改都不对了，干嘛用char啊，谁说只有一位数的。。。
// #define _CRT_SECURE_NO_WARNINGS
// #include <cstdio>
// #include <cctype>
// #include <queue>
// using namespace std;
// //A1110 Complete Binary Tree
// int main() {
//   bool isroot[25] = {false}, flag = true;
//   int n, node[25][2], root, cnt = 0, last = -1;
//   char l, r;
//   scanf("%d", &n);
//   for(int i = 0; i < n; i++){
//     getchar();
//     scanf("%c %c", &l, &r);    //10你就死了
//     node[i][0] = isdigit(l)?(int)(l - '0') : -1;
//     node[i][1] = isdigit(r) ? (int)(r - '0') : -1;
//     if(isdigit(l)) isroot[(int)(l - '0')] = true;
//     if(isdigit(r)) isroot[(int)(r - '0')] = true;
//   }
//   for(int i = 0; i < n; i++){
//     if(!isroot[i]){
//       root = i; break;
//     }
//   }
//   queue<int> q;
//   q.push(root);
//   while(!q.empty()){
//     int top = q.front();
//     q.pop();
//     if(top != -1){
//       last = top;
//       cnt++;
//     }else{
//       if(cnt != n) flag = false;
//       break;
//     }
//     q.push(node[top][0]);
//     q.push(node[top][1]);
//   }
//   if(!flag) printf("NO %d\n", root);
//   else printf("YES %d\n", last);
//   return 0;
// }
