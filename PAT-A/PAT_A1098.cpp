#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;
//A1098 Insertion or Heap Sort
int n, origin[105], partsort[105];
void adjust(int low, int high){
  int i = low, j = i * 2;
  while(j <= high){
    if(j + 1 <= high && partsort[j] < partsort[j + 1]) j = j+1;
    if(partsort[j] > partsort[i]){
      swap(partsort[j], partsort[i]);
      i = j;
      j = i * 2;
    }else break;
  }
}
int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    scanf("%d", &origin[i]);
  }
  for(int i = 1; i <= n; i++){
    scanf("%d", &partsort[i]);
  }
  int k = 1;//查看序列规律
  while(k < n && partsort[k + 1] >= partsort[k]) k++;
  int index = k++;
  while(k <= n && partsort[k] == origin[k]) k++;
  if(k == n + 1){ // insertionsort();
    printf("Insertion Sort\n");
    sort(partsort + 1, partsort + index + 2);
  }else{ // heapsort();
    printf("Heap Sort\n");
    int k = n;
    while(k > 1 && partsort[k] >= partsort[k - 1]) k--;
    swap(partsort[1], partsort[k]);
    adjust(1, k - 1);
  }
  for(int i = 1; i <= n; i++){
    if(i != 1) printf(" ");
    printf("%d", partsort[i]);
  }
  return 0;
}
