#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//A1097 Deduplication on a Linked List
struct Node{
  int address;
  int key;
  int next;
}node[100010], removed[100010], result[100010];
void print(Node R[], int sumn){
  for(int i = 0; i < sumn; i++){
    printf("%05d %d ", R[i].address, R[i].key);
    if(i == sumn - 1) printf("-1\n");
    else printf("%05d\n", R[i + 1].address);
  }
}
bool hashtable[1001] = {false};
int main() {
  int k, n;
  scanf("%d %d", &k, &n);
  for(int i = 0; i < n; i++){
    int temp, key, next;
    scanf("%d%d%d", &temp, &key, &next);
    node[temp] = { temp, key, next};
  }
  int sumr = 0, sumn = 0;
  while(k != -1){
    int temp = node[k].key;
    if(hashtable[abs(temp)] == false)
    {
      result[sumn].address = k;
      result[sumn].key = temp;
      hashtable[abs(temp)] = true;
      sumn++;
    }
    else{
      removed[sumr].address = k;
      removed[sumr].key = temp;
      sumr++;
    }
    k = node[k].next;
  }
  result[sumn].address = -1;
  removed[sumr].address = -1;
  print(result, sumn);
  print(removed, sumr);
  return 0;
}
// const int maxn = 100000;
// struct NODE {
//     int address, key, next, num = 2 * maxn;
// }node[maxn];
// bool exist[maxn];
// int cmp1(NODE a, NODE b){
//     return a.num < b.num;
// }
// int main() {
//     int begin, n, cnt1 = 0, cnt2 = 0, a;
//     scanf("%d%d", &begin, &n);
//     for(int i = 0; i < n; i++) {
//         scanf("%d", &a);
//         scanf("%d%d", &node[a].key, &node[a].next);
//         node[a].address = a;
//     }
//     for(int i = begin; i != -1; i = node[i].next) {
//         if(exist[abs(node[i].key)] == false) {
//             exist[abs(node[i].key)] = true;
//             node[i].num = cnt1;
//             cnt1++;
//         }
//         else {
//             node[i].num = maxn + cnt2;
//             cnt2++;
//         }
//     }
//     sort(node, node + maxn, cmp1);
//     int cnt = cnt1 + cnt2;
//     for(int i = 0; i < cnt; i++) {
//         if(i != cnt1 - 1 && i != cnt - 1) {
//             printf("%05d %d %05d\n", node[i].address, node[i].key, node[i+1].address);
//         } else {
//             printf("%05d %d -1\n", node[i].address, node[i].key);
//         }
//     }
//     return 0;
// }
