#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
//A1117_B1060	Eddington Number 爱丁顿数
int n, d[100010], cnt = 0;
bool cmp(int a, int b){ return a > b; }
int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &d[i]);
  }
  sort(d, d + n, cmp);
  while(cnt < n && d[cnt] > cnt + 1) cnt++;
  printf("%d\n", cnt);
  return 0;
}
