#include <cstdio>
int main(){
  int ans, P, A, p1, p2, p3, a1, a2, a3;
  scanf("%d.%d.%d %d.%d.%d", &p1, &p2, &p3, &a1, &a2, &a3);
  P = p1 * 17 * 29 + p2 * 29 + p3;
  A = a1 * 17 * 29 + a2 * 29 + a3;
  ans = A - P;
  if(ans < 0){
    printf("-");
    ans = -ans;
  }
  printf("%d.%d.%d\n", ans/17/29, ans/29%17, ans%29);
  return 0;
}
