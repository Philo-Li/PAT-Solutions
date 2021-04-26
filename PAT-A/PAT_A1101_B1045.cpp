#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cstdio>
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
//A1101_B1045 Quick sort
const int maxn = 100010;
int n;
int s[maxn];
int min_element(int i, int j){
  int minimun = s[i];
  for(int k = i; k < j; k++){
    if(minimun > s[k]) minimun = s[k];
  }
  return minimun;
}
int max_element(int i, int j){
  int maximun = s[i];
  for(int k = i; k < j; k++){
    if(maximun < s[k]) maximun = s[k];
  }
  return maximun;
}
int main() {
    int left_max[maxn], right_min[maxn];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
      scanf("%d", &s[i]);
      if(i == 0) left_max[i] = s[i];
      else left_max[i] = max(left_max[i - 1], s[i]);
    }
    for(int i = n - 1; i >= 0; i--){
      if(i == n - 1) right_min[i] = s[i];
      else right_min[i] = min(right_min[i + 1], s[i]);
    }
    int ans[maxn], cnt = 0;
    for(int i = 0; i < n; i++){
      if(s[i] <= right_min[i] && s[i] >= left_max[i]) {
        ans[cnt++] = s[i];
      }
    }
    sort(ans, ans + cnt);
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++){
      if(i != 0) printf(" ");
      printf("%d", ans[i]);
    }
    if(cnt == 0) printf("\n");
    return 0;
}
//对原序列sort排序，逐个比较，当当前元素没有变化
//并且它左边的所有值的最大值都比它小的时候
//就可以认为它一定是主元，它的排名【当前数在序列
//中处在第几个】一定不会变）
// #include <iostream>
// #include <algorithm>
// #include <vector>
// int a[100000], b[100000];
// using namespace std;
// int main() {
//     int n;
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &a[i]);
//         b[i] = a[i];
//     }
//     sort(a, a + n);
//     int v[100000], max = 0, cnt = 0;
//     for (int i = 0; i < n; i++) {
//         if(a[i] == b[i] && b[i] > max)
//             v[cnt++] = b[i];
//         if (b[i] > max)
//             max = b[i];
//     }
//     printf("%d\n", cnt);
//     for(int i = 0; i < cnt; i++) {
//         if (i != 0) printf(" ");
//         printf("%d", v[i]);
//     }
//     printf("\n");
//     return 0;
// }
