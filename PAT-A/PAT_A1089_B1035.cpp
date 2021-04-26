#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cstdio>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
//A1089_B1035 插入与归并
const int maxn = 100010;
int n, num[maxn], sort1[maxn], sort2[maxn], check[maxn];
bool issame(int *a, int *b){
  for(int i = 0; i < n; i++){
    if(a[i] != b[i]) return false;
  }
  return true;
}
void showans(int *a){
  printf("%d", a[0]);
  for(int i = 1; i < n; i++) printf(" %d", a[i]);
}
bool insertsort(){
  bool flag = false;
  for(int i = 1; i < n; i++){
    int j = i;
    if(i != 1 && issame(check, sort1)) {
      flag = true;
    }
    while(j > 0 && num[i] < sort1[j - 1]){
      sort1[j] = sort1[j - 1];
      j--;
    }
    sort1[j] = num[i];
    if(flag) {
      printf("Insertion Sort\n");
      showans(sort1);
      return true;
    }
  }
    return false;
}
void mergesort(){
  for(int step = 2; step / 2 < n; step *= 2){
    bool flag = false;
    if(step != 2 && issame(sort2, check)){
      printf("Merge Sort\n");
      flag = true;
    }
    for(int i = 0; i < n; i+=step){
      sort(sort2 + i, sort2 + min(i + step, n));
    }
    if(flag && step != 2){
      showans(sort2);return;
    }
  }
}
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
      scanf("%d", &num[i]);
      sort1[i] = num[i];
      sort2[i] = num[i];
    }
    for(int i = 0; i < n; i++){
      scanf("%d", &check[i]);
    }
    // 可以直接判定结果是不是 插入排序
    // 如果是插入排序，前面排好的一定是有序的，后面的都没有变动
    // for (i = 0; i < n - 1 && b[i] <= b[i + 1]; i++);
    // for (j = i + 1; a[j] == b[j] && j < n; j++);
    // if (j == n) {
    //     cout << "Insertion Sort" << endl;
    //     sort(a, a + i + 2);
    // }
    if(!insertsort()){
      mergesort();
    }
    return 0;
}
