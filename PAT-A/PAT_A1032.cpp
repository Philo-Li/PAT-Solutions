#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//A1032 Sharing
// struct NODE {
//   char key;
//   int next;
//   bool flag;
// }node[100000];
// int main() {
//   int s1, s2, n, a, b;
//   scanf("%d%d%d", &s1, &s2, &n);
//   char data;
//   for(int i = 0; i < n; i++) {
//     scanf("%d %c %d", &a, &data, &b);
//     node[a] = {data, b, false};
//   }
//   for(int i = s1; i != -1; i = node[i].next)
//     node[i].flag = true;
//   for(int i = s2; i != -1; i = node[i].next) {
//     if(node[i].flag == true) {
//         printf("%05d", i);
//         return 0;
//     }
//   }
//   printf("-1");
//   return 0;
// }

int Next[100010], n, a, b, la = 0, lb = 0, Ra[100010], Rb[100010];
void getlen(int first, int &len, int R[]){
  while(first != -1){
    R[len++] = first;
    first = Next[first];
  }
  R[len] = -1;
}
int main() {
  char data[100010];
  scanf("%d %d %d", &a, &b, &n);
  for(int i = 0; i < n; i++){
    int temp;
    scanf("%d ", &temp);
    scanf("%c %d", &data[temp], &Next[temp]);
  }
  getlen(a, la, Ra);
  getlen(b, lb, Rb);
  int ka = la > lb ? (la - lb) : 0;
  int kb = lb > la ? (lb - la) : 0;
  for(int i = 0; i <= min(la, lb); i++){
    if(Ra[i + ka] == Rb[i + kb]){
      if(Ra[i + ka] == -1) printf("-1\n");
      else printf("%05d\n", Ra[i + ka]);
      break;
    }
  }
  return 0;
}
