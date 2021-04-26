#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//A1052 Linked List Sorting
struct Node{
  int address;
  int key;
  int next;
  int order;
}node[100010];
bool cmp1(Node a, Node b){
   return a.order < b.order;
}
bool cmp2(Node a, Node b){
  return a.key < b.key;
}
int main() {
  int k, n, cnt = 0;
  scanf("%d %d", &n, &k);
  for(int i = 0; i < n; i++){
    int temp, key, next;
    scanf("%d%d%d", &temp, &key, &next);
    node[temp] = { temp, key, next, 10};
    node[temp].address = temp;
  }
  while(k != -1){
    node[k].order = -1;
    k = node[k].next;
    cnt++;
  }
  sort(node, node + 100010, cmp1);
  sort(node, node + cnt, cmp2);
  node[cnt].address = -1;
  printf("%d \n", cnt);
  if(node[0].address == -1) printf("-1\n");
  else printf("%05d\n", node[0].address);
  for(int i = 0; i < cnt; i++){
    printf("%05d %d ", node[i].address, node[i].key);
    if(i == cnt - 1) printf("-1\n");
    else printf("%05d\n", node[i + 1].address);
  }
  return 0;
}
