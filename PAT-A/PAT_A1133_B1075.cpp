#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
//A1133_B1075 Splitting A Linked List链表元素分类
int main() {
  int A[100010], D[100010], n, k, pos, now, next, temp;
  vector<int> first, second, last;
  scanf("%d %d %d", &pos, &n, &k);
  for(int i = 0; i < n; i++){
    scanf("%d %d %d",&now, &temp, &next);
    A[now] = next;
    D[now] = temp;
  }
  while(pos != -1){
    if(D[pos] < 0) first.push_back(pos);
    else if(D[pos] > k) last.push_back(pos);
    else second.push_back(pos);
    pos = A[pos];
  }
  for(int i = 0; i < second.size(); i++) first.push_back(second[i]);
  for(int i = 0; i < last.size(); i++) first.push_back(last[i]);
  for(int i = 0; i < first.size(); i++){
    if(i == first.size() - 1) printf("%05d %d -1", first[i], D[first[i]]);
    else printf("%05d %d %05d\n", first[i], D[first[i]], first[i + 1]);
  }
  return 0;
}
