#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
using namespace std;
//A1113 Integer Set Partition
int main() {
  int n, d[100010], sum1 = 0, sum2 = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &d[i]);
  }
  sort(d, d + n);
  if(n % 2 == 0) printf("0 ");
  else printf("1 ");
  for(int i = 0; i < n; i++){
    if(i < n / 2) sum1 += d[i];
    else sum2 += d[i];
  }
  printf("%d", sum2 - sum1);
  return 0;
}
