#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
//A1147 Heaps
int m, n, lev[1010], cnt;
void postorder(int root){
  if(root > n) return;
  postorder(2 * root);
  postorder(2 * root + 1);
  if(cnt != 0) printf(" ");
  printf("%d", lev[root]);
  cnt++;
}
int main() {
  scanf("%d%d", &m, &n);
  for(int i = 0; i < m; i++){
    bool maxheap = true, minheap = true;
    for(int j = 1; j <= n; j++){
      scanf("%d", &lev[j]);
    }
    for(int j = 1; 2 * j <= n; j++){
      if(lev[j] < lev[2 * j]) maxheap = false;
      else if(lev[j] > lev[2 * j]) minheap = false;
      if(2 * j + 1 <= n && lev[j] < lev[2 * j + 1]) maxheap = false;
      else if(2 * j + 1 <= n && lev[j] > lev[2 * j + 1]) minheap = false;
    }
    if(maxheap == true) printf("Max Heap\n");
    else if(minheap == true) printf("Min Heap\n");
    else if(maxheap == false && minheap == false) printf("Not Heap\n");
    cnt = 0;
    postorder(1);
    printf("\n");
  }
  return 0;
}
