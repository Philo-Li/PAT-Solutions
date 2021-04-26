#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cctype>
#include <queue>
#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>
using namespace std;
//A1064 Complete Binary Search Tree
int n, k;
int cbt[1005], temp[1005], cnt = 0;
void inorder(int root){
  if(root > n) return;
  inorder(2 * root);
  // printf("root = %d\n", root);
  cbt[root] = temp[cnt++];
  inorder(2 * root + 1);
}
int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &temp[i]);
  }
  sort(temp, temp + n);
  inorder(1);
  for(int i = 1; i <= n; i++){
    if(i != 1) printf(" ");
    printf("%d", cbt[i]);
  }
  return 0;
}
